#include <iostream>
#include <string>
class Item {
public:
    std::string name;
    int price;
    Item(std::string n, int p)
        :name(n), price(p) {
    }
};

class Player {
private:
    int hp;
    std::string name;
    int attack;

public:
    Player(int h)
        : hp(h) {  
    }
    Player(std::string n, int h, int at)
        :name(n), hp(h), attack(at) {
    }
    int getHp() const{
        return hp;
    }
    int getAttack() const {
        return attack;
    }
    void setHp(int sethp) {
        if (sethp < 0) {
            hp = 0;
        }
        else if (sethp > 100) {
            hp = 100;
        }
        else { hp = sethp; }
    }
    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) {
            hp = 0;
        }
    }
};

class Monster {
private:
    std::string name;
    int hp;
    int attack;
public:

    Monster() 
    :name("Slime"), hp(50), attack(15) {
        
    }
    Monster(std::string n, int hp, int at) 
        :name(n), hp(hp), attack(at){
    }
    void showStatus() const{
        std::cout << "Monster: " << name << '\n';
        std::cout<<"HP: "<<hp<<'\n';
        std::cout << "Attack: " << attack << '\n';
    }
    int getHp() const{
        return hp;
    }
    int getAttack() const{
        return attack;
    }
    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) {
            hp = 0;
        }
    }
};
int main()
{
    //문제 1
    Item sword("Sword", 500);
    Item potion("Potion", 100);
    std::cout << "Item: " << sword.name << '\n';
    std::cout << "Price: " << sword.price << '\n';
    std::cout << "Item: " << potion.name << '\n';
    std::cout << "Price: " << potion.price << '\n';
    //문제 2
    Player player(80);
    std::cout << "Initial HP: " << player.getHp() << '\n';
    player.setHp(120);
    std::cout << "After setHp(120): " << player.getHp() << '\n';
    player.setHp(-10);
    std::cout << "After setHp(-10): " << player.getHp() << '\n';
    //문제 3
    Monster Slime;
    Monster Goblin("Goblin", 80, 25);
    Slime.showStatus();
    Goblin.showStatus();
    //문제 4
    Player playerh("Hanna", 100, 20);
    Monster slime("Slime", 50, 15);
    std::cout << "=== Battle Start ===" << '\n';
    std::cout << "Player: Hanna | HP: " << playerh.getHp() << '\n';
    std::cout << "Monster: Slime | HP:" << slime.getHp() << '\n' << '\n';
    std::cout << "Hanna attacks Slime!" << '\n';
    slime.takeDamage(playerh.getAttack());
    std::cout << "Slime HP: " << slime.getHp() << '\n' << '\n';
    std::cout << "Slime counterattacks!" << '\n';
    playerh.takeDamage(slime.getAttack());
    std::cout << "Hanna HP: " << playerh.getHp() << '\n' << '\n';
    std::cout << "=== Battle End ===" << '\n';

    return 0;
}
