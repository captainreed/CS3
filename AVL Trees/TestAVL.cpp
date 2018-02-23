#include "AvlTree.h"
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
	AvlTree<int> t;
	for (int i=1; i < 30; i=i+3)
	     t.insert(i);
	t.insert(7);

	t.printTree();
	t.removeMin();
	t.printTree();

	//test the avltree framework using the tests given in the homework
	AvlTree<int> tester;
	int list[] = {1,3,5,7,9,11,2,4,8};
	
	for (int i = 0; i < 9; i++)
	{
		tester.insert(list[i]);
	}
	tester.printTree();
	tester.remove(7);
	tester.remove(9);
	tester.printTree();

	tester.insert(50);
	tester.insert(30);
	tester.insert(15);
	tester.insert(18);
	tester.printTree();

	tester.removeMin();
	tester.printTree();

	tester.removeMin();
	tester.printTree();

	tester.removeMin();
	tester.printTree();

	tester.insert(17);
	tester.printTree();
	
	std::cout << std::endl << t.findMin() << std::endl;
	std::cout << t.findMax() << std::endl;
	int check = 23;
	if (!t.contains(check))
		std::cout << check << " ITEM_NOT_FOUND failed!" << std::endl;
	
	std::string name = "this";

	AvlTree<std::string> words;
	words.insert("help");
	words.insert("me");
	words.insert("please");
	words.insert("I");
	words.insert("said");
	words.insert("help");
	words.insert("me");
	words.insert("please");
	words.printTree();

	char p;
	std::cin >> p;

	//return 0;
	
	std::string answer;
	std::cin >> answer;
}
