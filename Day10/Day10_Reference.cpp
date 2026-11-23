#include <iostream>
#include <string>

void takeDamage(int& hp, int damage) {
    hp -= damage;
}
void showPlayer(const std::string& name, const int& hp) {
    std::cout << "Player Name: " << name << '\n';
    std::cout << "HP: " << hp << '\n';
}
void healPlayer(int& hp, int amount, int maxHp) {
    hp += amount;
    if (hp > maxHp) {
        hp = maxHp;
    }
}

int main()
{
    //문제 1
    int a = 10;
    int b = a;
    int& c = a;
    b = 20;
    c = 30;
    std::cout << a << b << c << '\n';
    //문제 2
    int hp = 100;
    int damage = 25;
    takeDamage(hp,damage);
    std::cout << "Player Hp: "<< hp << '\n';
    //문제 3
    hp = 100;
    std::string playerName = "Hanna";
    showPlayer(playerName, hp);
    //문제 4
    hp = 80;
    int heal = 30;
    int playerHpMax = 100;
    std::cout << "Before Heal: " << hp << '\n';
    healPlayer(hp, heal, playerHpMax);
    std::cout << "After Heal: " << hp << '\n';
}
