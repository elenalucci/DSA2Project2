#include "Customer.hpp"
#include <iostream>
Customer::Customer(){
	arrivalTime = -1.0;
	startOfServiceTime = -1.0;
	departureTime = -1.0;
	PQTime = 0;
	nextCust = NULL;	
}

Customer::~Customer(){
	
	delete nextCust;	
}

void Customer::SetArrivalTime(float arrivalTime){

	this->arrivalTime = arrivalTime;

}

void Customer::SetSOSTime(float startOfServiceTime){

	this->startOfServiceTime = startOfServiceTime;

}

void Customer::SetDepartureTime(float departureTime){

	this->departureTime = departureTime;

}

void Customer::SetNextCust(Customer* nextCust){

	this->nextCust = nextCust;
	
}

void Customer::SetPQTime(float PQTime){

	this->PQTime = PQTime;
}

float Customer::GetArrivalTime(){

	return arrivalTime;
}

float Customer::GetSOSTime(){

	return startOfServiceTime;
}

float Customer::GetDepartureTime(){

	return departureTime;
}

float Customer::GetPQTime(){
	
	return PQTime;
}

Customer* Customer::GetNextCust(){

	return nextCust;
}


