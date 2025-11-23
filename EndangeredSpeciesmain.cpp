#include "BST.hpp"
#include "Interface.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;


int main() {

	/******************************************************************************
	 * I wrote the TNode class first.
     *
	 * For Testing - this is how I did it (there's more than one way!!!)
	 * Step 1:
	 * I First wrote the constructor, the insert, and the 3 print methods (I didn't
	 * write the setHeights until after, so all heights started at 1)
     *
     * Use your testing data to see if these methods are working properly
	******************************************************************************
	* Step 2:
	* I then wrote find and tested.
	* Again, use your test data to determine if this works properly
	******************************************************************************
	* Step 3:
	* I then wrote updateStatus and tested:  - you know the deal
	****************************************************************************
	* Step 4:
	* I started writing the remove method(s).
	* My approach (not necessarily yours):
    * I wrote one general remove method and 2 helper method.
    * The general remove method indes the node to be removed.
    * It determines if the node has 0 children, one child, or 2 children.
    * If it has 0 children, it calls a helper method for removing a node with
    * 0 children (remember to update the heights of nodes after removal)
    * You should test this method with your test data on removing a node with no children.
    *
    * Step 4b:
    * I then wrote the method that removes a node with 1 child
    * test with your data on removing a node with 1 child.
    *
    * Step 4c:
    * Finally, I wrote the part of the general remove method that dealt with removing a
    * node with two children.  Because this involves replacing the node with two children with
    * another node in the tree, you are in essence removing a node with either 0 or 1 child.
    * make sure you call the appropriate method (or deal with this removal).  AND make sure you
    * update heights appropriately
    * Test with your test data.


	********************************************************************
	If you've made it this far, congratulations!!!!!  Now you should run
	The code below, and play around.
	YOu can play around with the menu interface fo the smaller test file,
	and when you're satisfied everything runs, you can play around with the
	larger endangered Species file.
	********************************************************************/
	Interface interface("EndangeredSpeciesSubset.txt", true);
	interface.Menu();
	return 0;
}

