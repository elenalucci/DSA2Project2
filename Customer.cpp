//Elena Lucci Project2
#include "Customer.hpp"
#include <iostream>
//Default Constructor
Customer::Customer(){
	arrivalTime = 0;
	startOfServiceTime = -1.0;
	departureTime = -1.0;
	PQTime = 0;
	nextCust = NULL;	
}
//Destructor
Customer::~Customer(){
	
	delete nextCust;	
}
//Sets the arrival time
void Customer::SetArrivalTime(float arrivalTime){

	this->arrivalTime = arrivalTime;

}
//Sets start of service time
void Customer::SetSOSTime(float startOfServiceTime){

	this->startOfServiceTime = startOfServiceTime;

}
//sets departure time
void Customer::SetDepartureTime(float departureTime){

	this->departureTime = departureTime;

}
//sets next customer pointer
void Customer::SetNextCust(Customer* nextCust){

	this->nextCust = nextCust;
	
}
// sets PQtime which is what the priority queue will sort by
void Customer::SetPQTime(float PQTime){

	this->PQTime = PQTime;
}
//Returns arrival time
float Customer::GetArrivalTime(){

	return arrivalTime;
}
//returns start of service time
float Customer::GetSOSTime(){

	return startOfServiceTime;
}
// returns departure time
float Customer::GetDepartureTime(){

	return departureTime;
}
// returns pq time
float Customer::GetPQTime(){
	
	return PQTime;
}
// returns next customer pointer
Customer* Customer::GetNextCust(){

	return nextCust;
}


