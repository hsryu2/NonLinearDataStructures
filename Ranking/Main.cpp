#include <iostream>
#include "Container/Tree.h"

int main()
{
	Tree tree;
	int score;
	std::string player;

	FILE* file = nullptr;
	errno_t error = fopen_s(&file, "player.csv", "r+");

	if (file == nullptr)
	{
		std::cout << "Failed to open map file\n";
		return 0;
	}


	fclose(file);
}