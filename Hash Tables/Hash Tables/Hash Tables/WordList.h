#ifndef Word_List_H
#define Word_List_H

#include <vector>
#include <string>

class NextWord
{
public:
	std::string word;
	int count;
	std::string toString()
	{
		std::stringstream ss;
		ss << word << " " << count;
		return ss.str();
	};
	NextWord(std::string s, int c)
	{
		word = s;
		count = c;
	};
	void increment() { count++; }
};

class FirstWord
{
	std::string word;
	int count;
public:
	std::vector<NextWord*> secondaryList;
	int getCount() { return count; };

	std::string toString()
	{
		//std::string wholestring = word;

		std::stringstream ss;
		ss << word << " " << count;
		
		for (int i = 0; i<secondaryList.size(); i++)
		{
			ss << " " << secondaryList.at(i)->toString();
		}
		return ss.str();
	};
	FirstWord(std::string s, int c)
	{
		word = s;
		count = c;
	};
	void addNextWord(std::string w)
	{
		bool redundant = false;
		NextWord *nxt = new NextWord(w, 1);
		for (int i = 0; i<secondaryList.size(); i++)
		{
			if (w == secondaryList.at(i)->word)
			{
				redundant = true;
				secondaryList.at(i)->increment();
			}
		}
		if (!redundant)
		{
			secondaryList.push_back(nxt);
		}
	};
	void incrementCount() { count++; }
};




#endif
