#include <iostream>
#include <fstream>

using namespace std;

void readWrite(){
	ifstream readfile("Vad den nu heter");
	string newText;
	char ch;
	if(readfile.is_open()){
		while(readfile){
		readfile.get(ch);
		newText +=ch;
		newText += makeTrigrams(ch);
		}

	}


}

string makeTrigrams(char ch){
string add = "hehjehje";
return add;

}
