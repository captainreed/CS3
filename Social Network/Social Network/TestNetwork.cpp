#include "unionFind.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <time.h>

int rootCount(unionFind set);
bool canBeMerged(int f1, int f2, unionFind set, int &findCount);

void main()
{
	int setSize = 1000; // this is the number of elements that will be joined by the program
	unionFind testSet(setSize); // this object contains the vector will all of the items aswell as the union and find functions
	srand(time(NULL));//random number generator
	bool finished = false;//determine if the program is finished
	int days = 0; // if their is only one new connection a day, how many days does it take to connect all nodes
	int unions = 0;// number of unions needed to connect all nodes
	int finds = 0;// number of finds needed to connect all nodes

	while (!finished)
	{
		days++;
		int f1 = rand() % (setSize - 1);
		int f2 = rand() % (setSize - 1);
		if (f1 == f2)
		{
			f2 = (rand()*f2) % (setSize - 1);
		}
		if (canBeMerged(f1, f2,testSet,finds))
		{
			testSet.Union(f1, f2);
			unions++;
			finds += 2;
		}
		if (rootCount(testSet) == 1)
			finished = true;
	}
	std::cout << "Days: " << days << std::endl;
	std::cout << "Unions: " << unions << std::endl;
	std::cout << "Finds: " << finds << std::endl;
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
//decides weather or not f1 and f2 are connected. if they are they can not be unioned 
bool canBeMerged(int f1, int f2, unionFind set, int &findCount)
{
	int root1 = set.find(f1);
	int root2 = set.find(f2);
	findCount += 2;
	if (root1 == root2)
		return false;
	else
		return true;
}