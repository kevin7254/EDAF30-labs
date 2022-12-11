#include <iostream>
#include <string>
#include <cassert>
#include "tagremover.h"
#include "sieve.h"

bool test_tags(std::ifstream& infile, std::ostream& outfile)
{
	if(infile.is_open()){
	TagRemover TagRemover(infile);
	TagRemover.print(outfile);

	}
	return false;

}


int main()
{
	std::ifstream file("test.html");
	std::ofstream out("no_tags.html");

	if(test_tags(file, out)){
		std::cout << "Test passed" << std::endl;
	}else{
		std::cout << "Test failed" << std::endl;
	}



	return 0;
}








