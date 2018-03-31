#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>     
#include <time.h> 
#include <cassert>
#include "HashTable.h"
#include "WordList.h"

void clean(std::string & nextString);
std::string writePoem(int length, std::string first, HashTable<std::string, FirstWord> table);
HashTable<std::string, FirstWord> populateHash(std::string file);
//the main function contains all the instances of the poem functions that were outlined int the assignment
int main()
{
	
	//create a hashtable for the given poem
	HashTable<std::string, FirstWord> greenTable;
	//populate the hash table with the words from the file
	greenTable = populateHash("../green.txt");
	//output the hashtable to the console
	std::cout << greenTable.toString(1000);
	//start with an initial word and then write a poem with a given size
	std::cout <<writePoem(20, "sam",greenTable)<<std::endl;
	//put space between the poems
	std::cout << "\n" << std::endl;

	HashTable<std::string, FirstWord> clownTable;
	clownTable = populateHash("../clown.txt");
	std::cout << clownTable.toString(1000);
	//start with an initial word and then write a poem with a given size
	std::cout << writePoem(20, "go", clownTable) << std::endl;
	std::cout << "\n" << std::endl;

	HashTable<std::string, FirstWord> inchTable;
	inchTable = populateHash("../inch.txt");
	std::cout << writePoem(50, "computer", inchTable) << std::endl;
	std::cout << "\n" << std::endl;

	HashTable<std::string, FirstWord> poeTable;
	poeTable = populateHash("../poe.txt");
	std::cout << writePoem(50, "nevermore", poeTable) << std::endl;
	std::cout << "\n" << std::endl;

	HashTable<std::string, FirstWord> seussTable;
	seussTable = populateHash("../seuss.txt");
	std::cout << writePoem(50, "mordecai", seussTable) << std::endl;
	std::cout << "\n" << std::endl;

	//std::ofstream outputfile("results.txt", std::ofstream::out);
	//outputfile << results;
	//outputfile.close();
	
		//leave the console open so that the output can be observed
	std::string answer;
	std::cin >> answer;
	return 0;
}

//writes a random poem using the algorythm outlined in the assignment
std::string writePoem(int length, std::string first, HashTable<std::string, FirstWord> table)
{
	clean(first);//clean the word just in case
	srand((unsigned int)time(0));//create a random object
	std::stringstream thepoem;
	std::string currentWord = first;
	thepoem << currentWord<< " ";//add the poem to the string as it occures
	for (int i = 0; i < length; i++)
	{
		int secondlistSize = table.find(currentWord)->secondaryList.size();//find out the size of the number of objects that are conected to the word
		int randWord = rand() % secondlistSize + 1;//decide which word to use next
		if (randWord >= secondlistSize)
		{
			currentWord = table.find(currentWord)->secondaryList.at(0)->word;
		}
		else {
			currentWord = table.find(currentWord)->secondaryList.at(randWord)->word;
		}
		thepoem << currentWord << " ";		//add to the poem
	}
	return thepoem.str();
}



void clean(std::string & nextString)
{
	for (int i = 0; i < nextString.length();)
	{
		if (nextString[i] >255 || nextString[i] < 0 || ispunct(nextString[i]))
			nextString.erase(i, 1);
		else {
			nextString[i] = tolower(nextString[i]);
			i++;
		}
	}
}

HashTable<std::string, FirstWord> populateHash(std::string file)
{

	HashTable<std::string, FirstWord> theTable;
	//inport poem from file
	std::string nextWord;
	std::string prevWord = "";

	std::fstream poem;
	poem.open(file);
	assert(poem.good());
	while (poem >> nextWord)
	{
		clean(nextWord);
		if (prevWord != "")
			theTable.find(prevWord)->addNextWord(nextWord);
		//add all the words to the hash
		FirstWord *location = theTable.find(nextWord);
		if (location != NULL)
		{
			location->incrementCount();
		}
		else
		{
			FirstWord *newWord = new FirstWord(nextWord, 1);
			theTable.insert(nextWord, newWord);
		}
		prevWord = nextWord;
	}

	return theTable;
}
