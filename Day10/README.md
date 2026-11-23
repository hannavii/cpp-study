# Day 10 — References & const

## 1. 학습 목표

C++의 참조자(Reference)와 `const` 키워드를 학습하고, 함수에 데이터를 전달하는 방식에 따른 차이를 이해했습니다.

DAY 09에서는 함수 내부에서 HP를 변경하더라도 `main()`의 원본 HP가 변경되지 않는 문제를 경험했습니다. 이번 실습에서는 참조자를 이용하여 원본 변수를 직접 변경하는 방법을 학습했습니다.

**주요 학습 내용**
- 값에 의한 전달(Pass by Value)
- 참조자(Reference)의 선언과 사용
- 참조에 의한 전달(Pass by Reference)
- `const` 키워드의 역할
- `const` 참조자를 이용한 읽기 전용 데이터 전달
- 참조자를 활용한 HP 감소 및 회복 함수 구현

---

## 2. 핵심 개념

### 2.1 값에 의한 전달 (Pass by Value)

함수에 일반 변수를 전달하면 매개변수에 값이 복사됩니다.

따라서 함수 내부에서 매개변수의 값을 변경하더라도 원본 변수에는 영향을 주지 않습니다.

```cpp
void changeHp(int hp) {
    hp = 50;
}

int main() {
    int playerHp = 100;

    changeHp(playerHp);

    std::cout << playerHp << '\n';
}
```

**출력 결과**

```text
100
```

`changeHp()`의 `hp`는 원본 `playerHp`와 별개의 변수이므로 원본 값은 100으로 유지됩니다.

### 2.2 참조자 (Reference)

참조자는 이미 존재하는 객체를 참조하는 또 다른 이름입니다.

참조자를 선언할 때는 `&` 기호를 사용합니다.

```cpp
int a = 10;
int& b = a;

b = 30;

std::cout << a << '\n';
```

**출력 결과**

```text
30
```

`b`는 `a`의 참조자이므로 `b`를 통해 값을 변경하면 원본 `a`의 값도 변경됩니다.

**값 복사와 참조의 차이**

| 구분 | 값 복사 | 참조자 |
|---|---|---|
| 선언 | `int b = a;` | `int& b = a;` |
| 원본과의 관계 | 별개의 변수 | 동일한 객체의 다른 이름 |
| 값 변경 | 원본에 영향 없음 | 원본에 반영됨 |
| 주요 용도 | 독립적인 값 저장 | 원본 데이터 접근 및 수정 |

### 2.3 참조에 의한 전달 (Pass by Reference)

함수의 매개변수를 참조자로 선언하면 함수가 호출한 쪽의 원본 객체에 접근할 수 있습니다.

```cpp
void takeDamage(int& hp, int damage) {
    hp -= damage;
}
```

`int& hp`는 전달받은 원본 HP를 참조합니다.

따라서 `return`으로 변경된 값을 반환하지 않더라도 원본 HP를 변경할 수 있습니다.

```cpp
int hp = 100;

takeDamage(hp, 25);

std::cout << hp << '\n';
```

**출력 결과**

```text
75
```

### 2.4 const 키워드

`const`는 해당 선언을 통해 객체의 값을 수정하지 못하도록 제한하는 키워드입니다.

```cpp
const int maxHp = 100;
```

다음과 같이 값을 변경하려고 하면 컴파일 오류가 발생합니다.

```cpp
maxHp = 200; // 컴파일 오류
```

게임에서 최대 HP처럼 변경할 필요가 없는 값을 보호하는 데 사용할 수 있습니다.

### 2.5 const 참조자 (const Reference)

`const`와 참조자를 함께 사용하면 원본 객체를 참조하면서도 해당 참조자를 통한 수정을 방지할 수 있습니다.

```cpp
void showPlayer(const std::string& name, const int& hp) {
    std::cout << "Player Name: " << name << '\n';
    std::cout << "HP: " << hp << '\n';
}
```

- `const std::string& name`: 문자열을 복사하지 않고 읽기 전용으로 참조
- `const int& hp`: 정숫값을 읽기 전용으로 참조

함수 내부에서 해당 매개변수의 값을 변경하려고 하면 컴파일 오류가 발생합니다.

**함수 매개변수 전달 방식 비교**

| 매개변수 | 전달 방식 | 원본 수정 |
|---|---|---|
| `int hp` | 값에 의한 전달 | 불가능 |
| `int& hp` | 참조에 의한 전달 | 가능 |
| `const int& hp` | const 참조에 의한 전달 | 해당 참조자를 통해 수정 불가능 |

`std::string`, `std::vector`처럼 복사 비용이 발생할 수 있는 객체를 읽기만 하는 함수에서는 `const T&`를 유용하게 사용할 수 있습니다.

반면 `int`처럼 작은 자료형은 단순 값 전달도 효율적입니다.

---

## 3. 실습 문제

### 실습 1. 일반 변수와 참조자 비교

**문제**

- `a`를 10으로 초기화
- `b`에 `a`의 값을 복사
- `c`를 `a`의 참조자로 선언
- `b`를 20으로 변경
- `c`를 30으로 변경
- 최종 `a`, `b`, `c` 출력

**작성 코드**

```cpp
int a = 10;
int b = a;
int& c = a;

b = 20;
c = 30;

std::cout << a << b << c << '\n';
```

**출력 결과**

```text
302030
```

각 변수의 실제 값은 다음과 같습니다.

| 변수 | 최종 값 |
|---|---|
| `a` | 30 |
| `b` | 20 |
| `c` | 30 |

`b`는 별개의 복사본이므로 `a`에 영향을 주지 않습니다.

반면 `c`는 `a`의 참조자이므로 `c = 30`을 실행하면 `a`도 30이 됩니다.

**개선 사항**

출력값을 쉽게 구분할 수 있도록 공백이나 변수명을 함께 출력하는 것이 좋습니다.

### 실습 2. 참조자를 이용한 HP 감소

**문제**

- 초기 HP: 100
- 데미지: 25
- 참조자를 이용하여 원본 HP 감소
- `return` 없이 HP 변경

**작성 코드**

```cpp
void takeDamage(int& hp, int damage) {
    hp -= damage;
}
```

**함수 호출**

```cpp
int hp = 100;
int damage = 25;

takeDamage(hp, damage);

std::cout << "Player Hp: " << hp << '\n';
```

**출력 결과**

```text
Player Hp: 75
```

참조 매개변수 `int& hp`를 사용하여 `main()`의 원본 HP를 직접 변경했습니다.

### 실습 3. const 참조자를 이용한 플레이어 정보 출력

**문제**

- 플레이어 이름: Hanna
- 플레이어 HP: 100
- `const` 참조자를 이용하여 정보 출력
- 함수 내부에서 원본 데이터 수정하지 않기

**작성 코드**

```cpp
void showPlayer(const std::string& name, const int& hp) {
    std::cout << "Player Name: " << name << '\n';
    std::cout << "HP: " << hp << '\n';
}
```

**함수 호출**

```cpp
hp = 100;
std::string playerName = "Hanna";

showPlayer(playerName, hp);
```

**출력 결과**

```text
Player Name: Hanna
HP: 100
```

`const` 참조자를 사용하여 플레이어 정보를 변경하지 않고 출력했습니다.

### 실습 4. 참조자를 이용한 HP 회복

**문제**

- 초기 HP: 80
- 회복량: 30
- 최대 HP: 100
- 참조자를 이용하여 원본 HP 변경
- 최대 HP를 초과하지 않도록 처리

**작성 코드**

```cpp
void healPlayer(int& hp, int amount, int maxHp) {
    hp += amount;

    if (hp > maxHp) {
        hp = maxHp;
    }
}
```

**함수 호출**

```cpp
hp = 80;
int heal = 30;
int playerHpMax = 100;

std::cout << "Before Heal: " << hp << '\n';

healPlayer(hp, heal, playerHpMax);

std::cout << "After Heal: " << hp << '\n';
```

**출력 결과**

```text
Before Heal: 80
After Heal: 100
```

회복 후 HP가 110이 되지만, 최대 HP 제한 조건에 따라 100으로 조정됩니다.

DAY 09에서는 함수에서 변경된 HP를 `return`으로 반환했지만, 이번에는 참조 매개변수를 활용하여 원본 HP를 직접 변경했습니다.

---

## 4. DAY 09와 비교

DAY 09에서 사용했던 HP 변경 방식과 DAY 10에서 학습한 참조자 방식을 비교했습니다.

### DAY 09 — 반환값을 이용한 변경

```cpp
int takeDamage(int hp, int damage) {
    hp -= damage;
    return hp;
}

int main() {
    int playerHp = 100;

    playerHp = takeDamage(playerHp, 25);
}
```

함수는 복사된 HP를 계산한 뒤 결과를 반환합니다.

호출하는 쪽에서 반환값을 원본 변수에 대입해야 실제 HP가 변경됩니다.

### DAY 10 — 참조자를 이용한 변경

```cpp
void takeDamage(int& hp, int damage) {
    hp -= damage;
}

int main() {
    int playerHp = 100;

    takeDamage(playerHp, 25);
}
```

함수에서 원본 HP를 직접 수정하므로 반환값을 다시 저장할 필요가 없습니다.

**두 방식 모두 올바른 C++ 코드이며, 함수의 목적에 따라 적절한 방식을 선택할 수 있습니다.**

---

## 5. 이번 실습에서 배운 점

### 5.1 참조자는 원본 객체의 또 다른 이름

일반 변수에 값을 복사하는 것과 참조자를 선언하는 것은 다르다는 점을 확인했습니다.

복사된 변수는 독립적인 값을 가지지만, 참조자는 원본 객체와 연결되어 있습니다.

### 5.2 함수에서 원본 값을 변경하는 방법

함수의 매개변수를 `int&`로 선언하면 원본 변수를 직접 수정할 수 있습니다.

DAY 09에서 사용했던 `return` 방식과 비교하면서 함수의 데이터 전달 방식을 이해했습니다.

### 5.3 const를 이용한 데이터 보호

수정할 필요가 없는 데이터를 `const` 참조자로 전달하여 함수 내부의 의도하지 않은 변경을 방지할 수 있습니다.

읽기 전용 매개변수와 수정 가능한 참조 매개변수를 구분하는 방법을 학습했습니다.

### 5.4 함수의 목적에 따른 매개변수 설계

데이터를 읽기만 하는 함수와 원본 데이터를 수정해야 하는 함수는 서로 다른 매개변수 전달 방식을 사용할 수 있습니다.

이번 실습을 통해 매개변수의 자료형뿐 아니라 `&`와 `const`의 의미도 중요하다는 점을 배웠습니다.

---

## 6. 향후 학습 계획

- 포인터(Pointer)와 참조자의 차이
- 주소 연산자 `&`와 역참조 연산자 `*`
- 포인터를 이용한 데이터 접근
- 구조체 및 클래스에서 참조자 활용
- 게임 객체의 상태를 안전하게 전달하고 수정하는 방법

---

## 7. 파일 구성

```text
Day10/
├── Day10_Reference.cpp
└── README.md
```

- `Day10_Reference.cpp`: 참조자와 const 실습 코드
- `README.md`: 핵심 개념 및 실습 내용 정리

---

