#include <iostream>
#include <iomanip>
#include "Analytical.hpp"

int main(){
	
	int n;
	double lambda;
	double mu;
	int M;
	Analytical a;	

	std::cout << "Enter number of arrivals: ";
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "Enter lambda: ";
	std::cin >> lambda;
	std::cout << std::endl;
	std::cout << "Enter mu: ";
	std::cin >> mu;
	std::cout << std::endl;
	std::cout << "Enter number of service channels: ";
	std::cin >> M;

	a.SetN(n);
	a.SetLambda(lambda);
	a.SetMu(mu);
	a.SetM(M);	 
	
	std::cout << "Analytical Model: " << std::endl;
	std::cout << "Po = " <<  a.CalculatePo() << std::endl;
	std::cout << "L = " << a.CalculateL() << std::endl;
	std::cout << "W = " << a.CalculateW() << std::endl;
	std::cout << "Lq = " << std::setprecision(2) << a.CalculateLq() << std::endl;
	std::cout << "Wq = " << std::setprecision(3) << a.CalculateWq() << std::endl;	
	std::cout << "Rho = " << a.CalculateRho() << std::endl;	
	
	return 0;
}
