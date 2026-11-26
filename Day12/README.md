# Day 12 — Struct & Class

## 1. 학습 목표

C++의 구조체(`struct`)와 클래스(`class`)를 학습하고, 서로 관련된 데이터와 함수를 하나의 객체로 관리하는 방법을 익혔습니다.

DAY 09에서는 플레이어와 몬스터의 HP, 공격력 등을 개별 변수로 관리하고 외부 함수를 이용해 전투를 구현했습니다.

이번 실습에서는 구조체와 클래스를 정의하고, 객체의 멤버 함수를 이용하여 전투 로직을 구현했습니다.

**주요 학습 내용**
- `struct`와 `class`의 개념 및 차이
- 사용자 정의 자료형 만들기
- 객체(Object) 생성 및 활용
- 멤버 변수(Member Variable)
- 멤버 함수(Member Function)
- 멤버 접근 연산자 `.`
- `public`과 `private`의 기초 개념
- 객체 간 상호작용을 이용한 전투 구현

---

## 2. 핵심 개념

### 2.1 구조체(struct)

구조체는 서로 관련된 여러 데이터를 하나의 사용자 정의 자료형으로 묶는 기능입니다.

```cpp
struct Item {
    std::string name;
    int price;
    int quantity;
};
```

`Item` 구조체에는 아이템의 이름, 가격, 수량을 저장하는 세 개의 멤버 변수가 있습니다.

구조체를 정의한 후에는 해당 자료형의 객체를 생성할 수 있습니다.

```cpp
Item sword;

sword.name = "Sword";
sword.price = 500;
sword.quantity = 1;
```

`Item`은 자료형이고, `sword`는 그 자료형으로 생성한 객체입니다.

### 2.2 객체(Object)

객체는 구조체나 클래스와 같은 자료형을 이용해 생성한 실제 데이터입니다.

```cpp
Item sword;
Item potion;
```

두 객체는 같은 `Item` 자료형을 사용하지만 서로 독립적인 멤버 데이터를 가집니다.

따라서 `sword.price`를 변경해도 `potion.price`는 변경되지 않습니다.

### 2.3 멤버 변수와 멤버 함수

멤버 변수는 객체에 속한 데이터를 저장하고, 멤버 함수는 객체와 관련된 작업을 수행합니다.

```cpp
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

        if (hp < 0) {
            hp = 0;
        }
    }
};
```

`name`, `hp`, `attack`은 멤버 변수입니다.

`showStatus()`와 `takeDamage()`는 멤버 함수입니다.

멤버 함수에서는 해당 객체의 멤버 변수에 직접 접근할 수 있습니다.

### 2.4 멤버 접근 연산자(.)

객체의 멤버 변수나 멤버 함수에 접근할 때 `.` 연산자를 사용합니다.

```cpp
Player player;

player.name = "Hanna";
player.hp = 100;

player.showStatus();
player.takeDamage(25);
```

- `player.name`: 객체의 이름 멤버에 접근
- `player.hp`: 객체의 HP 멤버에 접근
- `player.showStatus()`: 객체의 멤버 함수 호출
- `player.takeDamage(25)`: 객체의 HP를 감소시키는 멤버 함수 호출

### 2.5 클래스(class)

클래스도 구조체처럼 데이터와 함수를 하나의 자료형으로 묶을 수 있습니다.

```cpp
class Monster {
public:
    std::string name;
    int hp;
    int attack;

    void showStatus() {
        std::cout << "Monster: " << name << '\n';
        std::cout << "HP: " << hp << '\n';
    }
};
```

클래스의 멤버는 기본적으로 `private`이므로, 외부에서 접근할 수 있도록 `public:`을 지정했습니다.

### 2.6 struct와 class의 차이

C++에서 구조체와 클래스는 대부분의 기능을 동일하게 사용할 수 있습니다.

가장 기본적인 차이는 접근 권한의 기본값입니다.

| 구분 | struct | class |
|---|---|---|
| 기본 멤버 접근 권한 | public | private |
| 멤버 변수 | 사용 가능 | 사용 가능 |
| 멤버 함수 | 사용 가능 | 사용 가능 |
| 객체 생성 | 가능 | 가능 |
| 상속 | 가능 | 가능 |
| 접근 권한 지정 | 가능 | 가능 |

`public`은 클래스 외부에서 접근할 수 있는 멤버를 의미합니다.

`private`은 클래스 외부에서 직접 접근할 수 없는 멤버를 의미합니다.

접근 제어를 이용한 데이터 보호와 캡슐화는 DAY 13에서 더 자세히 학습할 예정입니다.

---

## 3. 실습 문제

### 실습 1. Item 구조체 만들기

**문제**

아이템의 이름, 가격, 수량을 저장하는 `Item` 구조체를 정의하고 두 개의 아이템 객체를 생성합니다.

**작성 코드**

```cpp
struct Item {
    std::string name;
    int price;
    int quantity;
};
```

```cpp
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
```

**출력 결과**

```text
Item: Sword
Price: 500
Quantity: 1
Item: Potion
Price: 100
Quantity: 3
```

**학습 내용**

같은 구조체를 이용하여 서로 다른 데이터를 가진 객체를 생성했습니다.

각 객체의 멤버에 `.` 연산자로 접근하여 값을 저장하고 출력했습니다.

### 실습 2. Player 구조체와 멤버 함수

**문제**

플레이어의 이름, HP, 공격력을 저장하는 구조체를 작성하고 멤버 함수를 통해 HP를 변경합니다.

**작성 코드**

```cpp
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

        if (hp < 0) {
            hp = 0;
        }
    }
};
```

**함수 호출**

```cpp
Player player;

player.name = "Hanna";
player.hp = 100;

player.showStatus();
player.takeDamage(25);
player.showStatus();
```

**출력 결과**

```text
Name: Hanna
HP: 100
Name: Hanna
HP: 75
```

**학습 내용**

`takeDamage()`는 `damage`만 매개변수로 전달받아 객체의 HP를 감소시킵니다.

멤버 함수에서 자신의 객체에 속한 `hp`에 직접 접근할 수 있으므로 HP를 별도의 매개변수로 전달할 필요가 없습니다.

또한 HP가 음수가 되지 않도록 조건문을 적용했습니다.

### 실습 3. Monster 클래스 만들기

**문제**

몬스터의 이름, HP, 공격력을 저장하는 클래스를 정의하고 멤버 함수를 이용하여 상태를 출력하고 데미지를 적용합니다.

**작성 코드**

```cpp
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
```

**함수 호출**

```cpp
Monster slime;

slime.name = "Slime";
slime.hp = 50;

slime.showStatus();
slime.takeDamage(20);
slime.showStatus();
```

**출력 결과**

```text
Monster: Slime
HP: 50
Slime takes 20 damage!
Monster: Slime
HP: 30
```

**학습 내용**

`class`로 사용자 정의 자료형을 만들고, `public:`을 이용하여 외부에서 멤버에 접근할 수 있도록 설정했습니다.

또한 멤버 함수를 호출하여 몬스터 객체의 HP를 변경했습니다.

### 실습 4. 미니 전투 시스템

**문제**

`Player` 구조체와 `Monster` 클래스를 이용하여 플레이어의 공격과 몬스터의 반격을 구현합니다.

**전투 설정**

| 항목 | Player | Monster |
|---|---|---|
| 이름 | Hanna | Slime |
| 초기 HP | 100 | 50 |
| 공격력 | 20 | 15 |

**작성 코드**

```cpp
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
```

**출력 결과**

```text
=== Battle Start ===
Name: Hanna
HP: 100
Monster: Slime
HP: 50
Hanna attacks Slime!
Slime takes 20 damage!
Slime HP: 30
Slime counterattacks!
Hanna HP: 85
=== Battle End ===
```

**학습 내용**

플레이어가 공격할 때는 몬스터 객체의 `takeDamage()`를 호출하고, 몬스터가 반격할 때는 플레이어 객체의 `takeDamage()`를 호출했습니다.

각 객체는 자신의 HP를 관리하며, 다른 객체의 공격력을 전달받아 데미지를 계산합니다.

이를 통해 서로 다른 객체가 상호작용하는 간단한 전투 시스템을 구현했습니다.

---

## 4. 개발 과정에서 발생한 오류와 해결

### 4.1 HP 계산에서 연산자 우선순위 오류

**문제**

처음에는 HP를 감소시키면서 동시에 조건을 검사하려고 다음과 같이 작성했습니다.

```cpp
if (hp -= damage >= 0) {
    hp -= damage;
}
```

**원인**

C++에서 비교 연산자 `>=`는 복합 대입 연산자 `-=`보다 우선순위가 높습니다.

따라서 조건식은 의도한 HP 계산과 다르게 해석됩니다.

```cpp
hp -= (damage >= 0)
```

데미지가 0 이상이라면 비교 결과가 `true`이므로, 정수 연산에서 1로 변환되어 HP에서 1이 먼저 감소할 수 있습니다.

조건이 참일 경우 블록 안에서 데미지를 추가로 차감하므로 계산 결과가 잘못됩니다.

**해결**

HP 감소와 최솟값 검사를 분리했습니다.

```cpp
hp -= damage;

if (hp < 0) {
    hp = 0;
}
```

**배운 점**

연산자 우선순위를 정확히 이해해야 하며, 여러 작업을 하나의 조건식에 결합하기보다 계산과 검사를 구분하면 코드의 동작을 이해하기 쉽습니다.

### 4.2 공격 대상 지정 오류

**문제**

미니 전투 시스템을 처음 작성했을 때, 플레이어가 공격하는 상황에서 플레이어 자신의 `takeDamage()`를 호출했습니다.

```cpp
player.takeDamage(slime.attack);
```

반대로 몬스터가 반격하는 상황에서는 몬스터 자신의 `takeDamage()`를 호출했습니다.

```cpp
slime.takeDamage(player.attack);
```

**원인**

공격하는 객체와 공격받는 객체를 혼동했습니다.

**해결**

공격받는 객체의 `takeDamage()`를 호출하도록 수정했습니다.

```cpp
slime.takeDamage(player.attack);
player.takeDamage(slime.attack);
```

**배운 점**

객체의 멤버 함수는 호출된 객체의 상태를 변경합니다.

따라서 전투 시스템에서는 공격자와 피격자의 역할을 구분하는 것이 중요합니다.

### 4.3 하나의 main()에서 여러 실습 진행

이번 실습에서는 하나의 `main()`에서 네 가지 문제를 순서대로 구현했습니다.

실습 4에서는 실습 2와 3에서 생성한 객체를 재사용했습니다.

```cpp
player.hp = 100;
slime.hp = 50;
```

기존 객체의 멤버 값을 다시 설정하여 다음 실습에 활용하는 것은 정상적인 방법입니다.

다만 실제 프로젝트에서는 필요에 따라 기능을 별도의 함수나 파일로 분리하면 코드의 구조를 더 명확하게 만들 수 있습니다.

---

## 5. DAY 09와 DAY 12 비교

### DAY 09 — 개별 변수와 외부 함수 사용

DAY 09에서는 플레이어 HP와 몬스터 HP를 각각 변수로 선언했습니다.

```cpp
int playerHp = 100;
int monsterHp = 100;
```

공격 함수에 필요한 값을 매개변수로 전달하고, 반환값을 다시 저장했습니다.

```cpp
monsterHp = attack(c, playerAt, monsterHp);
```

### DAY 12 — 객체와 멤버 함수 사용

DAY 12에서는 관련 데이터를 구조체 또는 클래스의 멤버로 관리했습니다.

```cpp
struct Player {
    std::string name;
    int hp;
    int attack;

    void takeDamage(int damage) {
        hp -= damage;

        if (hp < 0) {
            hp = 0;
        }
    }
};
```

객체의 멤버 함수를 통해 상태를 변경합니다.

```cpp
player.takeDamage(slime.attack);
```

**두 방식의 차이**

| 구분 | DAY 09 | DAY 12 |
|---|---|---|
| 데이터 관리 | 개별 변수 | 객체의 멤버 변수 |
| 함수 | 외부 함수 | 멤버 함수 |
| HP 변경 | 반환값을 저장 | 객체의 멤버 함수에서 변경 |
| 데이터와 기능 | 별도 관리 | 하나의 자료형에 함께 정의 |
| 확장 방향 | 변수와 함수 추가 | 객체의 역할과 관계 설계 |

객체를 이용하면 관련 데이터와 동작을 함께 관리할 수 있다는 점을 확인했습니다.

---

## 6. 이번 실습에서 배운 점

### 6.1 구조체와 클래스로 새로운 자료형을 정의할 수 있다

기존의 `int`, `std::string`과 같은 자료형뿐 아니라 `Item`, `Player`, `Monster`처럼 프로그램의 목적에 맞는 자료형을 직접 정의할 수 있습니다.

### 6.2 객체마다 독립적인 상태를 가질 수 있다

동일한 구조체나 클래스로 여러 객체를 생성하더라도 각 객체의 멤버 데이터는 독립적으로 관리됩니다.

### 6.3 멤버 함수로 객체의 상태를 관리할 수 있다

`takeDamage()`를 멤버 함수로 구현하여 객체의 HP를 직접 변경했습니다.

이를 통해 모든 데이터를 외부 함수의 매개변수로 전달할 필요 없이 객체 내부에서 처리하는 방법을 학습했습니다.

### 6.4 객체 사이의 상호작용을 구현할 수 있다

플레이어와 몬스터 객체가 서로 공격하는 과정을 구현했습니다.

어떤 객체가 함수를 호출하는지에 따라 변경되는 상태가 달라진다는 점을 확인했습니다.

### 6.5 객체지향 설계의 기초를 이해했다

이번 실습에서는 `struct`, `class`, 멤버 변수와 멤버 함수의 기본적인 사용 방법을 학습했습니다.

다음 단계에서는 생성자와 접근 제어를 이용하여 객체의 초기화와 데이터 보호를 더 체계적으로 구현할 예정입니다.

---

## 7. 향후 학습 계획

- 생성자(Constructor)를 이용한 객체 초기화
- `private`과 `public`을 이용한 캡슐화
- 헤더 파일과 `.cpp` 파일 분리
- 상속(Inheritance)과 가상 함수(Virtual Function)
- 클래스 기반 텍스트 전투 게임 확장

---

## 8. 파일 구성

```text
Day12/
├── Day12_StructClass.cpp
└── README.md
```

- `Day12_StructClass.cpp`: 구조체와 클래스 실습 코드
- `README.md`: 핵심 개념, 실습 과정 및 오류 수정 기록


