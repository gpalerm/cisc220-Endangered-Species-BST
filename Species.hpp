#ifndef SPECIES_HPP_
#define SPECIES_HPP_

#include <iostream>
#include <stdlib.h>
using std::string;


class Species {
	friend class TNode;
	friend class BST;  // you'll need to change this
	friend class Interface;
	string name;  // name of the species
	string status;   // the level of threat - T1, T2, or T3
	string info;  // a short paragraph describing the species threat
public:
	Species(const string sp, const string st, const string inf);
	Species();
        // I did not write a destructor because the default destructor is sufficient here.
        // No fields are on the heap
};




#endif /* SPECIES_HPP_ */
