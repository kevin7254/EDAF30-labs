#include <iostream>
#include "coding.h"
#include <fstream>

void decodeFile() {
	std::string line;
	std::cout << "enter encoded filename\n";

	std::string input;

	std::cin >> input;

	std::ifstream file(input);

	std::string rawText;

	if(file.is_open()) {
		while(getline(file, line)) {
			for(char& c : line) {
				c--;
			}
			rawText.append(line + "\n");
		}
		file.close();
	}

	std::string filename;
	std::string filetype = ".dec";
        filename = input + filetype;
	std::ofstream outfile (filename);

	outfile << rawText << std::endl;

	outfile.close();
}
