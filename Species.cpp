#include "Species.hpp"

#include <iostream>
#include <string>
using std::string;

// just two constructors - that's it.  No need for a destructor
Species::Species(const string s, const string st, const string inf) {
	name = s;
	status = st;
	info = inf;
}

Species::Species() {
	name = "";
	status = "";
	info = "";
}


