#ifndef MED_HEAP
#define MED_HEAP
#include "MaxHeap.h"
#include "MinHeap.h"

#include <iostream>
#include <string>



class medianHeap
{
public:
	ItemType currMedian;
	int size;
	minHeap Min;
	maxHeap Max;
	medianHeap() { size = -1; };
	void insert(ItemType n)
	{
		if (size == -1)
		{
			currMedian = n;
		}

		if (n.priority < currMedian.priority)
		{
			Max.insert(n);
		}
		else
		{
			Min.insert(n);
		}

		if (Max.size > Min.size + 1)
		{
			ItemType oldMedian = currMedian;
			currMedian = Max.deleteMax();
			Min.insert(oldMedian);
		}
		if (Min.size > Max.size + 1)
		{
			ItemType oldMedian = currMedian;
			currMedian = Min.deleteMin();
			Max.insert(oldMedian);
		}
		size++;
	}

	ItemType getMedian()
	{
		return currMedian;
	
		/*
		ItemType Med = currMedian;
		if (Min.size > Max.size)
		{
			currMedian = Min.deleteMin();
		}
		else
		{
			currMedian = Max.deleteMax();
		}
		size--;
		return Med;
		*/
	}

	int getSize()
	{
		return size;
	}






};
#endif
