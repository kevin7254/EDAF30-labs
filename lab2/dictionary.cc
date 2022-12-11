#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <utility>
#include <unordered_set>
#include <sstream>

using std::string;
using std::vector;
using std::pair;

Dictionary::Dictionary() {
	std::ifstream wordfile("tri_words.txt");
	string str;
	string word;
	string tempWord;
	int location=0;
	int cnt =0;
	if(wordfile.is_open()){
	while(getline(wordfile,str)){
	std::istringstream iss(str);
	std::vector<string> trigrams;
	cnt =0;
		while(iss >> word){	
		if(cnt ==0) {
		location = word.size();
		stringSet.insert(word);
		tempWord = word;
		cnt++;
		}
		else if(cnt==1) {cnt++;}
		else{
		trigrams.push_back(word);
		cnt++;
		}
		}
		if(location <maxlen){
		Word wr{tempWord, trigrams};
		words[location].push_back(wr);	
	}
				
	}
	}
}

bool Dictionary::contains(const string& word) const {
	if(stringSet.count(word)==1){
		return true; 
	}
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}


void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const{	
	int length = word.size();
	std::vector<string> tri;
	int pos =0;
	if(length >2){
	while(pos <length-2){
	tri.push_back(word.substr(pos, 3));	
	pos++;
	}
	for(int i = length-1; i<= length+2; i++)	{
		for(Word w : words[i]){
		if(w.get_matches(tri) > tri.size()/2.0){
		suggestions.push_back(w.get_word());
	}
	}
	}

}
}
void Dictionary::trim_suggestions(vector<string>& suggestions)const{
		if(suggestions.size() > 5){
		suggestions.resize(5);

		}
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const{
	std::vector<pair<int, string>> v;
	for(string s : suggestions){
	int a = edit_distance(word, s);
	v.push_back(make_pair(a, s));
	}		
       	std::sort(v.begin(), v.end());

}

int Dictionary::edit_distance(const std::string& s1, const std::string& s2) const{

	        const std::size_t len1 = s1.size(), len2 = s2.size();
		std::vector<std::vector<unsigned int>> d(maxlen + 1, std::vector<unsigned int>(maxlen + 1));
		 d[0][0] = 0;
		        for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	        	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;
		
		       	for(unsigned int i = 1; i <= len1; ++i)
			for(unsigned int j = 1; j <= len2; ++j)
			 d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
			        return d[len1][len2];
			}


