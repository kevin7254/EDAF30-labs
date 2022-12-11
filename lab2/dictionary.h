#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"
class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	void add_trigram_suggestions(std::vector<std::string>& suggestions,const std::string& word) const; 
	int edit_distance(const std::string& s1, const std::string& s2) const;
	void rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
	void trim_suggestions(std::vector<std::string>& suggestions)const;
private:
	std::unordered_set <std::string> stringSet;
	static constexpr int maxlen{25};
	std::vector<Word> words[maxlen];
};

#endif
