#ifndef MIN_HEAP
#define MIN_HEAP
#include "ItemType.h"
//the a node in the heap that has has left and right children and an itemptype object
class heapNode
{
public:
	ItemType item;
	heapNode(std::string word = "", int p = 0) { item.word = word;  item.priority = p; npl = 0; };
	heapNode(ItemType i) { item = i;};
	heapNode *left;
	heapNode *right;
	int npl;
};
//the minehap object
class minHeap
{
public:
	static const int KIDS = 2;
	heapNode *root;
	minHeap()
	{
		size = 0;
	}
	void insert(ItemType &newVal)
	{
		heapNode *newNode = new heapNode(newVal.toString(), newVal.priority);
		root = merge(newNode, root);
		size++;
	};	
	int getCount() { return count; };
	int size = 0;
	// merges h into current heap as long as h is a minheap object
	void merge(minHeap *h) { 
		if (this == h) return;
		root = merge(root, h->root);
	};
	//takes 2 root nodes and merges their respective trees
	heapNode* merge(heapNode *n1, heapNode *n2)
	{
		if (n1 == NULL && n2 == NULL) return NULL;
		if (n1 == NULL) return n2;
		if (n2 == NULL) return n1;
		if (n1->item.priority < n2->item.priority)
			return internalMerge(n1, n2);
	};
	//takes 2 node parameters that will need to be merged
	heapNode* internalMerge(heapNode *n1, heapNode *n2)
	{
		if (n1->left == NULL) n1->left = n2;
		else
		{
			n1->right = merge(n1->right, n2);
			if (n1->left->npl < n1->right->npl)
				swapKids(n1);
			n1->npl = n1->right->npl + 1;
		}
		return n1;
	};
	//switch the kids of the given heapnode
	void swapKids(heapNode *n)
	{
		heapNode *temp = n->left;
		n->left = n->right;
		n->right = temp;
	};
	//retrievs the minimum object from the heap, returns the itemtype object
	ItemType deleteMin() {
		if (root->left != NULL && root->right != NULL) {
			root = merge(root->left, root->right);
			size--;
			return root->item;
		}
		return root->item;
		
	};
protected:
	ItemType * heap;   // Heap Array
	int count;
	int physicalSize;  // Physical size of heap
};
#endif