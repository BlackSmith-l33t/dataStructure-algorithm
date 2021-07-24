#include <iostream>
#include <algorithm>
#include <forward_list>
#include <list>	

using namespace std;

struct PlayList_track
{
	string title;
	PlayList_track* next;	
};

class PlayList {
public:
	using track = PlayList_track;
	using track_ptr = track*;
private:
	track_ptr head;
	track_ptr tail;

public:
	void push_front(string title)
	{
		auto new_track = new track{ title, NULL };
		if (head != NULL)
		{	
			new_track->next = head;
		}
		head = new_track;	


		if (tail == NULL)
		{
			tail = head;
		}
		else
		{
			new_track->next = head;
		}	
	}
	string pop_front()
	{
		auto first = head;
		if (head)
		{
			head = head->next;
			delete first;
		}

		return head->title;
	}
	
	struct PlayList_track_iterator
	{
	private:
		track_ptr ptr;
	
	public:
		PlayList_track_iterator(track_ptr p) : ptr(p) {}

		string& operator*() { return ptr->title; }

		track_ptr get() { return ptr; }

		PlayList_track_iterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}

		PlayList_track_iterator operator++(int)
		{
			PlayList_track_iterator result = *this;
			return *this;
		}

		friend bool operator==(const PlayList_track_iterator& left, const PlayList_track_iterator& right)
		{
			return left.ptr == right.ptr;
		}

		friend bool operator!=(const PlayList_track_iterator& left, const PlayList_track_iterator& right)
		{
			return left.ptr != right.ptr;
		}
	};
	
	PlayList_track_iterator begin() { return PlayList_track_iterator(head); }
	PlayList_track_iterator end() { return PlayList_track_iterator(?); }
	PlayList_track_iterator begin() const { return PlayList_track_iterator(head); }
	PlayList_track_iterator end() const { return PlayList_track_iterator(?); }


	





	void next(string title)
	{
		auto new_node = new node{ title, NULL };

	}

};