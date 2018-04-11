#define UNION_FIND
#ifdef UNION_FIND
#include <vector>
#include <assert.h>

class unionFind
{
public:
	unionFind(int listSize) { size = listSize; std::vector<int> tmp(size, -1); theList = tmp; };
	std::vector<int> theList;// the list of all the elements that will be used in the unions
	int size;// size of union items
	int getSize() { return size; };
	// joins the trees of n1 and n2 according to height
	void Union(int n1, int n2) 
	{
		int root1 = find(n1);
		int root2 = find(n2);
		if (theList[root1] < theList[root2])
			theList[root1] = root2;
		else
		{
			if (theList[root1] == theList[root2])
				theList[root1]--;
			theList[root2] = root1;
		}
	};
	//returns the parent of node
	int find(int node)
	{
		if (node < 0)
			return node;
		else { // this section prevents stack overflows from trying to connect to a node you are already connected to
			int loc1 = theList[node];
			int loc2;
			if (loc1 >= 0) 
			{
				loc2 = theList[loc1];
				if (loc1 == loc2)
					return node;
			}
			else
			theList[node] = find(theList[node]);
			return node;
		}
		//return node;
	};
	~unionFind();

private:

};

unionFind::~unionFind()
{
}










#endif // UNION_FIND
