//Elena Lucci Project2
#ifndef Customer_hpp
#define Customer_hpp

class Customer{
	private:
		float arrivalTime;
		float startOfServiceTime;
		float departureTime;
		float PQTime;
		Customer* nextCust;
	
	public:
		Customer();
		~Customer();
		void SetArrivalTime(float arrivalTime);
		void SetSOSTime(float startOfServiceTime);
		void SetDepartureTime(float departureTime);
		void SetNextCust(Customer* nextCust);
		void SetPQTime(float PQTime);
		float GetArrivalTime();
		float GetSOSTime();
		float GetDepartureTime();
		float GetPQTime();
		Customer* GetNextCust();
	   		

};

#endif
