#define Friend_H
#ifdef Friend_H
#include <assert.h>
#include <vector>

class Friend
{
public:
	Friend() { parent = -1; };
	int parent;
	int value;
	int id;
	int friendCount() { return friends.size(); };
	std::vector<int> friendsList() { return friends; };
	void connect(int id) 
	{ 
		if (!friends.empty) 
		{ 
			friends.push_back(id); 
		}
		else
		{
			parent = id;
		}
	};
	bool isConnected(int id) {
		if (parent == id)
			return true;
		for (int i = 0; i < friends.size(); i++)
		{
			if (friends.at(i) == id)
				return true;
		}
		return false;
	}
	~Friend() { parent = -1; };

private:
	std::vector<int> friends;
};

#endif // 
