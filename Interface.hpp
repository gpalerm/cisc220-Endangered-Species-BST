#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include <iostream>
#include <stdlib.h>
#include "BST.hpp"
using namespace std;

class Interface {
	string fn;
	BST *tree;
public:
	Interface(const string filename, const bool Xtra);
	void readFile();
	void strip(const string s,  string arr[]);

	void Menu();

};




#endif /* INTERFACE_HPP_ */
