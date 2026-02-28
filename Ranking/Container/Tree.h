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
		Destroy();
	}

	// »ðÀÔ
	bool Insert(const std::string& name, const int& score)
	{

		Node* outNode = nullptr;
		if (Search(score, name, outNode))
		{
			return false;
		}
		if (root == nullptr)
		{
			root = new Node(name, score);
			return true;
		}
		root = InsertRecursive(root, nullptr, name, score);
		return true;
	}

	// Å½»ö
	bool Search(const int& score, const std::string& name, Node*& outNode)
	{
		return searchRecursive(root,score, name, outNode);
	}

	Node* SearchMinValue(Node* node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}

		return node;
	}



	void DeleteNode(const std::string& name)
	{
		DeleteNodeRecursive(root, name);
	}

	void Top(int k)
	{
		// ÁßÀ§ ¼øÈ¸.
		TopRecursive(root, k);
		
	}
	void Find(const std::string& name)
	{
		Node* node = root;

		if (findRecursive(root, name, node))
		{
			std::cout << "°Ë»ö ¼º°ø!\n " << node->playerName << " " << node->score << "\n";
		}
		else
		{
			std::cout << "°Ë»ö ½ÇÆÐ.";
		}
	}


private:
	// »èÁ¦ Àç±ÍÇÔ¼ö.
	Node* DeleteNodeRecursive(Node* node, 
		const std::string name)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (node->left->playerName != name)
		{
			node->left = DeleteNodeRecursive(node->left, name);
		}
		else if (node->right->playerName != name)
		{
			node->right = DeleteNodeRecursive(node->right, name);
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
					node->right, node->playerName);
			
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

	// Å½»ö Àç±ÍÇÔ¼ö.
	bool searchRecursive(Node* node, const int& score, const std::string& name, Node*& outNode)
	{
		if (!node)
		{
			outNode = nullptr;
			return false;
		}

		if (node->playerName == name && node->score == score)
		{
			outNode = node;
			return true;
		}

		if (node->score > score && node->playerName != name)
		{

			searchRecursive(node->left, score, name, outNode);
		}

		else
		{
			searchRecursive(node->right, score, name, outNode);
		}
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

	void Destroy()
	{
		if (!root)
		{
			return;
		}

		DestroyRecursive(root);
	}

	void DestroyRecursive(Node* node)
	{
		if (!node)
		{
			return;
		}

		if (!node->left && !node->right)
		{
			delete node;
			return;
		}
		
		DestroyRecursive(node->right);
		DestroyRecursive(node->left);

		delete node;
	}
	void TopRecursive(Node* node, int& k)
	{
		if (!node || k <= 0)
		{
			return;
		}
		k--;
		TopRecursive(node->right, k);
		std::cout << node->playerName << ", " << node->score << "\n";
		TopRecursive(node->left, k);

	}

	bool findRecursive(Node* node, const std::string& name, Node*& outNode)
	{
		if (!node)
		{
			outNode = nullptr;
			return false;
		}

		if (node->playerName == name)
		{
			outNode = node;
			return true;
		}

		findRecursive(node->left, name, outNode);
		findRecursive(node->right, name, outNode);
	}
private:
	int rank = 0;
	Node* root;

};