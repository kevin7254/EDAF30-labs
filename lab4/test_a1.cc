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

	//test
	std::ifstream infile_notags("no_tags.html");
	std::string text;
	std::string line;
	while(getline (infile_notags, line)){
		text.append(line);
		text.append("\n");
	}
	std::string sub = text.substr(0, text.rfind("<"));
	assert(sub.find(">") == std::string::npos);
	assert(sub.find("<") == std::string::npos);
	std::string sub2 = text.substr(text.rfind("<"), 4);
	assert(sub2.compare("<> &") ==0);

	}
	return true;

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








