//ELena Lucci Projcet 2
#include "Simulation.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
//Default constructor
Simulation::Simulation(){
	
	simTime = 0;
	totalServiceAvail = 0;
	serviceAvail = totalServiceAvail;
	numCust = 0;
	customerWaitedCnt = 0;
	totalWaitTime = 0;
	currentWaitTime = 0;
	serviceTime = 0;
	idleTime = 0;
	interval=0;
	empty = false;
	lambda = 0;
	mu = 0;
	cust = nullptr;
	
}
//Runs the simulation
void Simulation::RunSimulation(){
	
	float addTime = 0;
	int i=0;

	while(i<200){
		//std::cout << "cust #" << i+1 << std::endl;		
		
		Customer * newCust = new Customer();
		interval = GetNextRandomInterval(lambda);
		//std::cout << interval << std::endl;
		
		addTime += interval;
		//std::cout << addTime << std::endl;
		
		newCust->SetArrivalTime(addTime);
		newCust->SetPQTime(addTime);

		pq.Insert(newCust, newCust->GetPQTime());
		i++;
	}
	simTime = addTime;
	numCust -= 200;

	while(pq.isEmpty() == false){
		//std::cout<< "run simulation" << std::endl;
		ProcessNextEvent();
		if(numCust >0 && pq.GetNumCust() <= serviceAvail + 1){
			addTime = simTime;
			for(int i = pq.GetNumCust(); i <200; i++){
				Customer * newCust = new Customer();
				interval = GetNextRandomInterval(lambda);
				addTime += interval;
				newCust->SetArrivalTime(addTime);
				newCust->SetPQTime(addTime);

				pq.Insert(newCust, newCust->GetPQTime());
			}
		}	
	
	}

}
//sets the service available count
void Simulation::SetTotalServiceAvail(int totalServiceAvail){

	this->totalServiceAvail = totalServiceAvail;
	serviceAvail = totalServiceAvail;
}
//sets number of customers 
void Simulation::SetNumCust(int numCust){
	
	this->numCust = numCust;
}
//sets lambda
void Simulation::SetLambda(double lambda){

	this->lambda = lambda;
}
//sets Mu
void Simulation::SetMu(double mu){

	this->mu = mu;
}
//generates random interval, sends in lambda for avg for arrivals, mu for departures
float Simulation::GetNextRandomInterval(double avg){
	
	float randNum = 0;

	randNum = (rand() % 100);
	
	randNum /= 100;
	if(randNum <=0){
		randNum += 0.5;
	}
	//std::cout<< randNum<< std::endl;
	interval = -1 * (1.0/avg) * (log(randNum));
	//std::cout << interval << std::endl;
	interval = floor(interval*100)/100;
	//std::cout << interval << std::endl;
	return interval;
	
}
//Processes arrival and departure times and sends to FIFO queue
void Simulation::ProcessNextEvent(){
	cust = pq.GetTop();
	//std::cout << "Process next event" << std::endl;
	//std::cout << cust->GetDepartureTime() << std::endl;
	if(cust->GetDepartureTime() <0){	
		if(serviceAvail >0){
			//std::cout<< "arrival event" << std::endl;
			serviceAvail--;
			cust->SetSOSTime(cust->GetArrivalTime());
			interval = GetNextRandomInterval(mu);
			cust->SetDepartureTime(cust->GetArrivalTime() + interval);
			cust->SetPQTime(cust->GetDepartureTime());
			pq.Insert(cust, cust->GetPQTime());

		}
		else{
			fifo.Insert(cust);
			//std::cout << "added to fifo" << std::endl;
		}	
	}
	else{
		serviceAvail++;
		ProcessStatistics(cust);
		simTime = cust->GetDepartureTime();	
		//std::cout << "departure event" << std::endl;
		//std::cout << "simTime = " << simTime << std::endl;	
		if(fifo.GetTop() != nullptr){
			Customer* temp = new Customer();
			temp = fifo.GetTop();
			temp->SetSOSTime(cust->GetDepartureTime());
			interval = GetNextRandomInterval(mu);
			temp->SetDepartureTime(temp->GetSOSTime() + interval);
			temp->SetPQTime(temp->GetDepartureTime());
			pq.Insert(temp, temp->GetPQTime());
			serviceAvail--;
		}

	}

}
//processes some statistics based on the customer pointer object sent to it
void Simulation::ProcessStatistics(Customer* customer){
	//float inSystem;
	float tempIdle;
	//std::cout << "process statistics" << std::endl;
	currentWaitTime = customer->GetSOSTime() - customer->GetArrivalTime();

	if(currentWaitTime>0){
		customerWaitedCnt++;
	}

	totalWaitTime += currentWaitTime;
	serviceTime = customer->GetDepartureTime() - customer->GetSOSTime();
	//inSystem = cust->GetDepartureTime() - cust->GetArrivalTime();
	tempIdle = customer->GetNextCust()->GetSOSTime() - customer->GetDepartureTime();
	
	if(serviceAvail == totalServiceAvail){
		idleTime += tempIdle;		
	}

}
