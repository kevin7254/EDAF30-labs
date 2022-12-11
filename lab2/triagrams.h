fndef TRIAGRAMS.H
#define TRIAGRAMS.H

#include <string>
#include <vector>
#include "word.h"

class T {
	public:
	void read();


	private:
	std::vector<string> makeTrigrams(string&);
};

#endif
