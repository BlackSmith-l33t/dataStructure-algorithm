#include <iostream>	
#include <random>

using namespace std;

#define CARD_NUMBER 13

struct Player
{
public:
	int cardList[CARD_NUMBER];
private:
	size_t n;

public:

	Player() : n(0)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 10);
			
		for (int i = 0; i < CARD_NUMBER; i++)
		{
			cardList[i] = dist(gen);
		}
	}

	size_t size() const
	{
		return n;
	}	

	~Player()
	{
		delete cardList;
	}



};

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


int main()
{
	Player player;

}