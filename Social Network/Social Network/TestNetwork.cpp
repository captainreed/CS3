#include "friend.h"
#include "friendGroup.h"
#include "unionFind.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>



bool isComplete(Friend list[]);

void main()
{
	const int listSize = 100;
	Friend theList [listSize];
	srand(time(NULL));
	bool finished = false;
	int days = 0;

	for(int i = 0; i < listSize; i++)
	{
		theList[i].id = i;
	}
	
	while (!finished)
	{
		days++;
		int f1 = rand() % 100 + 1;
		int f2 = rand() % 100 + 1;
		if(f1 == f2)
			f2 = rand() % 100 + 1;
		theList[f1].connect(f2);
		if (isComplete(theList))
			finished = true;

	}

	
	std::cout << days << std::endl;
}

bool isComplete(Friend list[])
{

}