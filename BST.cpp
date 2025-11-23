#include "BST.hpp"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
using std::string;

                            // step 1
//constructor
BST::BST(bool Xtra) {
    root = nullptr;
    size = 0;
    xtra = Xtra;
}

// insert: adds a node for a new species, returns true if it gets inserted and fale otherwise
bool BST::insert(const string &name, const string &status, const string &info, TNode *node) {

    // creates a root if the tree is empty
    if (!root) {
        root = new TNode(name, status, info);
        size = 1;
        cout << "created root" << endl;
        return true;
    }

    // starts from root if node isn't given
    if (!node) {
        node = root;
    }

    // making sure its not a duplicate
    if (name == node->animal->name) {
        return false;
    }

    // if name is less alphabetically then move left
    if (name < node->animal->name) {

        // if the node has a left child then it keeps moving down recursively
        if (node->left) {
            return insert(name, status, info, node->left);
        }

        // otherwise it inserts the new species node there, updates its parent & height & tree's size
        else {
            node->left = new TNode(name, status, info);
            node->left->parent = node;
            updateHeight(node);
            checkForRotation(node);
            size++;
            return true;
        }
    }

    // otherwise move right
    else {
        if (node->right) {
            return insert(name, status, info, node->right);
        }
        else {
            node->right = new TNode(name, status, info);
            node->right->parent = node;
            updateHeight(node);
            checkForRotation(node);
            size++;
            return true;
        }
    }
}

// setting up to be called with no input parameters and then overloaded
void BST::printTreeIO() {
    printTreeIO(xtra, root);
}

void BST::printTreePre() {
    printTreePre(xtra, root);
}

void BST::printTreePost() {
    printTreePost(xtra, root);
}

// goes left tree, then the current node, then the right tree
void BST::printTreeIO(bool XtraInfo, TNode* node) {
    // checking if empty, returns early if so
    if (!root) {
        return;
    }

    // starts from root if node isn't given
    if (!node) {
        node = root;
    }

    // if there's a left child it keeps moving down
    if (node->left) {
        printTreeIO(XtraInfo, node->left);
    }

    // if there's no left child it prints the current node
    // then returns and pops back to parent
    node->printNode(XtraInfo);

    // then it moves down the right and repeats
    if (node->right) {
        printTreeIO(XtraInfo, node->right);
    }
}

// goes current node, then the left tree, then the right tree
void BST::printTreePre(bool XtraInfo, TNode* node) {
    if (!root) {
        return;
    }

    if (!node) {
        node = root;
    }

    // prints the current node
    node->printNode(XtraInfo);

    // moves recursively left as far as possible, then return and pop back up
    // then move right and repeat
    if (node->left) {
        printTreePre(XtraInfo, node->left);
    }
    if (node->right) {
        printTreePre(XtraInfo, node->right);
    }
}

// goes left tree, then the right tree, then current node
void BST::printTreePost(bool XtraInfo, TNode* node) {

    if (!root) {
        return;
    }

    if (!node) {
        node = root;
    }

    //
    if (node->left) {
        printTreePost(XtraInfo, node->left);
    }
    if (node->right) {
        printTreePost(XtraInfo, node->right);
    }
    node->printNode(XtraInfo);
}



                            // step 2
// making it start from root if not given a node
TNode* BST::find(const string &name) {
    return find(name, root);
}

// overloading to take in a node
TNode *BST::find(const string &name, TNode *node) {

    // tree empty
    if (node == nullptr) {
        return nullptr;
    }

    // if the name matches the current node, the species is found and it
    // returns that node
    if (name == node->animal->name) {
        return node;
    }

    // if the search name is less than the current node's name, it moves recursively left
    if (name < node->animal->name) {
        return find(name, node->left);
    }

    // otherwise it moves recursively right
    return find(name, node->right);
}

                            // step 3

void BST::updateStatus(const string &name, const string &newStatus) {
    // finds the node with that species name first
    TNode* t = find(name);

    // then updates its status
    if (t) {
        t->animal->status = newStatus;
    }
}


                            // step 4

TNode* BST::remove(const string &name, TNode* node) {
    // empty tree
    if (!root) {
        return nullptr;
    }
    // starts at the root if the node isn't given
    if (!node) {
        node = root;
    }

    // calling the recursive helper
    return removeNode(node, name);
}

// helper
TNode* BST::removeNode(TNode* node, const string &name) {
    if (!node) {
        return nullptr;
    }

    // moving recursively left or right until the names match and the node is found
    if (name < node->animal->name) {
        return removeNode(node->left, name);
    }
    else if (name > node->animal->name) {
        return removeNode(node->right, name);
    }

    // node found
    else {
        // first case: no children
        if (!node->left && !node->right) {

            // unlinking from parent
            if (node->parent) {

                // checks if the node to be removed is a left child or
                // right child then unlinks
                if (node->parent->left == node) {
                    node->parent->left = nullptr;
                }
                else {
                    node->parent->right = nullptr;
                }
            }

            // else if it doesn't have a parent then its the root
            // so it just sets root to null
            else {
                root = nullptr;
            }

            // stores the node, updates the heights & tree size, then returns
            // the removed node
            TNode* temp = node;
            updateHeight(node->parent);
            checkForRotation(node);
            size--;
            return temp;
        }


        // second case: one child
        if (!node->left || !node->right) {
            TNode* child;

            // determining if it has a left or right child
            if (node->left) {
                child = node->left;
            } else {
                child = node->right;
            }

            // checks if the node to be removed is a left child or right child,
            // then updates the parent's pointer to skip over the node
            if (node->parent) {
                if (node->parent->left == node) {
                    node->parent->left = child;
                } else {
                    node->parent->right = child;
                }
            }
            // if the node to be removed is the root then the root is updated to be
            // the node's child
            else {
                root = child;
            }

            // updating the child's parent to skip over the node to be removed
            if (child) {
                child->parent = node->parent;
            }

            // stores the node, updates the heights & tree size, then returns
            // the removed node
            TNode* temp = node;
            updateHeight(node->parent);
            checkForRotation(node);
            size--;
            return temp;
        }

        // case 2: two children
        // finding the smallest in right subtree,
        // since it would be larger than everything to the left of the
        // node to be removed but still smaller than everything to the
        // right of that node
        TNode* replacement = findMin(node->right);

        // replacing the species to be removed with the chosen replacement
        // deletes the animal at the node with the species being removed then updates
        // its animal to be the species of the replacement
        delete node->animal;
        node->animal = new Species(replacement->animal->name,
                                   replacement->animal->status,
                                   replacement->animal->info);


        // removing the replacement node
        // the replacement can't possibly have two children so it can use one of
        // the first two removal cases
        // also storing the removed node and returning it
        TNode* removed = removeNode(node->right, replacement->animal->name);
        updateHeight(node);
        checkForRotation(node);
        //no need to decrease size here because the recursive call handles that when it branches to one of the first two
        //removal cases
        return removed;
    }
}

// finding the minimum/leftmost node
TNode* BST::findMin(TNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

void BST::updateHeight(TNode* node) {

    // loops until it reaches the root (parent of previous iteration's node would be null)
    while (node) {
        int leftHeight = 0;
        int rightHeight = 0;

        // getting the heights of the left and right children
        if (node->left) {
            leftHeight = node->left->height;
        }
        if (node->right) {
            rightHeight = node->right->height;
        }

        // the node's height is the greater of its children's heights plus one
        if (leftHeight > rightHeight) {
            node->height = leftHeight + 1;
        }
        else {
            node->height = rightHeight + 1;
        }

        // moves up to the parent to update its height
        node = node->parent;
    }
}

BST::~BST() {
    clear(root);
    // sets size to 0 when finished
    size = 0;
}

// helper for destructor
void BST::clear(TNode* node) {
    // makes sure a node is given
    if (!node) {
        return;
    }

    // moves recursively all the way down to the leftmost node, deletes it,
    // pops back to parent, then moves right & repeats
    clear(node->left);
    clear(node->right);
    delete node;

    // once it gets to the root node it sets root to null
    if (node == root) {
        root = nullptr;
    }
}

void BST::checkForRotation(TNode* node) {

    while (node) {
        int balance = getBalance(node);

        if (balance > 1 || balance < -1) {
            rebalance(node, balance);
        }
        else {
            node = node->parent;
        }
    }
}

int BST::getBalance(TNode* node) {

    if (!node) {
        return 0;
    }

    if (!node->left && !node->right) {
        return 0;
    }

    else if (!node->left) {
        return 0 - node->right->height;
    }

    else if (!node->right) {
        return node->left->height;
    }

    else {
        return node->left->height - node->right->height;
    }

}

TNode* BST::rebalance(TNode* node, int balance) {

    //right heavy
    if (balance <= -2) {
        int rightChildBalance = getBalance(node->right);

        //RR
        if (rightChildBalance <= 0) {
            return leftRotation(node);
        }

        //RL
        else {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
    }

    //left heavy
    else if (balance >= 2) {
        int leftChildBalance = getBalance(node->left);

        //LL
        if (leftChildBalance >= 0) {
            return rightRotation(node);
        }

        //LR
        else {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
    }

    //still balanced no rotation needed
    return node;
}

TNode* BST::leftRotation(TNode* node) {
    if (!node) {
        return nullptr;
    }

    cout << "***************************************\nLeft Rotating: " << node->animal->name << "\n***************************************" << endl;

    TNode* rightChild = node->right;
    if (!rightChild) {
        return node;
    }

    //unbalanced node's right points to right child's left
    node->right = rightChild->left;
    if (rightChild->left) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;
    //node was root
    if (!node->parent) {
        root = rightChild;
    }
    //node was a left child
    else if (node->parent->left == node) {
        node->parent->left = rightChild;
    }
    //node was a right child
    else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;

    updateHeight(node);
    return rightChild;
    //returning the new subtree root
}

TNode* BST::rightRotation(TNode* node) {
    if (!node) {
        return nullptr;
    }

    cout << "***************************************\nRight Rotating: " << node->animal->name << "\n***************************************" << endl;

    TNode* leftChild = node->left;
    if (!leftChild) {
        return node;
    }

    //unbalanced node's left points to left child's right
    node->left = leftChild->right;
    if (leftChild->right) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;
    //node was root
    if (!node->parent) {
        root = leftChild;
    }
    //node was a left child
    else if (node->parent->left == node) {
        node->parent->left = leftChild;
    }
    //node was a right child
    else {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;

    updateHeight(node);
    return leftChild;
    //returning new subtree root
}



