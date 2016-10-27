
//Author:Jessica Pearson
//This program was created for a class assignmnet, the assignment information and school name have
//been removed for confidentiality

// BinTree program will implement a binary search tree which will take in data from the 
// file and use it to ctreate a sorted tree of nodes. The nodes will contain pointers
// as well as a data item of the type NodeData as given in the supplemental files.
//This file will implement all of the functions needed for BinTree
////////////////////////////////////////////////////////////////////////////////
//#include "stdafx.h"
#include "BinTree.h"

//output with BSTree data will use in-order traversal starting at the root
ostream& operator<<(ostream& out, const BinTree& tree)
{
	tree.traversalInOrderHelper(tree.root);
	out << endl;
	return out;
}


//default constructor creates BSTree and sets the root to null
BinTree::BinTree()
{
	root = NULL;
}

//copy constructor takes an existing BSTree and
//copies it to create a new BSTree which has its own spot in memory
BinTree::BinTree(const BinTree& rhs)
{
	copyTreeHelper(root, rhs.root);
}


//true or false check if tree is empty or not
//returns true if tree is empty
bool BinTree::isEmpty() const
{
	return (root == NULL);
}

//destructor uses the helper function to clear the tree
BinTree::~BinTree()
{
	makeEmpty();
}

//passes the root node into the recursive helper function
void BinTree::makeEmpty()
{
	makeEmptyHelper(root);
}


//insert a new node, returns true if insert was successful and false if not
bool BinTree::insert(NodeData* dataPtr)
{
	return insertHelper(root, dataPtr);

}


//checks to see if a data value exists in the BSTree
//returns true if it does and false if it does not
bool BinTree::retrieve(const NodeData& target, NodeData*& found)
{
	return retrieveHelper(root, target, found);
}

//Recursive traversal of the tree
//uses recursive height helper to count nodes to the root
int BinTree::getHeight(const NodeData& target)
{
	Node* found;

	// Find the root node that has the passed-in data.
	if (findRootHelper(root, target, found))
	{
		return getHeightHelper(found);
	}
	else
	{
		return 0;
	}
}

//converts a BSTree into an array form with the same data
//The original tree will be cleared out
void BinTree::bstreeToArray(NodeData* arr[])
{
	int i = 0;  // index of array
	bstreeToArrayHelper(root, arr, i);

	root = NULL;

}

//build a balanced BSTree out of an array. Array is set to max at index 99(100 items)
//We have been told to assume we will never need more than 100 spaces. Any
//unused index after the data in the array is set to null
void BinTree::arrayToBSTree(NodeData* arr[])
{
	int i = 0;  // index of array

				// Count the length of array.
	while (arr[i] != NULL)
	{
		i++;
	}

	root = arrayToBSTreeHelper(arr, 0, i - 1);  //calls helper to
											//do the work of transferring the data
}

//function to display BSTree sideways
void BinTree::displaySideways() const
{
	sideways(root, 0);
}

//assignment operator overload
//Traverses the source tree to make new tree in memory
BinTree& BinTree::operator=(const BinTree& rhs)
{
	if (this != &rhs)
	{
		makeEmptyHelper(root);  
		copyTreeHelper(root, rhs.root);
	}
	return *this;
}

//comparison operator overloads. These will compare to trees and return
//true or false depending on if they are the same
//We want to compare not just the data in the trees, but also the shape of the trees.
bool BinTree::operator==(const BinTree& rhs) const
{
	if (isEmpty() && rhs.isEmpty())
		return true;
	else
		return compareTrees(root, rhs.root);
}

//comparison operator checks to see if two nodes do not have equality
//returns true if they are different, true if they are the same
bool BinTree::operator!=(const BinTree& rhs) const
{
	return !(*this == rhs);
}


///////////////////////////////////////////////////////////////////////////////
// Helper functions that are private to the class
//These are separated for ease of readability
///////////////////////////////////////////////////////////////////////////////

//helper function used in copy constructor
void BinTree::copyTreeHelper(Node*& lhs, Node* rhs) const
{
	if (rhs == NULL)
	{
		lhs = NULL;
	}

	else
	{
		// preorder traversal

		lhs = new Node;  // Create a new node.
		NodeData* temp = new NodeData(*rhs->data);  // Create a new data and set it to rhs's data.
		lhs->data = temp;

		copyTreeHelper(lhs->left, rhs->left);
		copyTreeHelper(lhs->right, rhs->right);
	}
}

//Recursively traverses the tree and clears it out 
//freeing back the memory used for the tree
void BinTree::makeEmptyHelper(Node* &current)
{
	if (current != NULL)
	{
		// postorder traversal

		makeEmptyHelper(current->left);
		makeEmptyHelper(current->right);

		delete current->data;
		current->data = NULL;

		delete current;
		current = NULL;
	}

}

//recursive helper function to insert the target node into the correct position
bool BinTree::insertHelper(Node*& current, NodeData* dataPtr)
{
	if (current == NULL)
	{
		current = new Node();
		current->data = dataPtr;  // Copy the ptr to data.
		current->left = NULL;
		current->right = NULL;
		return true;
	}
	else if (*dataPtr < *current->data)
	{
		insertHelper(current->left, dataPtr);
	}
	else if (*dataPtr > *current->data)
	{
		insertHelper(current->right, dataPtr);
	}
	else
	{
		dataPtr = NULL;  // Since dataPtr is no longer needed, it's set to NULL.
		return false;
	}
}


//recursive function to search the BSTree for a target data
//returns false if the target node is not found in the tree
bool BinTree::retrieveHelper(Node*& current, const NodeData& target, NodeData*& found)
{
	if (current == NULL)
	{
		found = NULL;
		return false;
	}
	else if (target == *current->data)
	{
		found = current->data;  // Store the pointer of found data to passed-in parameter.
		return true;
	}
	else if (target < *current->data)
	{
		return retrieveHelper(current->left, target, found);
	}
	else
	{
		return retrieveHelper(current->right, target, found);
	}
}

//recursive function to search the BSTree for a target data
bool BinTree::findRootHelper(Node*& current, const NodeData& target, Node*& found)
{
	if (current == NULL)
	{
		found = NULL;
		return false;
	}
	else if (target == *current->data)
	{
		found = current;
		return true;
	}
	else if (target < *current->data)
	{
		return findRootHelper(current->left, target, found);
	}
	else
	{
		return findRootHelper(current->right, target, found);
	}
}

//Recursive traversal of the tree
//uses recursive height helper to count nodes to the root
int BinTree::getHeightHelper(Node*& current)
{
	if (current == NULL)
	{
		return 0;
	}
	else
	{
		return (1 + returnLarger(getHeightHelper(current->left),
			getHeightHelper(current->right)));
	}
}

//recursive helper function to traverse BSTree for input to an array
void BinTree::bstreeToArrayHelper(const Node* current, NodeData* arr[], int& i)
{
	if (current == NULL)
	{
		return;
	}

	// inorder traversal

	if (current->left != NULL)
	{
		bstreeToArrayHelper(current->left, arr, i);
	}

	arr[i++] = current->data;

	if (current->right != NULL)
	{
		bstreeToArrayHelper(current->right, arr, i);
	}

	delete current;  //clear node to free memory

}

//recursively traverse the array and transfer the data over to the BSTree
BinTree::Node* BinTree::arrayToBSTreeHelper(NodeData* arr[], int min, int max)
{
	if (min > max)
	{
		return NULL;
	}

	else
	{
		int mid = (min + max) / 2;  //picking a middle node from the array for balanced BSTree


		Node* temp = new Node();
		temp->data = arr[mid];
		arr[mid] = NULL;  // Since it's no longer needed, set the element to NULL.

		temp->left = arrayToBSTreeHelper(arr, min, mid - 1);
		temp->right = arrayToBSTreeHelper(arr, mid + 1, max);
		return temp;
	}
}


//helper function for use in comparison operator overload
//recursively traverses both left hand side and right hand side trees
//We want to check not only for the same data in each tree, but that 
//both trees are of the same shape. If they are not the same shape than 
//for our purposes they are not a match.
bool BinTree::compareTrees(Node* lhs, Node* rhs) const
{

	// checks to see if trees are empty and returns if it is a match
	if ((lhs != NULL && rhs != NULL) && (*lhs->data == *rhs->data))
		return true;

	if ((lhs == NULL) || (rhs == NULL))
		return false;

	//recursively traverse both subtrees and check for equality
	//returns true if they are equal, false if they are not equal
	return (lhs->data == rhs->data) && compareTrees(lhs->left, rhs->left)
		&& compareTrees(lhs->right, rhs->right);

}

//in-order traversal helper function traverses left-root-right
//Recursively traverses the tree
void BinTree::traversalInOrderHelper(Node* current) const
{
	if (current != NULL)
	{
		traversalInOrderHelper(current->left);
		cout << *current->data << " ";
		traversalInOrderHelper(current->right);
	}
}

//function that returns the larger integer between two parameters.
// This function is used in the getHeightHelper function.
int returnLarger(int first, int second)
{
	return (first > second ? first : second);
}

void BinTree::sideways(Node* current, int level) const
{
	if (current != NULL)
	{
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--)
		{
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}
