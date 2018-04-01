#include "PQHeap.h"
#include "MaxHeap.h"
#include "MinHeap.h"
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

int main()
{   
	int const DELETE_CT=20;
	int const PRINTSIZE=30;
	int const HOWMANY = 100;  

	//PQHeap pqMax("MaxHeap",6000);
	minHeap pqmin("theMinHeap",6000);
	maxHeap pqMax("theMaxHeap", 6000);

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

	//process time for minheap operation
	clock_t minclk = clock();
	std::ifstream minfin;
	minfin.open("Prog5In.txt");
	assert(minfin);

	for (int i = 0; i < 60; i++)
	{
		insertNext(pqMax, minfin, HOWMANY);
		std::cout << pqMax.deleteMax().toString() << std::endl;
	}


	clock_t mintime = clock() - minclk;
	std::cout << "Elapsed time = " << ((float) mintime) / CLOCKS_PER_SEC << std::endl;


	std::cin.ignore();
}


