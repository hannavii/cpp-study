#include <iostream>
#include <random>
#include <string>
#include <vector>
int usePotion( int playerHp, int playerHpMax,int heal) {
	std::cout << "포션을 사용했습니다." << '\n';
	if (playerHp + heal <= playerHpMax) {
		std::cout << "Player HP: " << playerHp + heal << '\n';
		playerHp += heal;
	}
	else {
		std::cout << "Player HP: " << playerHpMax << '\n';
		playerHp = playerHpMax;
	}
	return playerHp;
}
int attack(int c, int playerAt, int monsterHp) {
	if (c <= 20) {
		std::cout << "Critical Hit!" << '\n';
		std::cout << "공격 데미지: " << playerAt * 2 << '\n';
		monsterHp -= playerAt * 2;
	}
	else {
		std::cout << "공격 데미지: " << playerAt << '\n';
		monsterHp -= playerAt;
	}
	return monsterHp;
}

int main() {
	std::string playerName;
	std::cout << "플레이어 이름을 입력하세요: " << '\n';
	std::cin >> playerName;
	int playerHp = 100;
	int playerHpMax = 100;
	int monsterHp = 100;
	std::vector<int> potion = { 1,2,3 };
	int heal = 30;
	int turn = 1;
	int playerSelect = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> playerAttack(10, 30);
	std::uniform_int_distribution<int> monsterAttack(5, 15);
	std::uniform_int_distribution<int> criticalPer(1,100);
	bool running = true;
	while (monsterHp>0&&playerHp>0&&running==true) {
		std::cout << "========== TURN" << turn << " ==========" << '\n';
		std::cout << "Player HP: " << playerHp << '\n';
		std::cout << "Monster HP: " << monsterHp << '\n';
		std::cout << "Potion: " << potion.size() << '\n' << '\n';
		std::cout << "1. Attack" << '\n';
		std::cout << "2. Use Potion" << '\n';
		std::cout << "3. Escape" << '\n' << '\n';
		std::cout << "Select: ";
		std::cin >> playerSelect;
		int playerAt = playerAttack(gen);
		int monsterAt = monsterAttack(gen);
		switch (playerSelect) {
		case 1: {
			int c = criticalPer(gen);
			monsterHp=attack( c, playerAt, monsterHp);
			if (monsterHp < 0) {
				monsterHp = 0;
			}
			std::cout << "몬스터 남은 HP: " << monsterHp << '\n';
			if (monsterHp > 0) {
				std::cout << "몬스터의 반격: " << monsterAt << '\n';
				playerHp -= monsterAt;
				if (playerHp < 0) {
					playerHp = 0;
				}
			}
			turn++;
			break;
		}
		case 2: {
			if (potion.size() > 0) {
				playerHp=usePotion(playerHp,playerHpMax,heal);
				if (monsterHp > 0) {
					std::cout << "몬스터의 반격: " << monsterAt << '\n';
					playerHp -= monsterAt;
				}
				if (playerHp < 0) {
					playerHp = 0;
				}
				potion.pop_back();
				turn++;
			}
			else {
				std::cout << "포션을 사용할 수 없습니다."; }
			break;
		}
		case 3: {
			running = false;
			break;
		}
		default: {
			std::cout << "잘못된 선택지입니다. 다시 입력해주세요: " << '\n';
			break;
		}
		}
	}
	if (running == false) {
		std::cout << "Escaped!" << '\n';
	}
	else if (running == true && monsterHp <= 0) {
		std::cout << "Victory!" << '\n';
	}
	else if(running == true && monsterHp > 0) {
		std::cout << "Defeat!" << '\n';
	}
}