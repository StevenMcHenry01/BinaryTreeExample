#pragma once
class IntBinaryTree
{
private:
	struct TreeNode
	{
		int value; // The value in the node
		TreeNode *left; // Pointer to left child node
		TreeNode *right; // Pointer to right child node
	};

	TreeNode *root; // Pointer to the root node
	
	// Private member functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(int, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *, int) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;
	int getLeafCount(TreeNode *) const;
	int getTreeHeight(TreeNode *) const;
	int getTreeWidth(TreeNode *) const;
public:
	// constructor
	IntBinaryTree()
		{ root = nullptr; }

	// destructor
	~IntBinaryTree()
	{ destroySubTree(root); }

	// Binary tree operations
	void insertNode(int);
	bool searchNode(int);
	void remove(int);
	void displayInOrder() const
	{ displayInOrder(root, 0); }
	
	void displayPreOrder() const
	{ displayPreOrder(root); }
	
	void displayPostOrder() const
	{ displayPostOrder(root); }

	int getLeafCount() const
	{ return getLeafCount(root); }

	int getTreeHeight() const
	{ return getTreeHeight(root); }

	int getTreeWidth() const
	{ return getTreeWidth(root); }

};

