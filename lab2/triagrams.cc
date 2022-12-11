#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
std::vector<string> makeTrigrams(string&);

void read(){
ifstream readfile("words.txt");
string newText;
string tempLine;

if(readfile.is_open()){
	while(getline(readfile, tempLine)){
	transform(tempLine.begin(), tempLine.end(), tempLine.begin(), ::tolower);
	newText.append(tempLine);
	vector<string> tempp = makeTrigrams(tempLine);
	for(string s : tempp){
	newText.append(" " +s);
	

	}
	newText.append("\n");

	}
ofstream outfile("tri_words.txt");
outfile <<newText;
readfile.close();
outfile.close();

}else cout << "Unable to open file";

}


vector<string> makeTrigrams(string& tempLine){
string temp = "";
int count =0;
vector<string> arr = {};
if(tempLine.size()>2){

	for(char& ch : tempLine){
		temp+=ch;
		if(temp.size() == 3){
		arr.push_back(temp);
		temp.erase(0,1);
		count++;
		}
	}
	
}
sort(arr.begin(), arr.end());
arr.insert(arr.begin(), std::to_string(count));
return arr;
}
