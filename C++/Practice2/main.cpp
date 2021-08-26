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
	cardLIst() : n(0)
	{
		firstCard = new node{ NULL, NULL };

	}

	size_t size() const
	{
		return n;
	}



};

class Player {
public:
	using node = cardList_node<T>;
	using node_ptr = node*;
	
private:


public:

	Player()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 10);

		auto new_card = new node{ dist(gen), NULL };
		for (int i = 0; i < CARD_NUMBER; i++)
		{
			node_ptr = dist(gen);
		}
	}

	~Player()
	{
		delete cardList;
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

	void printCard()
	{
		for (int i = 0; i < CARD_NUMBER; i++)
		{
			cout << cardList[i] << endl;
		}
	}

};



int main()
{
	Player player;
	
	player.printCard();


}