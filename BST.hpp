//
// Created by Giost on 10/27/2025.
//

#ifndef ENDANGEREDSPECIESBSTFORSTUDENTS_BST_H
#define ENDANGEREDSPECIESBSTFORSTUDENTS_BST_H

#include <iostream>
#include <stdlib.h>
#include "Species.hpp"
#include "TNode.hpp"
using std::string;

class BST {
    TNode* root;   // points to tree's root
    int size;      // num of nodes in tree
    bool xtra;

public:
    // constructor & destructor
    BST(bool Xtra);
    ~BST();

    // helper for destructor
    void clear(TNode* node = nullptr);

    // step 1 methods
    bool insert(const string &name, const string &status, const string &info, TNode* node = nullptr);

    void printTreeIO();
    void printTreePre();
    void printTreePost();

    void printTreeIO(bool XtraInfo, TNode* node);
    void printTreePre(bool XtraInfo, TNode* node);
    void printTreePost(bool XtraInfo, TNode* node);

    // step 2 methods
    TNode* find(const string &name);
    TNode* find(const string &name, TNode* node);

    // step 3 methods
    void updateStatus(const string &name, const string &newStatus);

    // step 4 methods

        // helpers
    TNode* removeNode(TNode* node, const string &name);
    TNode* findMin(TNode* node);
    void updateHeight(TNode* node);

    TNode* remove(const string &name, TNode* node = nullptr);


    // AVL Extra Credit
    void checkForRotation(TNode* node);
    int getBalance(TNode* node);
    TNode* rebalance(TNode* node, int balance);

    TNode* leftRotation(TNode* node);
    TNode* rightRotation(TNode* node);
};


#endif //ENDANGEREDSPECIESBSTFORSTUDENTS_BST_H