#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<std::string> items = { "Sword", "Shield", "Potion" };
	for (int i = 0; i < items.size(); i++) {
		std::cout << items[i] << '\n';
	}
	items.push_back("Bow");
	items.pop_back();
	for (const std::string& item : items) {
		std::cout << item << '\n';
	}
	std::cout << items.size() << '\n';
	for (auto it = items.begin(); it != items.end(); ++it) {
		std::cout << *it << '\n';
	}
	std::string playerItem;
	std::cout << "아이템 이름을 입력하세요: " << '\n';
	std::cin >> playerItem;
	bool Item = false;
	for (int a = 0; a < items.size(); a++) {
		if (playerItem == items[a]) {
			Item = true;
			break;
		}
	}
	if (Item) {
		std::cout << "Item Found!\n";
	}
	else {
		std::cout << "Item not Found!\n";
	}
	return 0;
}