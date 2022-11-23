#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "trigrams.h"
void trigrams() {
	std::string line;
	std::string rawText;
	std::string filename = "words";

	std::ifstream file(filename);
	
	if(file.is_open()) {
		while(getline(file,line)) {
				for(std::string s : makeTrigrams(line)) {
					rawText.append(" " + s + " ");
				}
				rawText.append("\n");
			}
			file.close();
	}
	std::ofstream outfile ("words2.txt");
	outfile << rawText << std::endl;
	outfile.close();
}


std::vector<std::string> makeTrigrams(std::string& line) {
	std::string temp = "";
	std::vector<std::string> arr = {};
	int count = 0;
	if(line.length() > 3) {
		for(char& c : line) {
			if(temp.length() == 3) {
				arr.push_back(temp);
				temp.erase(0,1);
				count++;
			}
			temp += std::tolower(c, std::locale());
		}
		sort(arr.begin(), arr.end());
		arr.insert(arr.begin(), std::to_string(count));
		arr.insert(arr.begin(),line);
	} else if(line.length() == 3) {
		arr.push_back(line);
		arr.push_back("1");
		arr.push_back(line);
	}
	return arr;

}

int main() {
	trigrams();

}
