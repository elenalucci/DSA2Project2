#include "PriorityQ.hpp"

PriorityQ::PriorityQ(){

	top = nullptr;
	numCust = 0;	
	empty = false;
}


void PriorityQ::Insert(Customer* cust,float PQTime){
	
	if(top == nullptr){
		top = cust;
		return;
	}

	Customer* temp = new Customer();

	temp = top;

	while(temp->GetNextCust() != nullptr){
		if(temp->GetNextCust()->GetPQTime() > PQTime){
			temp = temp->GetNextCust();
		}
		else{
			
			cust->SetNextCust(temp->GetNextCust());
			temp->SetNextCust(cust);
			break;
		}
		
	}
	
	numCust++;	

	delete temp;
	
}

Customer* PriorityQ::GetTop(){

	Customer* temp = new Customer();
	temp = top;

	top = top->GetNextCust();
	
	numCust--;

	return temp;
	
	delete temp;
}

bool PriorityQ::isEmpty(){

		if(numCust < 1){
			empty = true;
		}

		return empty;
}

