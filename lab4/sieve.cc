#include "sieve.h"
#include <string>
#include <vector>
#include <iostream>

int main(){
	Sieve s(200);
	std::cout << s.highestPrime() << std::endl;
	s.print();


	Sieve s2(100000);
	std::cout << s2.highestPrime() << std::endl;
return 0;

}

Sieve::Sieve(int nbrs){
	text.assign(nbrs+1, 'P');
	text[0] = 'C';
	text[1] = 'C';
	int starters[5] = {2, 3, 5, 7, 11};
	for(auto i : starters){
		int increment=i*2;
		while(increment <= nbrs){
			if(text[increment] == 'P'){
				text[increment] = 'C';
			}
			increment += i;
		}

	}
}

int Sieve::highestPrime(){
	return text.rfind('P');
	
}

void Sieve::print(){
	for(int i=0; i<text.length(); ++i){
		if(text[i] == 'P'){
		primes.push_back(i);
		}
	}
	for(auto k : primes){
		std::cout << k << " ";
	}
	
}
