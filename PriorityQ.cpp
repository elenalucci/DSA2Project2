//Elena Lucci Project2
#include "PriorityQ.hpp"
#include <iostream>
//Default Constructor
PriorityQ::PriorityQ(){

	top = nullptr;
	numCust = 0;	
	empty = false;
}

//inserts customer pointer into priority queue sorting by PQtime
void PriorityQ::Insert(Customer* cust,float PQTime){
	//std::cout << "inserting" << std::endl;	
	if(top == nullptr){
		//std::cout<< "setting top" << std::endl;
		top = cust;
		return;
	}

	Customer* temp = new Customer();

	temp = top;
	
	while(temp->GetNextCust() != nullptr){
	//	std::cout << "while loop" << std::endl;
	//	std::cout << temp->GetPQTime() << std::endl;
		
		if(temp->GetNextCust()->GetPQTime() < PQTime){
			temp = temp->GetNextCust();
		}
		else if(temp->GetNextCust()->GetPQTime() >= PQTime){
			break;
		}
		
	
	}

	cust->SetNextCust(temp->GetNextCust());
	temp->SetNextCust(cust);
	
	numCust++;	

	
}
//Removes and returns the top pointer and sets top to the next value
Customer* PriorityQ::GetTop(){

	Customer* temp = new Customer();
	temp = top;

	top = top->GetNextCust();

	numCust--;


	return temp;
	
}
//returns number of customers in the queue
int PriorityQ::GetNumCust(){

	return numCust;
}
//returns whether the queue is empty or not
bool PriorityQ::isEmpty(){

		if(numCust < 1){
			empty = true;
		}

		return empty;
}

