#pragma once
#include "../Container/Node.h"

class Tree
{
public:
	Tree()
		: root(nullptr)
	{
	}
	~Tree()
	{

	}

	// »ðÀÔ
	bool Insert(const std::string name, const int score)
	{
		if (Search(score, name))
		{
			return false;
		}
		if (root == nullptr)
		{
			root = new Node(name, score);
			return true;
		}

	}

	// Å½»ö
	bool Search(const int score, const std::string name)
	{
		return searchReursive(root,score, name);
	}

	Node* SearchMinValue(Node* node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}

		return node;
	}

	// Å½»ö Àç±ÍÇÔ¼ö.
	bool searchReursive(Node* node, const int score, const std::string name)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (node-> playerName == name && node->score == score)
		{
			return true;
		}

		if (node->left->score > score && node->playerName != name)
		{
			searchReursive(node->left, score, name);
		}

		else
		{
			searchReursive(node->right, score, name);
		}
	}

	void DeleteNode(const std::string name, const int score)
	{
		DeleteNodeRecursive(root, name, score);
	}

	
private:
	// »èÁ¦ Àç±ÍÇÔ¼ö.
	Node* DeleteNodeRecursive(Node* node, 
		const std::string name, const int score)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (node->left->score > score && node->left->playerName != name)
		{
			node->left = DeleteNodeRecursive(node->left, name, score);
		}
		else if (node->right->score > score && node->right->playerName != name)
		{
			node->right = DeleteNodeRecursive(node->right, name, score);
		}
		else
		{
			if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
				return nullptr;
			}
			if (node->left != nullptr && node->right != nullptr)
			{
				node->score = SearchMinValue(node->right)->score;
				
				node->right = DeleteNodeRecursive(
					node->right, node->playerName, node->score);
			
			}

			else
			{
				if (node->left == nullptr)
				{
					Node* right = node->right;

					right->parent = node->parent;

					delete node;

					return right;
				}

				else if (node->right == nullptr)
				{
					Node* left = node->left;

					left->parent = node->parent;

					delete node;

					return left;
				}
			}

		}

		return node;

	}


	// »ðÀÔ Àç±ÍÇÔ¼ö.
	Node* InsertRecursive(
		Node* node,
		Node* parent,
		const std::string name,
		const int score)
	{
		if (node == nullptr)
		{
			return new Node(name, score, parent);
		}

		if (node->score > score)
		{
			node->left = InsertRecursive(node->left, node, name, score);
		}
		else
		{
			node->right = InsertRecursive(node->right, node, name, score);
		}

		return node;
	}

private:

	Node* root;

};