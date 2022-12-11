#ifndef SIEVE_H
#define SIEVE_H

#include <string>
#include <vector>

class Sieve{
	public:	
		Sieve(int nbrs);
		int highestPrime();	
		void print();


	private:
		std::string text;
		std::vector<int> primes;

};

#endif
