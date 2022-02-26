//Elena Lucci Project2
#ifndef PriorityQ_hpp
#define PriorityQ_hpp
#include "Customer.hpp"

class PriorityQ{
	private:
		Customer* top;
		const int totalNumCust = 200;
		int numCust;
		bool empty;
		
	public:
		PriorityQ();
		void Insert(Customer* cust,float PQTime);
		Customer* GetTop();
		int GetNumCust();
		bool isEmpty();
};
#endif
