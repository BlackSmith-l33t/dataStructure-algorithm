#include <iostream>
#include <algorithm>

using namespace std;

struct playList_track
{
	string title;
	playList_track* next;
};

class playList {
public:
	using track = playList_track;
	using track_ptr = track*;
private:
	track_ptr head;

public:
	void push_front(string title)
	{
		auto new_track = new track{ title, NULL };
		if (head != NULL)
		{	
			new_track->next = head;
		}
		head = new_track;		
	}
	void pop_front()
	{
		auto first = head;
		if (head)
		{
			head = head->next;
			delete first;
		}
	}






	void next(string title)
	{
		auto new_node = new node{ title, NULL };

	}

};