#include "unionFind.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>



int rootCount(unionFind set);

void main()
{
	unionFind testSet(100);
	srand(time(NULL));
	bool finished = false;
	int days = 0;

	while (!finished)
	{
		days++;
		int f1 = rand() % 100 + 1;
		int f2 = rand() % 100 + 1;
		if(f1 == f2)
			f2 = rand() % 100 + 1;
		testSet.Union(f1, f2);
		if (rootCount(testSet) == 1)
			finished = true;

	}
	std::cout << days << std::endl;
	std::string answer;
	std::cin >> answer;
}

int rootCount(unionFind set)
{
	int roots = 0;
	for (int i = 0; i < set.theList.size(); i++)
	{
		if (set.theList[i] < 0)
			roots++;
	}
	return roots == 1;
}