#define UNION_FIND
#ifdef UNION_FIND
#include <vector>

class unionFind
{
public:
	unionFind(int listSize) { size = listSize; std::vector<int> tmp(size, -1); theList = tmp; };
	std::vector<int> theList;
	int size;
	int getSize() { return size; };
	void Union(int n1, int n2) 
	{
		int root1 = find(n1);
		int root2 = find(n2);
		if (theList.at(root1) < theList.at(root2))
			theList.at(root1) = root2;
		else
		{
			if (theList.at(root1) == theList.at(root2))
				theList.at(root1)--;
			theList.at(root2) = root1;
		}
	};

	int find(int node)
	{
		if (node < 0)
			return node;
		else {
			theList.at(node) = find(theList.at(node));
		}
	};
	~unionFind();

private:

};

unionFind::~unionFind()
{
}










#endif // UNION_FIND
