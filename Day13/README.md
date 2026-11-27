# Day 13 — Constructor & Encapsulation

## 1. 학습 목표

C++의 생성자(Constructor)와 캡슐화(Encapsulation)를 학습하고, 객체를 초기화하고 내부 데이터를 안전하게 관리하는 방법을 익혔습니다.

DAY 12에서는 `struct`와 `class`를 이용하여 멤버 변수와 멤버 함수를 구현했습니다.

이번 실습에서는 생성자를 이용하여 객체의 초기값을 설정하고, `private`과 `public`을 활용하여 객체의 데이터에 대한 접근을 제어했습니다.

**주요 학습 내용**
- 생성자(Constructor)의 개념과 작성 방법
- 기본 생성자(Default Constructor)
- 매개변수가 있는 생성자
- 생성자 오버로딩(Constructor Overloading)
- 멤버 초기화 리스트(Member Initializer List)
- 캡슐화(Encapsulation)
- `private`과 `public` 접근 지정자
- Getter와 Setter
- `const` 멤버 함수
- 캡슐화를 적용한 객체 간 상호작용

---

## 2. 핵심 개념

### 2.1 생성자(Constructor)

생성자는 객체가 생성될 때 자동으로 호출되는 특별한 멤버 함수입니다.

클래스 이름과 동일한 이름을 사용하며, 반환형을 작성하지 않습니다.

```cpp
class Item {
public:
    std::string name;
    int price;

    Item(std::string n, int p)
        : name(n), price(p) {
    }
};
```

객체를 생성할 때 필요한 초기값을 전달할 수 있습니다.

```cpp
Item sword("Sword", 500);
Item potion("Potion", 100);
```

DAY 12에서는 객체를 생성한 뒤 각 멤버 변수에 값을 대입했지만, 이번에는 생성자를 이용하여 객체 생성과 동시에 초기화했습니다.

### 2.2 멤버 초기화 리스트(Member Initializer List)

생성자에서 멤버 변수를 초기화하는 방법입니다.

```cpp
Item(std::string n, int p)
    : name(n), price(p) {
}
```

`:` 뒤에 멤버 이름과 초기화할 값을 작성합니다.

- `name(n)`: name 멤버를 n으로 초기화
- `price(p)`: price 멤버를 p로 초기화

생성자 본문에서 값을 대입하는 것과 달리, 멤버 초기화 리스트는 멤버 자체를 초기화합니다.

멤버는 초기화 리스트의 작성 순서가 아니라 클래스에서 선언된 순서대로 초기화됩니다.

### 2.3 기본 생성자(Default Constructor)

인수 없이 호출할 수 있는 생성자입니다.

```cpp
Monster()
    : name("Slime"), hp(50), attack(15) {
}
```

다음과 같이 객체를 생성할 수 있습니다.

```cpp
Monster Slime;
```

이 객체는 생성과 동시에 다음 값을 갖습니다.

- name: Slime
- hp: 50
- attack: 15

### 2.4 생성자 오버로딩(Constructor Overloading)

같은 클래스에 매개변수 구성이 다른 생성자를 여러 개 정의하는 것입니다.

```cpp
Monster()
    : name("Slime"), hp(50), attack(15) {
}

Monster(std::string n, int hp, int at)
    : name(n), hp(hp), attack(at) {
}
```

두 생성자는 이름이 같지만 매개변수가 다릅니다.

```cpp
Monster Slime;
Monster Goblin("Goblin", 80, 25);
```

하나의 클래스에서 서로 다른 방식으로 객체를 생성할 수 있습니다.

### 2.5 캡슐화(Encapsulation)

캡슐화는 데이터와 관련 기능을 하나의 객체로 묶고, 외부에서 객체의 내부 상태에 접근하는 방법을 제한하는 설계 방식입니다.

이번 실습에서는 `private` 멤버 변수와 `public` 멤버 함수를 사용하여 구현했습니다.

```cpp
class Player {
private:
    int hp;

public:
    int getHp() const {
        return hp;
    }
};
```

`hp`는 `private`이므로 외부에서 직접 접근할 수 없습니다.

```cpp
player.hp = 100; // 컴파일 오류
```

대신 `public` 멤버 함수인 `getHp()` 등을 이용하여 상태를 확인하거나 변경합니다.

### 2.6 private과 public

| 접근 지정자 | 역할 |
|---|---|
| `private` | 클래스 외부에서 직접 접근할 수 없도록 제한 |
| `public` | 클래스 외부에서 접근할 수 있도록 허용 |

`private`을 이용하면 객체 외부에서 멤버 변수를 임의로 변경하는 것을 제한할 수 있습니다.

다만 실제 데이터의 안전성을 보장하려면 값을 변경하는 함수에서도 올바른 검증이 필요합니다.

### 2.7 Getter와 Setter

Getter는 객체의 값을 읽고, Setter는 객체의 값을 변경하는 데 사용하는 멤버 함수입니다.

**Getter**

```cpp
int getHp() const {
    return hp;
}
```

현재 HP를 반환합니다.

함수 뒤에 붙은 `const`는 해당 멤버 함수가 일반적인 비가변 멤버를 수정하지 않겠다는 의미입니다.

**Setter**

```cpp
void setHp(int sethp) {
    if (sethp < 0) {
        hp = 0;
    }
    else if (sethp > 100) {
        hp = 100;
    }
    else {
        hp = sethp;
    }
}
```

HP를 0~100 범위로 제한합니다.

- 0보다 작으면 0으로 설정
- 100보다 크면 100으로 설정
- 정상 범위라면 입력받은 값으로 설정

이렇게 하면 외부에서 잘못된 값을 전달하더라도 정해진 HP 범위를 유지할 수 있습니다.

---

## 3. 실습 문제

### 실습 1. 생성자를 이용한 아이템 초기화

**문제**

`Item` 클래스를 만들고, 생성자와 멤버 초기화 리스트를 이용하여 아이템의 이름과 가격을 초기화합니다.

**작성 코드**

```cpp
class Item {
public:
    std::string name;
    int price;

    Item(std::string n, int p)
        : name(n), price(p) {
    }
};
```

**객체 생성 및 출력**

```cpp
Item sword("Sword", 500);
Item potion("Potion", 100);

std::cout << "Item: " << sword.name << '\n';
std::cout << "Price: " << sword.price << '\n';

std::cout << "Item: " << potion.name << '\n';
std::cout << "Price: " << potion.price << '\n';
```

**예상 출력**

```text
Item: Sword
Price: 500
Item: Potion
Price: 100
```

**학습 내용**

생성자의 매개변수를 통해 객체의 초기값을 전달했습니다.

멤버 초기화 리스트를 사용하여 객체 생성 시 데이터를 초기화하는 방법을 학습했습니다.

### 실습 2. private과 Getter·Setter

**문제**

`Player` 클래스를 정의하고 HP를 `private`으로 선언하여 외부에서 직접 수정하지 못하도록 보호합니다.

Getter와 Setter를 이용하여 HP를 조회하고 변경합니다.

**작성 코드**

```cpp
class Player {
private:
    int hp;
    std::string name;
    int attack;

public:
    Player(int h)
        : hp(h) {
    }

    int getHp() const {
        return hp;
    }

    void setHp(int sethp) {
        if (sethp < 0) {
            hp = 0;
        }
        else if (sethp > 100) {
            hp = 100;
        }
        else {
            hp = sethp;
        }
    }
};
```

위 코드는 실습 2와 관련된 멤버만 발췌한 코드입니다. 최종 소스 파일의 `Player` 클래스에는 실습 4를 위한 생성자와 멤버 함수도 포함되어 있습니다.

**객체 생성 및 함수 호출**

```cpp
Player player(80);

std::cout << "Initial HP: " << player.getHp() << '\n';

player.setHp(120);

std::cout << "After setHp(120): "
          << player.getHp() << '\n';

player.setHp(-10);

std::cout << "After setHp(-10): "
          << player.getHp() << '\n';
```

**예상 출력**

```text
Initial HP: 80
After setHp(120): 100
After setHp(-10): 0
```

**학습 내용**

`private`으로 선언된 HP를 Getter와 Setter를 통해 관리했습니다.

특히 Setter에서 값의 범위를 확인하여 HP를 0~100 사이로 유지하도록 구현했습니다.

### 실습 3. 생성자 오버로딩

**문제**

`Monster` 클래스에 기본 생성자와 매개변수가 있는 생성자를 구현하여 서로 다른 몬스터 객체를 생성합니다.

**작성 코드**

```cpp
class Monster {
private:
    std::string name;
    int hp;
    int attack;

public:
    Monster()
        : name("Slime"), hp(50), attack(15) {
    }

    Monster(std::string n, int hp, int at)
        : name(n), hp(hp), attack(at) {
    }

    void showStatus() const {
        std::cout << "Monster: " << name << '\n';
        std::cout << "HP: " << hp << '\n';
        std::cout << "Attack: " << attack << '\n';
    }

    int getHp() const {
        return hp;
    }

    int getAttack() const {
        return attack;
    }

    void takeDamage(int damage) {
        hp -= damage;

        if (hp < 0) {
            hp = 0;
        }
    }
};
```

**객체 생성 및 함수 호출**

```cpp
Monster Slime;
Monster Goblin("Goblin", 80, 25);

Slime.showStatus();
Goblin.showStatus();
```

**예상 출력**

```text
Monster: Slime
HP: 50
Attack: 15
Monster: Goblin
HP: 80
Attack: 25
```

**학습 내용**

서로 다른 매개변수를 가진 생성자 두 개를 정의했습니다.

기본 생성자로 생성한 `Slime`은 클래스에 지정된 기본값을 사용하고, `Goblin`은 객체를 생성할 때 전달한 값을 사용합니다.

또한 `showStatus()`에 `const`를 적용하여 객체 정보를 출력하는 함수가 멤버 데이터를 변경하지 않도록 했습니다.

### 실습 4. 캡슐화를 적용한 미니 전투 시스템

**문제**

`Player`와 `Monster` 클래스를 이용하여 `private` 멤버 변수를 직접 변경하지 않고, 멤버 함수를 통해 공격과 반격을 구현합니다.

**Player 클래스의 주요 구현**

```cpp
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
        : name(n), hp(h), attack(at) {
    }

    int getHp() const {
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
        else {
            hp = sethp;
        }
    }

    void takeDamage(int damage) {
        hp -= damage;

        if (hp < 0) {
            hp = 0;
        }
    }
};
```

**전투 구현 코드**

```cpp
Player playerh("Hanna", 100, 20);
Monster slime("Slime", 50, 15);

std::cout << "=== Battle Start ===" << '\n';

std::cout << "Player: Hanna | HP: "
          << playerh.getHp() << '\n';

std::cout << "Monster: Slime | HP:"
          << slime.getHp() << '\n' << '\n';

std::cout << "Hanna attacks Slime!" << '\n';

slime.takeDamage(playerh.getAttack());

std::cout << "Slime HP: "
          << slime.getHp() << '\n' << '\n';

std::cout << "Slime counterattacks!" << '\n';

playerh.takeDamage(slime.getAttack());

std::cout << "Hanna HP: "
          << playerh.getHp() << '\n' << '\n';

std::cout << "=== Battle End ===" << '\n';
```

**예상 출력**

```text
=== Battle Start ===
Player: Hanna | HP: 100
Monster: Slime | HP:50

Hanna attacks Slime!
Slime HP: 30

Slime counterattacks!
Hanna HP: 85

=== Battle End ===
```

**학습 내용**

플레이어와 몬스터의 데이터를 `private` 멤버 변수로 관리했습니다.

공격력과 HP를 가져올 때는 Getter를 사용하고, 데미지를 적용할 때는 `takeDamage()` 멤버 함수를 호출했습니다.

```cpp
slime.takeDamage(playerh.getAttack());
playerh.takeDamage(slime.getAttack());
```

따라서 `main()`에서 각 객체의 HP를 직접 수정하지 않고도 전투를 구현할 수 있었습니다.

---

## 4. 개발 과정에서 발생한 오류와 해결

### 4.1 Setter에서 정상 범위의 값을 처리하지 않은 문제

**초기 코드**

```cpp
void setHp(int sethp) {
    if (sethp < 0) {
        hp = 0;
    }
    else if (sethp > 100) {
        hp = 100;
    }
}
```

**문제**

HP가 0보다 작거나 100보다 큰 상황만 처리했습니다.

따라서 `setHp(50)`처럼 정상 범위의 값을 전달하면 HP가 변경되지 않았습니다.

**해결**

정상 범위의 값을 처리하는 `else`를 추가했습니다.

```cpp
else {
    hp = sethp;
}
```

**배운 점**

조건문을 설계할 때 예외 상황뿐 아니라 정상적인 입력값도 처리해야 한다는 점을 학습했습니다.

### 4.2 HP 계산에서 연산자 우선순위 오류

**초기 코드**

```cpp
void takeDamage(int damage) {
    if (hp -= damage > 0) {
        hp -= damage;
    }
    else {
        hp = 0;
    }
}
```

**문제**

의도는 HP에서 데미지를 뺀 뒤 HP가 0보다 큰지 검사하는 것이었습니다.

그러나 C++에서는 비교 연산자 `>`가 복합 대입 연산자 `-=`보다 우선순위가 높습니다.

따라서 실제로는 다음과 같이 해석됩니다.

```cpp
hp -= (damage > 0)
```

데미지가 양수이면 HP에서 먼저 1이 감소하고, 조건이 참인 경우 데미지가 추가로 감소합니다.

**해결**

HP 감소와 조건 검사를 별도로 작성했습니다.

```cpp
void takeDamage(int damage) {
    hp -= damage;

    if (hp < 0) {
        hp = 0;
    }
}
```

**배운 점**

연산자 우선순위를 고려해야 하며, 계산과 조건 검사를 분리하면 의도하지 않은 값 변경을 방지하기 쉽습니다.

### 4.3 기본 생성자에서 멤버 초기화 리스트를 사용하지 않은 문제

**초기 코드**

```cpp
Monster() {
    name = "Slime";
    hp = 50;
    attack = 15;
}
```

이 코드는 정상적으로 동작하지만, 이번 실습의 목표인 멤버 초기화 리스트를 사용하지 않았습니다.

**수정 코드**

```cpp
Monster()
    : name("Slime"), hp(50), attack(15) {
}
```

**배운 점**

생성자 본문에서 값을 대입하는 방법과 멤버 초기화 리스트를 이용하여 멤버를 초기화하는 방법의 차이를 학습했습니다.

### 4.4 출력 형식 오류

**초기 코드**

```cpp
std::cout << "Item" << sword.name << '\n';
std::cout << "Price" << sword.price << '\n';
```

위 코드는 `ItemSword`, `Price500`처럼 문자열과 값이 붙어서 출력됩니다.

**수정 코드**

```cpp
std::cout << "Item: " << sword.name << '\n';
std::cout << "Price: " << sword.price << '\n';
```

**배운 점**

프로그램의 계산 결과뿐 아니라 출력 형식도 요구사항에 맞게 작성해야 한다는 점을 확인했습니다.

---

## 5. DAY 12와 DAY 13 비교

DAY 12에서는 클래스의 멤버 변수를 `public`으로 선언하고 외부에서 직접 값을 변경했습니다.

```cpp
Monster slime;

slime.hp = 50;
```

DAY 13에서는 생성자로 객체를 초기화하고 `private` 멤버를 멤버 함수로 관리했습니다.

```cpp
Monster slime("Slime", 50, 15);

std::cout << slime.getHp() << '\n';
```

| 구분 | DAY 12 | DAY 13 |
|---|---|---|
| 객체 초기화 | 멤버 변수에 직접 대입 | 생성자 사용 |
| 멤버 변수 | 주로 public | private 활용 |
| 데이터 조회 | 직접 접근 | Getter 사용 |
| 데이터 변경 | 직접 대입 또는 멤버 함수 | Setter 및 멤버 함수 |
| 초기화 방식 | 생성 후 값 설정 | 멤버 초기화 리스트 |
| 주요 학습 목표 | 구조체와 클래스 기초 | 객체 초기화 및 캡슐화 |

이번 실습을 통해 객체의 데이터를 단순히 묶는 것에서 나아가, 초기화와 접근 방법까지 설계하는 방법을 학습했습니다.

---

## 6. 이번 실습에서 배운 점

### 6.1 생성자로 객체의 초기 상태를 설정할 수 있다

객체를 생성할 때 이름과 HP, 공격력을 전달하여 초기값을 설정했습니다.

초기화를 객체 생성 과정에 포함하면 여러 객체를 생성할 때 반복적인 대입 코드를 줄일 수 있습니다.

### 6.2 생성자 오버로딩으로 다양한 생성 방식을 제공할 수 있다

같은 클래스에서 기본 생성자와 매개변수가 있는 생성자를 구현했습니다.

이를 통해 기본 몬스터와 서로 다른 능력치를 가진 몬스터를 생성할 수 있었습니다.

### 6.3 private과 public으로 데이터 접근을 제어할 수 있다

HP와 공격력을 `private`으로 선언하여 외부에서 직접 접근하지 못하도록 했습니다.

대신 `public` 멤버 함수를 통해 필요한 값을 조회하고 수정했습니다.

### 6.4 Getter와 Setter는 역할이 다르다

Getter는 데이터를 읽고, Setter는 데이터를 변경합니다.

특히 Setter에서 값을 검증하면 의도한 범위 내에서 객체의 상태를 관리할 수 있습니다.

### 6.5 객체 간 상호작용을 캡슐화된 방식으로 구현할 수 있다

전투 과정에서 객체의 HP에 직접 접근하지 않고 Getter와 `takeDamage()`를 이용했습니다.

객체가 자신의 상태를 직접 관리하는 방식의 기초를 실습했습니다.

---

## 7. 추가 개선 사항

이번 실습은 요구된 기능을 구현했으며, 추후 개선할 수 있는 부분도 확인했습니다.

### 7.1 Player 생성자의 멤버 초기화

현재 한 개의 정수를 받는 생성자는 다음과 같습니다.

```cpp
Player(int h)
    : hp(h) {
}
```

이 생성자를 사용하면 `hp`는 초기화되지만, `attack`은 초기화되지 않습니다. `name`은 빈 문자열로 기본 생성됩니다.

추후에는 사용되지 않는 멤버에도 적절한 초기값을 설정하여 안전성을 높일 수 있습니다.

### 7.2 초기화 리스트의 작성 순서

`Player` 클래스의 멤버 선언 순서는 `hp`, `name`, `attack`입니다.

현재 매개변수가 세 개인 생성자의 초기화 리스트는 `name`, `hp`, `attack` 순서입니다.

실제 초기화 순서는 멤버 선언 순서를 따르므로, 초기화 리스트도 동일한 순서로 작성하면 가독성을 높일 수 있습니다.

### 7.3 플레이어 및 몬스터 이름 출력

실습 4에서는 `Hanna`, `Slime`이라는 이름을 출력문에 직접 작성했습니다.

추후 `getName()`과 같은 멤버 함수를 추가하면 객체에 저장된 이름을 출력하도록 개선할 수 있습니다.

### 7.4 생성자와 데미지 함수의 입력값 검증

현재 Getter·Setter를 통한 HP 변경과 데미지 차감의 기본 동작을 구현했습니다.

향후에는 생성자에서 전달받은 잘못된 HP나 음수 데미지 등도 검증하여, 객체가 항상 유효한 상태를 유지하도록 개선할 수 있습니다.

---

## 8. 향후 학습 계획

- 헤더 파일(`.h`)과 소스 파일(`.cpp`) 분리
- 클래스 선언과 멤버 함수 정의 분리
- 상속(Inheritance)과 가상 함수(Virtual Function)
- 클래스 기반 Text Battle Game v2 구현
- 객체지향 설계를 활용한 게임 시스템 확장

---

## 9. 파일 구성

```text
Day13/
├── Day13_ConstructorEncapsulation.cpp
└── README.md
```

- `Day13_ConstructorEncapsulation.cpp`: 생성자와 캡슐화 실습 코드
- `README.md`: 학습 내용, 실습 과정 및 오류 수정 기록

---
