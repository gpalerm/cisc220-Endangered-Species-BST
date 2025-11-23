#include "TNode.hpp"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
using std::string;

// constructor for empty node
TNode::TNode() {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    animal = nullptr;
    height = 1;
}

// constructor for creating a node with an animal
TNode::TNode(const string &name, const string &status, const string &info) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    animal = new Species(name, status, info);
    height = 1;
}

// printing the node's animal
void TNode::printNode(const bool XtraInfo) {
    // checking if empty node, if so it returns early
    if (!animal) {
        cout << "node is empty" << endl;
        return;
    }

    // printing the node's animal's information
    if (XtraInfo) {
        cout << "\n" << "Name: " << animal->name << endl;
        cout << "Status: " << animal->status << endl;
        cout << "Info: " << animal->info << endl;
        cout << "Height: " << height << "\n";
        /*******************************************/
        if (parent) {
            cout << "Parent: " << parent->animal->name << endl;
        }
        else {
            cout << "Node is Root" << endl;
        }
        /*******************************************/
        if (left) {
            cout << "Left Child: " << left->animal->name << endl;
        }
        else {
            cout << "No Left Child" << endl;
        }
        /*******************************************/
        if (right) {
            cout << "Right Child: " << right->animal->name << endl;
        }
        else {
            cout << "No Right Child" << endl;
        }
    }
}


TNode::~TNode() {
    if (animal) {
        delete animal;
        animal = nullptr;
    }
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}