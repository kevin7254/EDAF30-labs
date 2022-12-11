#ifndef SIEVE_H
#define SIEVE_H

#include <string>
#include <vector>

class Sieve{
	public:	
		Sieve(int nbrs);
		int highestPrime();	
		void print();
		void test();

	private:
		std::string text;
		std::vector<int> primes;
		std::string answer ="CCPPCPCPCCCPCPCCCPCPCCCPCCCCCPCPCCCC";
};

#endif
