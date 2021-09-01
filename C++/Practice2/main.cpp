#include <iostream>	
#include <random>

using namespace std;

#define CARD_NUMBER 13


template <typename T>
struct cardList_node
{
	T* card;
	cardList_node* next;
	
	~cardList_node()
	{
		delete card;
	}
};

template <typename T>
struct cardList {
public:
	using node = cardList_node<T>;
	using node_ptr = node*;

private:
	node_ptr firstCard;
	size_t n;

public:
	cardList() : n(0)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 10);

		firstCard = new node{ NULL, NULL };		
		
		for (int i = 0; i < CARD_NUMBER; i++)
		{
			auto new_card = new node{ dist(gen), NULL };
			firstCard->next = new_card;
		}

	}

	size_t size() const
	{
		return n;
	}



};


class Player {
public:
	
private:

public:
	Player()
	{
	
	}

	void GameTable()
	{

	}

	void Shuffle()
	{

	}

	void SelectRandomCard()
	{

	}

	void MatchTest()
	{

	}

	bool IsWinner()
	{
		return false;
	}


};



int main()
{
	Player player;
	
	


}