#include <iostream>

int main() {
	int hp = 0;
	std::cout << "플레이어 hp를 입력하세요: " << "\n";
	std::cin >> hp;

	if (hp <= 0) {
		std::cout << "Dead\n";
	}
	else if (hp >= 1 && hp <= 30) {
		std::cout << "Danger\n";
	}
	else if (hp >= 31) {
		std::cout << "Healthy\n";
	}
	int mp = 0;
	std::cout << "MP를 입력하세요: " << "\n";
	std::cin >> mp;
	if (mp >= 10) {
		std::cout << "Skill Available" << "\n";
	}
	else if (mp < 10){
		std::cout << "Not Enough MP:" << "\n";
		}
	int menu = 2;
	switch (menu) {
	case 1:
		std::cout << "Start" << "\n";
		break;
	case 2:
		std::cout << "Load" << "\n";
		break;
	case 3:
		std::cout << "Exit" << "\n";
		break;
	default:
		std::cout << "Invalid" << "\n";
		break;
	}
	int mhp = 100;
	int dm = 0;
	std::cout << "몬스터에게 입힐 데미지를 입력하세요" << "\n";
	std::cin >> dm;
	mhp -= dm;
	if (mhp <= 0) {
		std::cout << "Monster Defeated" << "\n";
	}
	else {
		std::cout << "Monster Survived: " << mhp << "\n";
	}
}