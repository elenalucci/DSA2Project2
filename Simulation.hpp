//Elena Lucci Project2
#ifndef Simulation_hpp
#define Simulation_hpp
#include "Customer.hpp"
#include "PriorityQ.hpp"
#include "FIFO.hpp"

class Simulation{
	private:
		float simTime;
		int totalServiceAvail;
		int serviceAvail;
		int numCust;
		int customerWaitedCnt;
		float totalWaitTime;
		float currentWaitTime;
		float serviceTime;
		float idleTime;
		float interval;
		bool empty;
		double lambda;
		double mu;
		Customer* cust;
		PriorityQ pq;
		FIFO fifo;

	public:
		Simulation();
		void RunSimulation();
		void SetTotalServiceAvail(int totalServiceAvail);
		void SetNumCust(int numCust);
		void SetLambda(double lambda);
		void SetMu(double mu);
		float GetNextRandomInterval(double avg);
		void ProcessStatistics(Customer* customer);
		void ProcessNextEvent();

};

#endif
