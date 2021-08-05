#include <iostream>

using namespace std;

template <typename T>

struct cir_list_node
{
	T* data;
	cir_list_node* next;
	cir_list_node* prev;

	~cir_list_node()
	{
		delete data;
	}
};

template <typename T>
struct cir_list
{
public:
	using node = cir_list_node<T>;
	using node_ptr = node*;

private:
	node_ptr head;
	size_t n;

public:
	cir_list() : n(0)
	{
		head = new node{ NULL, NULL, NULL }; // 모두 NULL로 구성된 기본 노드
		head->next = head;
		head->prev = head;
	}

	size_t size() const
	{
		return n;
	}
	
	void insert(const T& value)
	{
		node_ptr newNode = new node{ new T(value), NULL, NULL };
		n++;
		auto dummy = head->prev;
		dummy->next = newNode;
		newNode->prev = dummy;
		if (head == dummy)
		{
			dummy->prev = newNode;
			newNode->next = dummy;
			head = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	void erase(const T& value)
	{
		auto cur = head, dummy = head->prev;
		while (cur != dummy)
		{
			if (*(cur->data) == value)
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				if (cur == head)
					head = head->next;
				delete cur;
				n--;
				return;
			}
			cur = cur->next;
		}
	}

	struct cir_list_it
	{
	private:
		node_ptr ptr;

	public:
		cir_list_it(node_ptr p) : ptr(p) {}

		T& operator*()
		{
			return *(ptr->data);
		}

		node_ptr get()
		{
			return ptr;
		}

		cir_list_it& operator++()
		{
			ptr = ptr->next;
			return *this;
		}

		cir_list_it operator++(int)
		{
			cir_list_it it = *this;
			++(*this);
			return it;
		}

		cir_list_it& operator--()
		{
			ptr = ptr->prev;
			return *this;
		}

		cir_list_it operator--(int)
		{
			cir_list_it it = *this;
			--(*this); return it;
		}



	};
};



class PlayList {
public:
	using track = PlayList_track;
	using track_ptr = track*;
private:
	track_ptr head;
	track_ptr tail;
	track_ptr play = head;	

public:
	void push_front(string title)
	{
		auto new_track = new track{ title, NULL };
		if (head != NULL)
		{	
			new_track->next = head;
		}

		if (tail == NULL)
		{
			tail = head;
		}
	
		head = new_track;				
	}
	
	string pop_front()
	{
		auto first = head;
		if (head)
		{
			head = head->next;
			tail = head;
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
	PlayList_track_iterator end() { return PlayList_track_iterator(tail); }
	PlayList_track_iterator begin() const { return PlayList_track_iterator(head); }
	PlayList_track_iterator end() const { return PlayList_track_iterator(tail); }

	void insert(track_ptr place, string title)
	{
		auto new_track = new track{ title, NULL };
		if (place != NULL)
		{
			place->next = new_track;
			new_track->prev = place;
		}
	}

	string next()
	{					
		play = head->next;
		
		return play->title;
	}

	string previous()
	{
		play = play->prev;
		
		if (play == head)
		{
			play = tail;
		}
		
		return play->title;
	}

};