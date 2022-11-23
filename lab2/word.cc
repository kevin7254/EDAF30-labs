#include <string>
#include <vector>
#include "word.h"

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
	int c = 0;
	for(string s : trigrams) {
		for(string s2 : t) {
			if(s2 == s)c++;
		}
	}
	return c;
}
