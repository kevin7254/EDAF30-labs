#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::pair;
using std::cin;
using std::endl;

Dictionary::Dictionary() {
	string line;
	mySet = {};
	string filename = "words2.txt";
	ifstream file(filename);

	if(file.is_open()) {
		while(getline(file, line)) {
			std::vector<std::string> v = getStrings(line);
			if(v.size() > 0) {
				std::string s = v.at(0);
				mySet.insert(s);
				v.erase(v.begin());
				v.erase(v.begin());
				Word wr{s, v};
				if(s.size() < 25) words[s.size()].push_back(wr);
			}
		}
	}
	file.close();
}


std::vector<std::string> Dictionary::getStrings(std::string& line) {
	std::vector<std::string> arr;
	std::string dec = "  ";
	line.erase(line.begin());
	size_t pos = 0;
	std::string token;
	while((pos = line.find(dec)) != std::string::npos) {
		token = line.substr(0, pos);
		arr.push_back(token);
		line.erase(0, pos + dec.length());
	}
	return arr;
}

bool Dictionary::contains(const string& word) const {
	cout << mySet.count(word) << endl;
	return (mySet.count(word) == 1) ? true : false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigrams(suggestions,word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigrams(vector<string>& suggestions, const string& word) const {
	int length = word.size() - 1;
	std::vector<std::string> mispelledArr = makeTrigrams(word);
	for(int i = length; i <=length+2;i++) {
		for(Word w : words[i]) {
			if(w.get_matches(mispelledArr) > (mispelledArr.size() / 2)) {
				suggestions.push_back(w.get_word());
			}
		}
	}
}

std::vector<std::string> Dictionary::makeTrigrams(const std::string& line) const {
        std::string temp = "";
        std::vector<std::string> arr = {};
        if(line.length() > 3) {
                for(const char& c : line) {
                        if(temp.length() == 3) {
                                arr.push_back(temp);
                                temp.erase(0,1);
                        }
                        temp += std::tolower(c, std::locale());
                }
                sort(arr.begin(), arr.end());
        } else if(line.length() == 3) {
                arr.push_back(line);
                arr.push_back(line);
        }
        return arr;

}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const {
	std::vector<pair<int, std::string>> vec;
	for(string s : suggestions) {
		vec.push_back(make_pair(edit_distance(word, s), s));
	}
	std::sort(vec.begin(), vec.end());
}

int Dictionary::edit_distance(const std::string& s1, const std::string& s2) const {
	const std::size_t len1 = s1.size(), len2 = s2.size();
        int d[maxlen+1][maxlen+1];

        for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
        for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

        for(unsigned int i = 1; i <= len1; ++i)
                for(unsigned int j = 1; j <= len2; ++j)
                      d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });


	return d[len1][len2];
}

void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	suggestions.resize(5);
}
