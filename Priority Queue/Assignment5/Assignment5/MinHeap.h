#ifndef MIN_HEAP
#define MIN_HEAP
#include "ItemType.h"

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
	heapNode* merge(heapNode *n1, heapNode *n2)
	{
		if (n1 == NULL) return n2;
		if (n2 == NULL) return n1;
		if (n1->item.priority < n2->item.priority)
			return internalMerge(n1, n2);
	};

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
	void swapKids(heapNode *n)
	{
		heapNode *temp = n->left;
		n->left = n->right;
		n->right = temp;
	};

	ItemType deleteMin() {
		if (root != NULL) {
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