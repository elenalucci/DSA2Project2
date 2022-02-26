//Elena Lucci Project2
#ifndef FIFO_HPP
#define FIFO_HPP
#include "Customer.hpp"

class FIFO{
	private:
		int size;
		bool empty;
		Customer* top;	
	public:
		FIFO();
		void Insert(Customer* cust);
		Customer* GetTop();
		bool isEmpty();
	

};
#endif
