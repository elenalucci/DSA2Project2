//Elena Lucci Project 2
#include "Analytical.hpp"
#include <iostream>
#include <cmath>
//Default Constructor
Analytical::Analytical(){
	n = 0;
	lambda = 0.0;
	mu = 0.0;
	M = 0;
	Po = 0.0;
	L = 0.0;
	W = 0.0;
	Lq = 0.0;
	Wq = 0.0;
	rho = 0.0;
}
//Sets number of customers
void Analytical::SetN(int n){
	this->n = n;
}
//Sets lambda
void Analytical::SetLambda(double lambda){
	this->lambda = lambda;
}
//Sets Mu
void Analytical::SetMu(double mu){
	this->mu = mu;
}
//Sets M
void Analytical::SetM(int M){
	this->M = M;
}
//Calculates percent idle time
double Analytical::CalculatePo(){
	
	long double E = 0.0;
	long double iFac;
	long double mFac = 1.0;
	

	for(int i=0; i < M; i++){
			
		iFac = 1.0;
		for(int j=1; j < i; j++){
			iFac *= j;
		} 
		
		E += (1/iFac)*(pow((lambda/mu),i));
				
	}

	for(int i=1; i<=M; i++){
		mFac *= i;
	}	

	Po = ((1) / ((E) + ((1/mFac)* (pow((lambda/mu),M)) * ((M*mu)/((M*mu)- lambda)))));

	return Po;
}
//Calculates average number of people in the system
double Analytical::CalculateL(){
	
	long double mFac = 1.0;
	
	for(int i=1; i<= M-1; i++){
		mFac *= i;
	}

	L = ((lambda*mu * (pow((lambda/mu),M)) / ((mFac)* (pow(((M*mu)-lambda),2)))));
	L = L* Po + (lambda/mu);

	return L;
}
//Calculates average time a customer spends in the system
double Analytical::CalculateW(){
	
	W = L/lambda;

	return W;
}
//calculates average numbers of customers in the queue
double Analytical::CalculateLq(){
	
	Lq = L - (lambda/mu);	

	return Lq;
}
//Calculates average time a customer spends waiting in queue
double Analytical::CalculateWq(){

	Wq = Lq / lambda;

	return Wq;
}
//Calculates utilization factor
double Analytical::CalculateRho(){

	rho = lambda / (M*mu);

	return rho;
}

