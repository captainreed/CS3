#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>


template <class Etype>
class TreeNode
{
public:
	Etype element;  // value in node
	TreeNode *left;  // left child
	TreeNode *right; // right child
	TreeNode *parent; // parent of node
	TreeNode(Etype e = 0, TreeNode *l = NULL, TreeNode *r = NULL, TreeNode *p = NULL) :
		element(e), left(l), right(r), parent(p) { }
};

template <class Etype>
class BinaryTree
{
protected:
	TreeNode<Etype> *root;  // root of tree
	Etype LOW;   // Smallest possible value stored in tree
	Etype HIGH;  // Largest possible value stored in tree
	bool insert(Etype & x, TreeNode<Etype> * & t, TreeNode<Etype>*  p);

	void printTree(TreeNode<Etype> * t, std::string indent, int currDepth = 0, int maxDepth = numeric_limits<int>::max());

	TreeNode<Etype> * findFirst(TreeNode<Etype> * t) const;
	TreeNode<Etype> * find(TreeNode<Etype> * curr, Etype value)const;
	int size(TreeNode<Etype> *t) const;
	TreeNode <Etype>* currentNode;
public:
	/* Return the leftmost value in the tree.  Set a local currentNode to that node.*/
	Etype getFirst() {
		currentNode = findFirst(root);
		if (currentNode == NULL) return LOW;
		return currentNode->element;
	}

	bool isBST()
	{
		return true;
	}



	std::string verticalElements(TreeNode<Etype>* node, int msg)
	{
		std::string message = msg;
		
		if (node == NULL) {
			return message;
		}
		else {
			message = msg + (char)node->element;
			return verticalElements(node->parent, message);
		}

	}

	void printShort(std::string message) {

		message = message + verticalElements(currentNode,currentNode->element);
		std::cout << message << endl;
	}



	BinaryTree(Etype low = 0, Etype high = 0) : root(NULL) {
		LOW = low;
		HIGH = high;
	}

	void makeEmpty()
	{

	}
	//find the successor to currentNode.  Change currentNode to point to the successor.
	void successor(){}
	int width(){return 0;}
	void getMaxCompleteSubtree() {}

	bool perfectBalance(Etype *list, int beg, int final) { return true; }
	void fall() {};
	void flip() {};
	Etype closestCommon(Etype t1, Etype t2) { return LOW; };
	void buildFromPreorder(Etype* list) {};

	//Print the tree preceeded by the "msg".
	// Print the tree to depth "depth"
	// Print the whole tree if no depth is specified
	void  printTree(std::string msg, int depth = numeric_limits<int>::max())
	{
		std::cout << std::endl << msg << std::endl;
		printTree(root, "", 0, depth);
	}

	//Insert item x into the tree using BST ordering
	virtual int insert(Etype & x) { return insert(x, root, NULL); }

	/*Return the value of the currentNode */
	Etype getCurrNodeValue( )
	{
		if (currentNode == NULL) return LOW;
		return currentNode->element;
	}

};


// return the number of nodes in the tree rooted at t
template <class Etype>
int BinaryTree<Etype>::size(TreeNode<Etype> *t) const
{
	if (t == NULL) return 0;
	return (1 + size(t->left) + size(t->right));
}


//Print the contents of tree t
// Indent the tree bby the string "indent"
// Print the tree to a depth of "depth" given "currdepth" is the depth of t
template <class Etype>
void BinaryTree<Etype>::printTree(TreeNode<Etype> *t, std::string indent, int currdepth, int depth)
{
	if (t == NULL || currdepth>depth) return;
	printTree(t->right, indent + "  ", currdepth + 1, depth);
	if (t->parent != NULL)
		cout << indent << t->element << "(" << t->parent->element << ")" << endl;
	else
		cout << indent << t->element << "( no parent)" << endl;
	printTree(t->left, indent + "  ", currdepth + 1, depth);
}

// insert inserts data into the tree rooted at t
// parent is the parent of t
// Returns true if insertion is successful  (duplicates are not allowed)
// Code is O(log n) for a balanced tree as each level is accessed once
// This inserts as if we wanted to created a binary search tree.
template <class Etype>
bool BinaryTree<Etype>::insert(Etype & data, TreeNode<Etype> * & t, TreeNode<Etype> *  parent)
{
	if (t == NULL)
	{  // cout << "inserting " << data << endl;
		t = new TreeNode<Etype>(data, NULL, NULL, parent);
		if (t == NULL) return false;
		return true;
	}
	if (data < t->element) return insert(data, t->left, t);
	return insert(data, t->right, t);
}
// find seaches for data in the tree rooted at curr
// Returns the node if the find is successful, NULL otherwise
// Code is O(log n) for a balanced tree as each level is accessed once


// Find the leftmost node in a tree rooted at t.
template <class Etype>
TreeNode<Etype> * BinaryTree<Etype>::findFirst(TreeNode<Etype> * t) const
{
	TreeNode<Etype>* s = t;
	for (; s->left != NULL; s = s->left)
		;
	return s;
}


