#include "editor.h"

#include <string>
#include <iostream>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const {
	std::string str = text;
	int i = 1;
	int t = pos-1;

	std::cout << str << "\n";

	while(i > 0) {
		char c = str[++t];
		if((c=='(') || (c=='{') || (c=='[')) {
			i++;
		} else if((c==')') || (c=='}') || (c==']')) {
			i--;
		}
	}		
       	return t;
}
