//Elena Lucci Project2
#include "FIFO.hpp"
//Default Constructor
FIFO::FIFO(){
	top = nullptr;
	size = 0;
	empty = false;
}
//Inserts Customer at the back of queue
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
//returns the top pointer value
Customer* FIFO::GetTop(){
	
	Customer* temp = new Customer();
	temp = top;

	top = top->GetNextCust();
	
	size--;

	return temp;
	delete temp;
	
}
//returns whether teh fifo is empty or not
bool FIFO::isEmpty(){
	
	if(size < 1){
		empty = true;
	}
	
	return empty;
}
