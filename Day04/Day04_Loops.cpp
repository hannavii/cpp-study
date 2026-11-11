#include <iostream>

int main() {
	for (int i = 1;i<11;i++){
		std::cout << i << "\n";
	}

	for (int a = 1; a <= 20; a++) {
		if (a % 2 == 1) {
			continue;
		}
		std::cout << a << "\n";
	}
	int mhp = 100;
	int at = 0;
	while (mhp > 0) {
		std::cout << "공격력을 입력하세요: " << "\n";
		std::cin >> at;
		mhp -= at;
		std::cout << "남은 체력: " << mhp << "\n";
	}
	std::cout << "Monster Defeated!";
}