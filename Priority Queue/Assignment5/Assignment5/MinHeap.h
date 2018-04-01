#ifndef MIN_HEAP
#define MIN_HEAP
#define MAX_HEAP
#include "PQHeap.h"

class minHeap : public PQHeap
{
public:
	static const int KIDS = 2;
	minHeap(std::string name, int physicalSize)
	{
		this->name = name;
		size = 0;
		heap = new ItemType[physicalSize];
		this->physicalSize = physicalSize;
	}
	void insert(ItemType &newVal)
	{
		int curr = size;
		assert(size < physicalSize);
		int parent = (curr - 1) / KIDS; // round down
		while (curr>0 && newVal.priority >heap[parent].priority) {
			heap[curr] = heap[parent];
			curr = parent;
			parent = (curr - 1) / KIDS;
		}
		heap[curr] = newVal;
		size++;
	}
	ItemType deleteMin() {};
};

#endif