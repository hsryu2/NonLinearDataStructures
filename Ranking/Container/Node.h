#pragma once
#include <string>

class Node
{

	friend class Tree;
public:
	Node(const std::string playerName, const int score)
		: playerName(playerName), score(score), parent(nullptr), left(nullptr), right(nullptr)
	{
	}
	Node(const std::string playerName, const int score, Node* parent)
		:playerName(playerName), score(score), parent(parent), left(nullptr), right(nullptr)
	{
	}
	~Node()
	{
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}

private:
	std::string playerName;
	int score;

	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;


};