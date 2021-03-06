#pragma once
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <iostream> 
#include <cassert>


// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class AvlTree
{
private:
	struct AvlNode
	{
		Comparable element;
		AvlNode   *left;
		AvlNode   *right;
		int       height;

		AvlNode(Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0)
			: element{ ele }, left{ lt }, right{ rt }, height{ h } { }

		AvlNode(Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0)
			: element{ std::move(ele) }, left{ lt }, right{ rt }, height{ h } { }
	};

	
public:
	AvlNode * root;

	AvlTree() : root{ nullptr }
	{ }

	AvlTree(const AvlTree & rhs) : root{ nullptr }
	{
		root = clone(rhs.root);
	}

	AvlTree(AvlTree && rhs) : root{ rhs.root }
	{
		rhs.root = nullptr;
	}

	~AvlTree()
	{
		makeEmpty();
	}

	/**
	* Deep copy.
	*/
	AvlTree & operator=(const AvlTree & rhs)
	{
		AvlTree copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	/**
	* Move.
	*/
	AvlTree & operator=(AvlTree && rhs)
	{
		std::swap(root, rhs.root);

		return *this;
	}

	/**
	* Find the smallest item in the tree.
	* Abort if empty.
	*/
	 Comparable & findMin()
	{
		assert(!isEmpty());
		return findMin(root)->element;
	}

	/**
	* Find the largest item in the tree.
	* Abortif empty.
	*/
	Comparable & findMax()
	{
		assert(!isEmpty());;
		return findMax(root)->element;
	}

	/**
	* Returns true if x is found in the tree.
	*/
	bool contains( Comparable & x)
	{
		return contains(x, root);
	}

	/**
	* Test if the tree is logically empty.
	* Return true if empty, false otherwise.
	*/
	bool isEmpty()
	{
		return root == nullptr;
	}

	/**
	* Print the tree contents in sorted order.
	*/
	void displayTheTree(AvlNode *n, std::string indent, int currdepth, int depth)
	{
		if (n == NULL || currdepth>depth) return;

		displayTheTree(n->right, indent + "  ", currdepth + 1, depth);
		
		std::cout << indent << n->element << std::endl;

		displayTheTree(n->left, indent + "  ", currdepth + 1, depth);
		
	}

	void printTree() 
	{
		if (isEmpty())
			std::cout << "Empty tree" << std::endl;
		else
			displayTheTree(root, "", 0, root->height);
	}


	/**
	* Make the tree logically empty.
	*/
	void makeEmpty()
	{
		makeEmpty(root);
	}

	/**
	* Insert x into the tree; duplicates are allowed
	*/
	void insert(Comparable & x)
	{
		insert(x, root);
	}

	/**
	* Insert x into the tree; duplicates are allowed
	*/
	void insert(Comparable && x)
	{
		insert(std::move(x), root);
	}

	/**
	* Remove x from the tree. Nothing is done if x is not found.
	*/
	void remove( Comparable & x)
	{
		remove(x, root);
	}


	void removeMin()
	{

		AvlNode* min = findMin(root);

		remove(min->element);

	}






	/**
	* Internal method to insert into a subtree.
	* x is the item to insert.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void insert( Comparable & x, AvlNode * & t)
	{
		//std::cout << "insert &" << x << std::endl;
		if (t == nullptr)
			t = new AvlNode{ x, nullptr, nullptr };
		else if (x <= t->element)
			insert(x, t->left);
		else if (t->element < x)
			insert(x, t->right);

		balance(t);
	}

	/**
	* Internal method to insert into a subtree.
	* x is the item to insert.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void insert(Comparable && x, AvlNode * & t)
	{
		std::cout << "insert &&" << x << std::endl;
		if (t == nullptr)
			t = new AvlNode{ std::move(x), nullptr, nullptr };
		else if (x <= t->element)
			insert(std::move(x), t->left);
		else if (t->element < x)
			insert(std::move(x), t->right);

		balance(t);
	}

	/**
	* Internal method to remove from a subtree.
	* x is the item to remove.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void remove(Comparable & x, AvlNode * & t)
	{
		if (t == nullptr)
			return;   // Item not found; do nothing

		if (x < t->element)
			remove(x, t->left);
		else if (t->element < x)
			remove(x, t->right);
		else if (t->left != nullptr && t->right != nullptr) // Two children
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else
		{
			AvlNode *oldNode = t;
			t = (t->left != nullptr) ? t->left : t->right;
			delete oldNode;
		}

		balance(t);
	}

	static const int ALLOWED_IMBALANCE = 1;

	// Assume t is balanced or within one of being balanced
	void balance(AvlNode * & t)
	{
		if (t == nullptr)
			return;

		if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
			if (height(t->left->left) >= height(t->left->right))
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
		else
			if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
				if (height(t->right->right) >= height(t->right->left))
					rotateWithRightChild(t);
				else
					doubleWithRightChild(t);

		t->height = max(height(t->left), height(t->right)) + 1;
	}

	/**
	* Internal method to find the smallest item in a subtree t.
	* Return node containing the smallest item.
	*/
	AvlNode * findMin(AvlNode *t) const
	{
		if (t == nullptr)
			return nullptr;
		if (t->left == nullptr)
			return t;
		return findMin(t->left);
	}

	/**
	* Internal method to find the largest item in a subtree t.
	* Return node containing the largest item.
	*/
	AvlNode * findMax(AvlNode *t) const
	{
		if (t != nullptr)
			while (t->right != nullptr)
				t = t->right;
		return t;
	}


	/**
	* Internal method to test if an item is in a subtree.
	* x is item to search for.
	* t is the node that roots the tree.
	*/
	bool contains( Comparable & x, AvlNode *t) const
	{
		if (t == nullptr)
			return false;
		else if (x < t->element)
			return contains(x, t->left);
		else if (t->element < x)
			return contains(x, t->right);
		else
			return true;    // Match
	}
	/****** NONRECURSIVE VERSION*************************
	bool contains( const Comparable & x, AvlNode *t ) const
	{
	while( t != nullptr )
	if( x < t->element )
	t = t->left;
	else if( t->element < x )
	t = t->right;
	else
	return true;    // Match

	return false;   // No match
	}
	*****************************************************/

	/**
	* Internal method to make subtree empty.
	*/
	void makeEmpty(AvlNode * & t)
	{
		if (t != nullptr)
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = nullptr;
	}

	/**
	* Internal method to print a subtree rooted at t in sorted order.
	*/
	void printTree(AvlNode *t) const
	{
		if (t != nullptr)
		{
			printTree(t->left);
			std::cout << t->element << " ";
			printTree(t->right);
		}
	}

	/**
	* Internal method to clone subtree.
	*/
	AvlNode * clone(AvlNode *t) const
	{
		if (t == nullptr)
			return nullptr;
		else
			return new AvlNode{ t->element, clone(t->left), clone(t->right), t->height };
	}
	// Avl manipulations
	/**
	* Return the height of node t or -1 if nullptr.
	*/
	int height(AvlNode *t) const
	{
		return t == nullptr ? -1 : t->height;
	}

	int max(int lhs, int rhs) const
	{
		return lhs > rhs ? lhs : rhs;
	}

	/**
	* Rotate binary tree node with left child.
	* For AVL trees, this is a single rotation for case 1.
	* Update heights, then set new root.
	*/
	void rotateWithLeftChild(AvlNode * & localRoot)
	{
		AvlNode *leftChild = localRoot->left;
		localRoot->left = leftChild->right;
		leftChild->right = localRoot;
		localRoot->height = max(height(localRoot->left), height(localRoot->right)) + 1;
		leftChild->height = max(height(leftChild->left), localRoot->height) + 1;
		localRoot = leftChild;
	}

	/**
	* Rotate binary tree node with right child.
	* For AVL trees, this is a single rotation for case 4.
	* Update heights, then set new root.
	*/
	void rotateWithRightChild(AvlNode * & localRoot)
	{
		AvlNode *rightChild = localRoot->right;
		localRoot->right = rightChild->left;
		rightChild->left = localRoot;
		localRoot->height = max(height(localRoot->left), height(localRoot->right)) + 1;
		rightChild->height = max(height(rightChild->right), localRoot->height) + 1;
		localRoot = rightChild;
	}

	/**
	* Double rotate binary tree node: first left child.
	* with its right child; then node k3 with new left child.
	* For AVL trees, this is a double rotation for case 2.
	* Update heights, then set new root.
	*/
	void doubleWithLeftChild(AvlNode * & localRoot)
	{
		rotateWithRightChild(localRoot->left);
		rotateWithLeftChild(localRoot);
	}

	/**
	* Double rotate binary tree node: first right child.
	* with its left child; then node k1 with new right child.
	* For AVL trees, this is a double rotation for case 3.
	* Update heights, then set new root.
	*/
	void doubleWithRightChild(AvlNode * & localRoot)
	{
		rotateWithLeftChild(localRoot->right);
		rotateWithRightChild(localRoot);
	}
};

#endif
