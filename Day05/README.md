# Day 05. C++ 함수 (Functions)

> 학습 주제: 함수 선언과 정의, 매개변수, 반환값, `return`

## 1. 학습 목표

- 함수의 개념과 필요성 이해하기
- 함수 선언, 정의, 호출의 차이 이해하기
- `void` 함수 사용하기
- 매개변수(Parameter)와 인수(Argument) 구분하기
- `return`을 이용해 계산 결과 반환하기
- 함수를 활용하여 게임의 공격 및 회복 기능 구현하기

---

## 2. 함수(Function)란?

함수는 특정 작업을 수행하는 코드를 하나로 묶어 놓은 것이다.

함수를 사용하면 코드를 재사용할 수 있고, 기능별로 분리하여 프로그램의 가독성과 유지보수성을 높일 수 있다.

### 기본 구조

```cpp
반환형 함수이름(매개변수) {
    // 실행할 코드
    return 반환값;
}
```

반환값이 없는 `void` 함수는 값을 반환하는 `return`이 필요하지 않다.

### 함수의 구성 요소

| 구성 요소 | 설명 |
|---|---|
| 반환형 | 함수가 반환하는 값의 자료형 |
| 함수 이름 | 함수를 호출할 때 사용하는 이름 |
| 매개변수 | 함수가 전달받는 값을 저장하는 변수 |
| 함수 본문 | 함수가 수행할 작업 |
| return | 함수 실행 종료 및 반환값 전달 |

---

## 3. void 함수

`void`는 함수가 값을 반환하지 않는다는 의미이다.

```cpp
void greet() {
    std::cout << "Hello Player!" << '\n';
}
```

함수를 호출하면 작성된 코드가 실행된다.

```cpp
greet();
greet();
greet();
```

실행 결과:

```text
Hello Player!
Hello Player!
Hello Player!
```

---

## 4. 매개변수와 인수

함수는 외부에서 값을 전달받아 사용할 수 있다.

```cpp
void attack(int damage) {
    std::cout << "Damage: " << damage << '\n';
}
```

함수 호출:

```cpp
attack(20);
attack(35);
```

실행 결과:

```text
Damage: 20
Damage: 35
```

- **매개변수(Parameter):** 함수를 정의할 때 선언하는 `damage`
- **인수(Argument):** 함수를 호출할 때 전달하는 `20`, `35`

---

## 5. 반환값과 return

`return`을 사용하면 함수에서 계산한 결과를 호출한 곳에 반환할 수 있다.

```cpp
int calculateDamage(int attack, int defense) {
    int result = attack - defense;
    return result;
}
```

함수 호출:

```cpp
std::cout << calculateDamage(50, 15) << '\n';
```

실행 결과:

```text
35
```

함수의 반환값을 별도의 변수에 저장하거나 바로 출력할 수 있다.

---

## 6. 함수 선언과 정의

함수 선언은 함수의 반환형, 이름, 매개변수 정보를 컴파일러에 알려준다.

함수 정의는 실제로 수행할 코드를 작성하는 것이다.

```cpp
int add(int a, int b); // 함수 선언

int add(int a, int b) { // 함수 정의
    return a + b;
}
```

함수 호출 위치보다 앞에 선언이 있어야 하며, 함수 정의는 뒤에 작성할 수도 있다.

---

## 7. 실습 문제

### 실습 1. 인사 함수

`void greet()` 함수를 작성하고 `main()`에서 세 번 호출하였다.

```cpp
void greet() {
    std::cout << "Hello Player!" << '\n';
}
```

**학습 내용**
- 반환값이 없는 함수 구현
- 함수 호출 방법
- 동일한 함수 반복 호출

### 실습 2. 공격 함수

매개변수로 데미지를 전달받아 출력하는 함수를 구현하였다.

```cpp
void attack(int damage) {
    std::cout << "Damage: " << damage << '\n';
}
```

**학습 내용**
- 매개변수 선언
- 함수 호출 시 인수 전달
- 전달받은 값을 함수 내부에서 사용

### 실습 3. 데미지 계산 함수

공격력과 방어력을 전달받아 데미지를 계산하고 반환하였다.

```cpp
int calculateDamage(int attack, int defense) {
    int result = attack - defense;
    return result;
}
```

**학습 내용**
- 여러 매개변수 사용
- 정수형 반환값
- `return`을 통한 계산 결과 전달

### 실습 4. 체력 회복 함수

현재 체력과 회복량을 전달받아 회복된 체력을 반환하는 함수를 구현하였다.

```cpp
int heal(int hp, int amount) {
    int re = hp + amount;
    return re;
}
```

**학습 내용**
- 두 매개변수를 이용한 연산
- 반환값이 있는 함수
- 게임 내 체력 회복 로직 구현

---

## 8. 전체 실행 결과

```text
Hello Player!
Hello Player!
Hello Player!
Damage: 20
Damage: 35
35
80
```

위 결과는 최초 작성한 실습 코드 기준이다.

이후 출력문의 가독성을 위해 데미지와 HP에 라벨을 추가하도록 개선하였다.

```cpp
std::cout << "Damage: " << calculateDamage(50, 15) << '\n';
std::cout << "HP: " << heal(50, 30) << '\n';
```

---

## 9. 코드 리뷰 및 개선 사항

### 1. 함수의 반환값 활용

반환값을 반드시 변수에 저장할 필요는 없다.

```cpp
std::cout << calculateDamage(50, 15) << '\n';
```

하지만 실제 변수의 값을 변경하려면 반환값을 저장해야 한다.

```cpp
int hp = 50;
hp = heal(hp, 30);
```

이 경우 `hp`는 80이 된다.

### 2. 값 전달 이해하기

현재 구현한 함수는 정수를 값으로 전달받는다.

따라서 함수 내부의 매개변수를 변경해도 호출한 곳의 원본 변수는 자동으로 변경되지 않는다.

추후 참조자와 포인터를 학습하며 이 차이를 더 자세히 이해할 예정이다.

### 3. 변수명 개선

`re`와 같은 축약된 이름보다 `result`나 `healedHp`처럼 의미가 명확한 변수명을 사용하는 것이 좋다.

```cpp
int heal(int hp, int amount) {
    int healedHp = hp + amount;
    return healedHp;
}
```

### 4. 함수의 역할 분리

`attack()` 함수는 전달받은 데미지를 출력하고, `calculateDamage()` 함수는 실제 계산 결과를 반환한다.

출력과 계산 기능을 구분하면 함수를 다른 곳에서도 재사용하기 쉬워진다.

---

## 10. 학습 회고

이번 학습에서는 함수를 직접 정의하고 호출하면서 코드 재사용과 기능 분리의 중요성을 이해하였다.

`void` 함수와 반환값이 있는 함수의 차이를 익히고, 매개변수를 이용한 값 전달과 `return`을 활용한 계산 결과 반환을 연습하였다.

특히 함수에서 반환된 값을 출력하는 것과 실제 변수에 저장하는 것은 다르다는 점을 배웠다.

앞으로 게임 시스템을 구현할 때 기능별로 함수를 분리하는 연습을 이어갈 예정이다.

---

