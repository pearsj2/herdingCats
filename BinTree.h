#pragma once
//Author:Jessica Pearson
//This program was created for a class assignmnet, the assignment information and school name have
//been removed for confidentiality
//
// BinTree program will be a binary search tree which will take in data from the 
// file and use it to ctreate a sorted tree of nodes. 
//The nodes will contain pointers as well as a data item of the type 
//NodeData as given in the supplemental files.
////////////////////////////////////////////////////////////////////////////////

#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <string>
#include "NodeData.h"

using namespace std;


class BinTree
{
	//overloads the output operator
	friend ostream& operator<<(ostream&, const BinTree&);

public:
	//construcors and destructor
		BinTree();
		BinTree(const BinTree&);
		~BinTree();

		bool isEmpty() const;//returnns true if the tree is empty, otherwise false
		void makeEmpty();//clears the tree
		
		bool insert(NodeData*);//inserts a new node to the tree
		bool retrieve(const NodeData &, NodeData* &);//returns true if a particular node exists
		int getHeight(const NodeData &);//returns the height of the tree
				
		void bstreeToArray(NodeData*[]);//assuming statically allocated array
									//of 100 null elements. No size error checking necessary
		void arrayToBSTree(NodeData*[]);//Takes a sorted array of NodeData*
									//and leaves the array filled with nulls and builds a balanced tree
		void displaySideways() const;//given to us in files

		//Operator overloads are limited to equality and assignment operators
		//Other operators were not added because they don't fit the scope of this assignmnet
		
		// assignment operator
		BinTree& operator=(const BinTree&);

		// equality and inequality operators
		bool operator==(const BinTree&) const;
		bool operator!=(const BinTree&) const;



private:

	//basic node structure including pointers to left/right subtrees and data object
	//Data object will be coming from NodeData files that were given
		struct Node
		{
		
			Node* left;
			Node* right;
			NodeData* data;
		};
		Node* root;

	////////////////////////////////////////////////////////////////////////////////
	//Helper functions for use within the public class functions. 
	//These helper functions should make code more readable and versatile.
	////////////////////////////////////////////////////////////////////////////////

		void copyTreeHelper(Node* &lhs, Node* rhs) const;//for use in the assignment operator overload

		bool compareTrees(Node*, Node*) const;//for use in the comparison overload


		void makeEmptyHelper(Node* &);//for use in clearing the tree
		bool insertHelper(Node* &, NodeData*);//for use in the insert function

		bool retrieveHelper(Node* &, const NodeData&, NodeData* &);//for use in retrieve function

		bool findRootHelper(Node*&, const NodeData&, Node*&);////for use in get height function

		int getHeightHelper(Node*&);//helper for get height function


		void sideways(Node*, int) const;///
		void bstreeToArrayHelper(const Node*, NodeData*[], int&);//for use in bstree to array function

		Node* arrayToBSTreeHelper(NodeData*[], int, int);//for use in array to BSTree function
		void traversalInOrderHelper(Node*) const;//in order traversal for use in output overload

};

	int returnLarger(int, int);  // Returns larger integer between two parameters.

#endif
