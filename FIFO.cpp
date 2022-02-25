#include "FIFO.hpp"

FIFO::FIFO(){
	top = nullptr;
	size = 0;
	empty = false;
}

void FIFO::Insert(Customer* cust){
	
	if(top == nullptr){
		top = cust;
	}

	Customer* temp = new Customer();
	temp = top;	
	
	while(temp->GetNextCust() != nullptr){
		temp = temp->GetNextCust();
	}
	
	temp->SetNextCust(cust);

	size++;

	delete temp;

}

Customer* FIFO::GetTop(){
	
	Customer* temp = new Customer();
	temp = top;

	top = top->GetNextCust();
	
	size--;

	return temp;
	delete temp;
	
}

bool FIFO::isEmpty(){
	
	if(size < 1){
		empty = true;
	}
	
	return empty;
}
