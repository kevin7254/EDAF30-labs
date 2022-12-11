#include <string>
#include <vector>
#include "word.h"
#include <iostream>

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) {
word = w;
trigrams = t;
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int index =0;
	int c =0;
	for(string s : trigrams){
		for(string s2 : t){
		if(s==s2) c++;
		}
	}
		
	return c;
}
