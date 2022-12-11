#include "tagremover.h"
#include <string>
#include <fstream>
#include <iostream>

std::string decode(std::string& code){
	if(code == "&lt;"){
		return "<";
	}else if(code == "&gt;"){
		return ">";
	}else if(code == "&nbsp;"){
		return " ";
	}else if (code == "&amp;"){
		return "&";
	}
return code;
}


TagRemover::TagRemover(std::istream& in) {
	std::string line;
	std::string sub;
	while(getline (in, line)){
		text.append(line);
		text.append("\n");
	}
		std::size_t open = text.find("<");
		std::size_t close = text.find(">");

	while(close!=std::string::npos){
		int tag = close - open +1;		
		text.erase(open, tag);
		open = text.find("<");
		close = text.find(">");
	}

		std::size_t s_open = text.find('&');
	while(s_open != std::string::npos){
		std::size_t s_close = text.find(';', s_open);
		int s_tag = s_close -s_open+1;
		std::string sub = text.substr(s_open, s_tag);		
		std::string rep = decode(sub);
		text.replace(s_open, s_tag, rep);
		s_open = text.find('&', s_open+1);
		}
	}

std::string decodee(std::string& code){
	if(code == "&lt;"){
		return "<";
	}else if(code == "&gt;"){
		return ">";
	}else if(code == "&nbsp;"){
		return " ";
	}else if(code == "&amp;"){
		return "&";
	}else{
		return code;

}
}
void TagRemover::print(std::ostream& out){
	out << text << std::endl;
}
