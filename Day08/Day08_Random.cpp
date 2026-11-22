#include <iostream>
#include <random>
#include <string>

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 6);

	for (int i = 0; i < 5; i++) {
		int num = dist(gen);
		std::cout << num << '\n';
	}
	std::uniform_int_distribution<int> dam(10, 30);
	int monHp = 100;
	int attackDamage = dam(gen);
	std::cout << "공격 데미지: " << attackDamage << '\n';
	std::cout << "남은 Hp" << monHp - attackDamage << '\n';
	int normalAttack = 20;
	std::string attackPower = "Normal Hit";
	std::uniform_int_distribution<int> attackPer(1, 100);
	if (attackPer(gen) <= 20) {
		normalAttack *= 2;
		attackPower = "Critical Hit";
	}
	std::cout << "공격 종류: " << attackPower << '\n';
	std::cout << "데미지: " << normalAttack << '\n';
	int a = 0;
	while (monHp> 0) {
		attackDamage=dam(gen);
		monHp -= attackDamage;
		std::cout << "공격 데미지: " << attackDamage << '\n';
		std::cout << "남은 HP" << monHp << '\n';
		a += 1;
	}
	std::cout << "총 공격횟수: " << a << '\n';
	std::cout << "Monster Defeat!\n";
}