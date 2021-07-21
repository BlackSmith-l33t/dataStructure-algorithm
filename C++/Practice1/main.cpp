#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct playList_node
{
	string title;
	playList_node* next;
};

class playList {
public:
	using node = playList_node;
	using node_ptr = node*;

private:
	node_ptr head;

public:
	void next(string title)
	{
		auto new_node = new node{ title, NULL };

	}

};