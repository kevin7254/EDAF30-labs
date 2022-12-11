#include "editor.h"
#include <iostream>

#include <string>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const {
	char right = text.at(pos);
	unsigned int temp =0;
	char left;
	if(right == ')'){
	left ='(';
	}
	if(right == '}'){
	left = '{';
	}
	if(right == ']'){
	left ='[';
	}
	for(int i = pos-1; i>0; i--){;
		if(text.at(i) == right){
		temp++;
		}else if(text.at(i) == left){
		if(temp==0){
			return i;
		}
			temp--;
		
		}
	}	
    	return string::npos;
}
