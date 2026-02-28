#include <iostream>
#include "Container/Tree.h"


int main()
{
	Tree tree;
	char buffer[100];
	std::string player;

	std::string input;
	std::string name;

	int rank;
	

	FILE* file = nullptr;
	errno_t error = fopen_s(&file, "player.csv", "r+");

	if (file == nullptr)
	{
		std::cout << "Failed to open map file\n";
		return 0;
	}
	std::string str = fgets(buffer, 100, file);

	// 데이터 삽입.
	while (fgets(buffer, 100, file))
	{
		buffer[strcspn(buffer, "\n")] = 0;
		int score;
		char* context = NULL;

		// ,로 파싱.
		std::string name = strtok_s(buffer, ",", &context);
		std::string strScore = strtok_s(NULL, ",", &context);

		// 플레이어 이름과 점수 파싱이 잘 됐으면 string인 score를 int로 형변환.
		if (name != "0" && strScore != "0")
		{
			score = std::stoi(strScore);
		}

		// 이진트리에 삽입.
		tree.Insert(name, score);

	}



	std::cout << "delete [이름] 입력 시 해당 이름이 있으면 삭제합니다. \n";
	std::cout << "top [숫자] 입력 시 해당 수 만큼 랭킹이 출력됩니다.\n";
	std::cout << "find [이름] 입력 시 해당 이름이 있으면 플레이어의 정보가 출력됩니다.\n";
	std::cout << "q 입력시 종료합니다. \n";

	// 검색, 삭제 입력 루프
	while (true)
	{
		std::cin >> input;
		
		if (input == "q")
		{
			break;
		}

		if (input == "delete")
		{
			std::cin >> name;
			tree.DeleteNode(name);
		}
		else if (input == "top")
		{
			std::cin >> rank;
			tree.Top(rank);
		}
		else if (input == "find")
		{
			std::cin >> name;
			tree.Find(name);
		}
		else
		{
			std::cout << "입력이 잘못 됐습니다.\n";
		}

	}

	//tree.Top(10);
	//tree.Find("Starlight_01");
	fclose(file);
}