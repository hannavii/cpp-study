#include <iostream>
#include <string>

int main() {
	int hp[5] = { 100,80,50,120,60 };
	for (int i = 0; i < 5; i++) {
		std::cout << hp[i] << '\n';
	}
	std::string item[4] = { "Sword", "Shield", "Potion", "Bow"};
	for (int a = 0; a < 4; a++) {
		std::cout << item[a] << '\n';
	}
	std::string name = "";
	std::cout << "사용자 이름을 입력하세요: " << '\n';
	std::cin >> name;
	std::cout << name+ " " <<name.length() << '\n';
	std::string itemName = "";
	std::cout << "아이템 이름을 입력하세요: " << '\n';
	std::cin >> itemName;
	for (int b = 0; b < 4; b++) {
		if (itemName == item[b]) {
			std::cout << "Item Found!" << '\n';
		}
		else {
			std::cout << "Item Not Found!" << '\n';
		}
	}
}