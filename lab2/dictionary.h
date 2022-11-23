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
	std::vector<std::string> getStrings(std::string& line);
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	void add_trigrams(std::vector<std::string>& suggestions, const std::string& word) const;
	std::vector<std::string> makeTrigrams(const std::string& line) const;
	void rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
	int edit_distance(const std::string& s, const std::string& s2) const;
	std::unordered_set<std::string> mySet;
	static constexpr int maxlen {25};
	std::vector<Word> words[maxlen];
	void trim_suggestions(std::vector<std::string>& suggestions) const;
};

#endif
