#ifndef Customer_hpp
#define Customer_hpp

class Customer{
	private:
		float arrivalTime;
		float startOfServiceTime;
		float departureTime;
		Customer* nextCust;
	
	public:
		Customer();
		~Customer();
		void SetArrivalTime(float arrivalTime);
		void SetSOSTime(float startOfServiceTime);
		void SetDepartureTime(float departureTime);
		void SetNextCust(Customer* nextCust);
		float GetArrivalTime();
		float GetSOSTime();
		float GetDepartureTime();
		Customer* GetNextCust(); 

};

#endif
