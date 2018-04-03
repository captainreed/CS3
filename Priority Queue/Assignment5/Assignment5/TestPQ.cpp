#include "PQHeap.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"
#include <time.h>
//#include "SkewHeap.h"
//#include "Leftist.h"

//Insert limit elements of the file fin into heap.
void insertNext(PQ & pq,std::ifstream & fin,int limit=0) 
{	if (limit ==0) 
		limit = std::numeric_limits<int>::max();
	std::string word;
	int ct;
	for (int i =0; i <= limit && !fin.eof(); i++)
	{
		fin >> word >> ct;
		//std::cout << "inserting " << word << ct << std::endl;
		ItemType item(word, ct);
		pq.insert(item);
	}
}

void insertNext(minHeap & pq, std::ifstream & fin, int limit = 0)
{
	if (limit == 0)
		limit = std::numeric_limits<int>::max();
	std::string word;
	int ct;
	for (int i = 0; i <= limit && !fin.eof(); i++)
	{
		fin >> word >> ct;
		//std::cout << "inserting " << word << ct << std::endl;
		ItemType item(word, ct);
		pq.insert(item);
	}
}

void insertNext(medianHeap & pq, std::ifstream & fin, int limit = 0)
{
	if (limit == 0)
		limit = std::numeric_limits<int>::max();
	std::string word;
	int ct;
	for (int i = 0; i <= limit && !fin.eof(); i++)
	{
		fin >> word >> ct;
		//std::cout << "inserting " << word << ct << std::endl;
		ItemType item(word, ct);
		pq.insert(item);
	}
}


int main()
{   
	int const DELETE_CT=20;
	int const PRINTSIZE=30;
	int const HOWMANY = 100;  

	//PQHeap pqMax("MaxHeap",6000);
	minHeap pqmin;
	maxHeap pqMax("theMaxHeap", 6000);
	medianHeap medHeap;
	

	//process time for maxheap operation
	clock_t maxclk = clock();
	std::ifstream maxfin;
	maxfin.open("Prog5In.txt");
	assert(maxfin);

	for (int i = 0; i < 60; i++)
	{
		insertNext(pqMax, maxfin, HOWMANY);
		std::cout << pqMax.deleteMax().toString() << std::endl;
	}


	clock_t maxtime = clock()-maxclk;
	std::cout << "Elapsed time = " << ((float) maxtime)/CLOCKS_PER_SEC << std::endl;
	maxfin.close();
	
	//process time for minheap operation
	clock_t minclk = clock();
	std::ifstream minfin;
	minfin.open("Prog5In.txt");
	assert(minfin);

	for (int i = 0; i < 60; i++)
	{
		insertNext(pqmin, minfin, HOWMANY);
		std::cout << pqMax.deleteMax().toString() << std::endl;
	}
	
	clock_t mintime = clock() - minclk;
	std::cout << "Elapsed time = " << ((float) mintime) / CLOCKS_PER_SEC << std::endl;
	minfin.close();


	//process time for median heap operation
	clock_t medclk = clock();
	std::ifstream medfin;
	medfin.open("Prog5In.txt");
	assert(medfin);

	for (int i = 0; i < 60; i++)
	{
		insertNext(medHeap, medfin, HOWMANY);
		
		std::cout << medHeap.getMedian().toString() << std::endl;
	}


	clock_t medtime = clock() - medclk;
	std::cout << "Elapsed time = " << ((float)maxtime) / CLOCKS_PER_SEC << std::endl;
	medfin.close();
		
	std::cin.ignore();
}


