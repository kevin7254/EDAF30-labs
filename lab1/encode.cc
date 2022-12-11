#include <iostream>
#include "coding.h"
#include <fstream>
using namespace std;
void encodefile(){
	string input;
	cout << "Enterrrrr Filename" << endl;
 	cin >> input;
	ifstream myfile(input+".txt");

	string newText;
	char ch; 
	if (myfile.is_open())
		        {  
	while(myfile){
	myfile.get(ch);
	encode(ch);
	newText+= ch;
   }
   ofstream outfile(input + ".enc");
   outfile <<newText;

 myfile.close();			}
	      else cout << "Unable to open file";
}

int main(){

encodefile();
decodefile();
return 0;
}
