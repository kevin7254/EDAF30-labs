#ifndef TAGREMOVER_H
#define TAGREMOVER_H


#include<iostream>
#include<fstream>
#include<string>



class TagRemover{

	public:
		TagRemover(std::istream& in);
		void print(std::ostream& out);



	private:
		std::string text;

};
#endif
