#include <iostream>
#include <iomanip>
#include "Analytical.hpp"
#include "Simulation.hpp"

int main(){
	
	int n;
	double lambda;
	double mu;
	int M;
	Analytical a;	
	Simulation s;

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

	s.SetTotalServiceAvail(M);
	s.SetNumCust(n);
	s.SetLambda(lambda);
	s.SetMu(mu);
	s.RunSimulation();
	

	std::cout << "Simulation: " << std::endl;
	std::cout << "Po = " << std::endl;
	std::cout << "W = " << std::endl;
	std::cout << "Wq = " << std::endl;
	std::cout << "Rho = " << std::endl;
	return 0;
}
