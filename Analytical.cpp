#include "Analytical.hpp"
#include <iostream>
#include <cmath>
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

void Analytical::SetN(int n){
	this->n = n;
}

void Analytical::SetLambda(double lambda){
	this->lambda = lambda;
}

void Analytical::SetMu(double mu){
	this->mu = mu;
}

void Analytical::SetM(int M){
	this->M = M;
}

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

double Analytical::CalculateL(){
	
	long double mFac = 1.0;
	
	for(int i=1; i<= M-1; i++){
		mFac *= i;
	}

	L = ((lambda*mu * (pow((lambda/mu),M)) / ((mFac)* (pow(((M*mu)-lambda),2)))));
	L = L* Po + (lambda/mu);

	return L;
}

double Analytical::CalculateW(){
	
	W = L/lambda;

	return W;
}

double Analytical::CalculateLq(){
	
	Lq = L - (lambda/mu);	

	return Lq;
}

double Analytical::CalculateWq(){

	Wq = Lq / lambda;

	return Wq;
}

double Analytical::CalculateRho(){

	rho = lambda / (M*mu);

	return rho;
}

