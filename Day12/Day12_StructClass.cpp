#include <iostream>
#include <string>

struct Item {
	std::string name;
	int price;
	int quantity;
};

struct Player {
	std::string name;
	int hp;
	int attack;
	void showStatus() {
		std::cout << "Name: " << name << '\n';
		std::cout << "HP: " << hp << '\n';
	}
	void takeDamage(int damage) {
		hp -= damage;
		if (hp< 0) {
			hp = 0;
		}
	}
};

class Monster {
	public:
	std::string name;
	int hp;
	int attack;

	void showStatus() {
		std::cout << "Monster: " << name << '\n';
		std::cout << "HP: " << hp << '\n';
	}
	void takeDamage(int damage) {
		std::cout << name << " takes " << damage << " damage!" << '\n';
		hp -= damage;
		if (hp < 0) {
			hp = 0;
		}
	}
};
int main()
{
	//문제 1
	Item sword;
	Item potion;
	sword.name = "Sword";
	sword.price = 500;
	sword.quantity = 1;
	potion.name = "Potion";
	potion.price = 100;
	potion.quantity = 3;
	std::cout << "Item: " << sword.name << '\n';
	std::cout << "Price: " << sword.price << '\n';
	std::cout << "Quantity: " << sword.quantity << '\n';
	std::cout << "Item: " << potion.name << '\n';
	std::cout << "Price: " << potion.price << '\n';
	std::cout << "Quantity: " << potion.quantity << '\n';
	//문제 2
	Player player;
	player.name = "Hanna";
	player.hp = 100;
	player.showStatus();
	player.takeDamage(25);
	player.showStatus();
	//문제 3
	Monster slime;
	slime.name = "Slime";
	slime.hp = 50;
	slime.showStatus();
	slime.takeDamage(20);
	slime.showStatus();
	//문제 4
	std::cout << "=== Battle Start ===" << '\n';
	player.hp = 100;
	slime.hp = 50;
	player.showStatus();
	slime.showStatus();
	player.attack = 20;
	slime.attack = 15;
	std::cout << "Hanna attacks Slime!" << '\n';
	slime.takeDamage(player.attack);
	std::cout << "Slime HP: " << slime.hp << '\n';
	std::cout << "Slime counterattacks!" << '\n';
	player.takeDamage(slime.attack);
	std::cout << "Hanna HP: " << player.hp << '\n';
	std::cout << "=== Battle End ===" << '\n';
}
