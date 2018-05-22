#include "stdafx.h"
#include "IntBinaryTree.h"
#include <iostream>
#include <iomanip>      // std::setw
#include <algorithm>    // max
#include <queue>		// for queue
using namespace std;

//*******************************************************************
// name: insert
// Called By: insertNode
// passed: TreeNode*&, TreeNode*&
// returns: none
// calls: insert
// Description: inserts nodes to tree
//*******************************************************************
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode; // Insert the node.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode); // Search the left branch.
	else
		insert(nodePtr->right, newNode); // Search the right branch.
}

//*******************************************************************
// name: insertNode
// Called By: main
// passed: int
// returns: none
// calls: insert
// Description: creates new node and inserts to tree
//*******************************************************************
void IntBinaryTree::insertNode(int num)
{
	TreeNode *newNode = nullptr; // Pointer to a new node.

	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;
	
	// Insert the node.
	insert(root, newNode);
}

//*******************************************************************
// name: destorySubTree
// Called By: none
// passed: TreeNode *
// returns: none
// calls: destroySubTree
// Description: destroys entire sub tree
//*******************************************************************
void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//*******************************************************************
// name: remove
// Called By: none
// passed: int
// returns: none
// calls: deleteNode
// Description: deletes specific number from tree
//*******************************************************************
void IntBinaryTree::remove(int num)
{
	deleteNode(num, root);
}

//*******************************************************************
// name: deleteNode
// Called By: remove
// passed: int, TreeNode*&
// returns: none
// calls: deleteNode, makeDeletion
// Description: deletes node
//*******************************************************************
void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

//*******************************************************************
// name: makeDeletion
// Called By: deleteNode
// passed: TreeNode *&
// returns: none
// calls: none
// Description: assister function for deleting nodes
//*******************************************************************
void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
	// Define a temporary pointer to use in reattaching
	// the left subtree.
	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << " Cannot delete empty node." << endl;
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; // Reattach the left child.
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; // Reattach the right child.
		delete tempNodePtr;
	}
	// If the node has two children.
	else
	{
		// Move one node to the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//*******************************************************************
// name: searchNode
// Called By: none
// passed: int
// returns: bool
// calls: none
// Description: searches gor a number in the tree (returns true of false)
//*******************************************************************
bool IntBinaryTree::searchNode(int num)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

//*******************************************************************
// name: displayInOrder
// Called By: main
// passed: TreeNode *
// returns: none
// calls: displayInOrder
// Description: displays tree in incremental order
//*******************************************************************
void IntBinaryTree::displayInOrder(TreeNode *nodePtr, int indent = 0) const
{
	if (nodePtr)
	{
		if(nodePtr->left) 
			displayInOrder(nodePtr->left, indent+4);
		if (indent) {
			cout << setw(indent) << ' ';
		}
		cout << nodePtr->value << endl << " ";
		if (nodePtr->right)
			displayInOrder(nodePtr->right, indent + 4);
	}
}
// ORIGINAL
//void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
//{
//	if (nodePtr)
//	{
//		displayInOrder(nodePtr->left);
//		cout << " " << nodePtr->value << endl;
//		displayInOrder(nodePtr->right);
//	}
//}

//*******************************************************************
// name: displayPreOrder
// Called By: none
// passed: TreeNode *
// returns: none
// calls: displayPreOrder
// Description: displays tree in pre order
//*******************************************************************
void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << " " << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//*******************************************************************
// name: displayPostOrder
// Called By: none
// passed: TreeNode *
// returns: none
// calls: displayPostOrder
// Description: displays tree in post order
//*******************************************************************
void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << " " << nodePtr->value << endl;
	}
}

//*******************************************************************
// name: getLeafCount
// Called By: main
// passed: TreeNode *
// returns: int
// calls: getLeafCount
// Description: returns the number of leaves in the tree
//*******************************************************************
int IntBinaryTree::getLeafCount(TreeNode *nodePtr) const
{
	// if tree is empty, then return 0
	if (nodePtr == nullptr)
		return 0;
	// check if there is only one node
	else if (nodePtr->left == nullptr && nodePtr->right == nullptr)
		return 1;
	// recursively add up the left and right side leaves and return value
	else
		return getLeafCount(nodePtr->left) +
			   getLeafCount(nodePtr->right);
}

//*******************************************************************
// name: getTreeHeight
// Called By: main
// passed: TreeNode *
// returns: int
// calls: getTreeHeight
// Description: returns the height of the tree
//*******************************************************************
int IntBinaryTree::getTreeHeight(TreeNode *nodePtr) const
{
	// if tree is empty, then return 0
	if (nodePtr == nullptr)
		return 0;
	// else recursively iterate through tree and return the max
	else
		return 1 + max(getTreeHeight(nodePtr->left), 
					   getTreeHeight(nodePtr->right));
}

//*******************************************************************
// name: getTreeWidth
// Called By: main
// passed: TreeNode *
// returns: int
// calls: getTreeWidth
// Description: returns the max width of the tree
//*******************************************************************
int IntBinaryTree::getTreeWidth(TreeNode *nodePtr) const
{
	// hold result
	int result = 0;
	// create queue
	queue<TreeNode*> q;
	// if tree is empty, then return 0
	if (nodePtr == nullptr)
		return 0;
	// push root to queue
	q.push(nodePtr);
	while (!q.empty())
	{
		// get current size of queue
		int count = q.size();
		// update max node value
		result = max(count, result);
		// iterate through all nodes
		while (count--)
		{
			// dequeue a node from queue
			TreeNode *temp = q.front();
			q.pop();
			// enqueue left and right children of dequeued node
			if (temp->left != nullptr)
				q.push(temp->left);
			if (temp->right != nullptr)
				q.push(temp->right);
		}
	}
	return result;
}


