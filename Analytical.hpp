//Elena Lucci Project 2 
#ifndef Analytical_hpp
#define Analytical_hpp

class Analytical{
	private:
		int n;
		double lambda;
		double mu;
		int M;
		double Po;
		double L;
		double W;
		double Lq;
		double Wq;
		double rho;
	public:
		Analytical();
		void SetN(int n);
		void SetLambda(double lambda);
		void SetMu(double mu);
		void SetM(int M);
		double CalculatePo();
		double CalculateL();
		double CalculateW();
		double CalculateLq();
		double CalculateWq();
		double CalculateRho();
};

#endif
