// PQHeap.cpp - wdg 2008
#ifndef PQHeap_H
#define PQHeap_H

#include "PQ.h"

class PQHeap: public PQ 
{
public:
	//int count;
	static const int KIDS = 2;
	PQHeap(std::string name, int size);
	PQHeap() {};
	void insert(ItemType &);  //    virtual void insert(ItemType & x )=0 ;
	ItemType deleteMax();
	int getCount() { return count; };
	void merge(PQ *h);  // merges h into current heap  
	std::string toString(int size) const;
protected:
	ItemType * heap;   // Heap Array
	int getBestKid(int bestVal,int curr, int size );
	int count;
	int physicalSize;  // Physical size of heap
};


#endif


