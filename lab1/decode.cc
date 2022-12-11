#include <iostream>
#include "coding.h"
#include <fstream>
using namespace std;
void decodefile(){
 	string input;
        cout << "Enter Filename" << endl;	
	cin >> input;
	ifstream myfile(input+".enc");

	string newText;
	char ch;
	if(myfile.is_open())
	{
		while(myfile){
			myfile.get(ch);
			decode(ch);
			newText+= ch;
		}
		ofstream outfile(input + ".dec");
		outfile << newText;

		myfile.close();
	}		
 else cout << "Unable to open file";
}
