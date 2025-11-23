

#ifndef TNode_HPP_
#define TNode_HPP_

#include <iostream>
#include <stdlib.h>
#include "Species.hpp"

using std::string;

class TNode{
	friend class BST;  // You should change this to whatever you called your BST class
	friend class Interface;
	TNode *left;
	TNode *right;
	TNode *parent;
	Species *animal;
	int height;
public:
	TNode(const string &sp, const string &st, const string &inf);
	TNode();
	~TNode();
	void printNode(const bool XtraInfo);
};




#endif /* TNode_HPP_ */
