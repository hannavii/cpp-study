#include <iostream>

void greet() {
	std::cout << "Hello Player!" << '\n';
}
void attack(int damage) {
	std::cout << "Damage: " << damage<< '\n';
}
int calculateDamage(int attack, int defense) {
	int result = attack - defense;
	return result;
}

int heal(int hp, int amount) {
	int re = hp + amount;
	return re;
}
int main() {
	greet();
	greet();
	greet();
	attack(20);
	attack(35);
	std::cout << "Damage: " << calculateDamage(50, 15) << '\n';
	std::cout << "HP: " << heal(50, 30) << '\n';
}