# Day 07. C++ vector와 반복자 (Vector & Iterator)

> 학습 주제: `std::vector`, `push_back()`, `pop_back()`, `size()`, 범위 기반 for문, Iterator

## 1. 학습 목표

- 일반 배열과 `std::vector`의 차이 이해하기
- `std::vector` 선언 및 초기화
- `push_back()`과 `pop_back()`을 이용한 요소 추가·제거
- `size()`를 이용한 요소 개수 확인
- 범위 기반 `for`문 사용하기
- 반복자(Iterator)를 이용한 컨테이너 순회
- `bool`과 `break`를 활용한 인벤토리 검색 구현

---

## 2. std::vector란?

`std::vector`는 C++ 표준 라이브러리에서 제공하는 동적 배열 컨테이너이다.

일반 배열과 달리 실행 중에 요소를 추가하거나 제거하여 크기를 변경할 수 있다.

### 일반 배열과 vector 비교

```cpp
std::string item[3] = {"Sword", "Shield", "Potion"};

std::vector<std::string> items = {"Sword", "Shield", "Potion"};
```

| 구분 | 일반 배열 | vector |
|---|---|---|
| 크기 | 고정 | 동적으로 변경 가능 |
| 요소 추가 | 크기 확장 불가 | `push_back()` |
| 마지막 요소 제거 | 크기 축소 불가 | `pop_back()` |
| 인덱스 접근 | `item[0]` | `items[0]` |
| 요소 개수 확인 | `std::size()` 등 | `items.size()` |

### vector 선언

```cpp
#include <vector>
#include <string>

std::vector<std::string> items = {
    "Sword", "Shield", "Potion"
};
```

- `std::vector`: 동적 배열 컨테이너
- `<std::string>`: 저장할 요소의 자료형
- `items`: vector 변수 이름

---

## 3. vector의 주요 함수

### push_back()

vector의 마지막에 요소를 추가한다.

```cpp
items.push_back("Bow");
```

실행 후:

```text
Sword
Shield
Potion
Bow
```

### pop_back()

vector의 마지막 요소를 제거한다.

```cpp
items.pop_back();
```

실행 후:

```text
Sword
Shield
Potion
```

`pop_back()`은 제거한 요소를 반환하지 않으며, 빈 vector에서 호출하면 안 된다.

### size()

현재 vector에 저장된 요소의 개수를 반환한다.

```cpp
std::cout << items.size() << '\n';
```

출력 결과:

```text
3
```

---

## 4. vector 순회

### 인덱스를 이용한 for문

```cpp
for (int i = 0; i < items.size(); i++) {
    std::cout << items[i] << '\n';
}
```

배열과 마찬가지로 인덱스는 0부터 시작한다.

`items.size()`는 부호 없는 정수형을 반환하므로 인덱스 변수에 `std::size_t`를 사용하는 방식도 있다.

```cpp
for (std::size_t i = 0; i < items.size(); i++) {
    std::cout << items[i] << '\n';
}
```

### 범위 기반 for문

```cpp
for (const std::string& item : items) {
    std::cout << item << '\n';
}
```

범위 기반 for문은 컨테이너의 요소를 순서대로 순회한다.

- `const`: 요소를 수정하지 않도록 제한
- `std::string&`: 문자열 요소를 참조
- `item`: 현재 순회 중인 요소

이 방식은 문자열을 매 반복마다 복사하지 않고 읽기 전용으로 접근할 수 있다.

---

## 5. 반복자(Iterator)

반복자는 컨테이너의 요소를 가리키며 순회하는 데 사용하는 객체이다.

### 반복자를 이용한 출력

```cpp
for (auto it = items.begin(); it != items.end(); ++it) {
    std::cout << *it << '\n';
}
```

| 표현 | 역할 |
|---|---|
| `begin()` | 첫 번째 요소를 가리키는 반복자 반환 |
| `end()` | 마지막 요소 바로 다음 위치의 반복자 반환 |
| `auto` | 초기화 표현식으로 자료형 추론 |
| `++it` | 다음 요소로 이동 |
| `*it` | 반복자가 가리키는 요소에 접근 |

`end()`는 실제 요소를 가리키지 않으므로 역참조하면 안 된다.

---

## 6. 실습 문제

### 실습 1. vector 아이템 목록 출력

`Sword`, `Shield`, `Potion`을 vector에 저장하고 `for`문을 이용해 출력하였다.

```cpp
std::vector<std::string> items = {
    "Sword", "Shield", "Potion"
};

for (int i = 0; i < items.size(); i++) {
    std::cout << items[i] << '\n';
}
```

**학습 내용**

- vector 선언과 초기화
- 인덱스를 이용한 요소 접근
- 반복문을 이용한 요소 출력

### 실습 2. 아이템 추가 및 제거

기존 인벤토리에 `Bow`를 추가한 뒤 마지막 아이템을 제거하였다.

```cpp
items.push_back("Bow");
items.pop_back();
```

이후 범위 기반 for문을 이용하여 남은 아이템을 출력하였다.

```cpp
for (const std::string& item : items) {
    std::cout << item << '\n';
}

std::cout << items.size() << '\n';
```

최종 인벤토리:

```text
Sword
Shield
Potion
```

아이템 개수: `3`

**학습 내용**

- vector 크기의 동적 변경
- 요소 추가 및 제거
- 범위 기반 for문
- `size()`를 이용한 요소 개수 확인

### 실습 3. 반복자를 이용한 출력

반복자를 이용하여 vector에 저장된 모든 아이템을 출력하였다.

```cpp
for (auto it = items.begin(); it != items.end(); ++it) {
    std::cout << *it << '\n';
}
```

**학습 내용**

- `begin()`과 `end()` 사용
- `auto` 자료형 추론
- 반복자 증가 연산
- 역참조 연산자 `*` 사용

### 실습 4. 인벤토리 아이템 검색

사용자에게 아이템 이름을 입력받고, vector에서 해당 아이템이 존재하는지 검색하였다.

```cpp
std::string playerItem;

std::cout << "아이템 이름을 입력하세요: " << '\n';
std::cin >> playerItem;

bool Item = false;

for (int a = 0; a < items.size(); a++) {
    if (playerItem == items[a]) {
        Item = true;
        break;
    }
}

if (Item) {
    std::cout << "Item Found!\n";
}
else {
    std::cout << "Item not Found!\n";
}
```

**실행 예시 — 아이템이 존재하는 경우**

```text
아이템 이름을 입력하세요:
Potion
Item Found!
```

**실행 예시 — 아이템이 존재하지 않는 경우**

```text
아이템 이름을 입력하세요:
Bow
Item not Found!
```

`Bow`는 앞서 `pop_back()`으로 제거했으므로 검색되지 않는다.

**학습 내용**

- vector 요소 검색
- `bool`을 이용한 검색 상태 관리
- `break`를 이용한 반복문 종료
- 검색 결과를 한 번만 출력하는 조건 분기

---

## 7. 코드 리뷰 및 개선 사항

### 1. DAY 06 아이템 검색 로직 개선

DAY 06에서는 배열의 각 요소를 비교할 때마다 `Item Found!` 또는 `Item Not Found!`를 출력하였다.

따라서 하나의 아이템을 검색해도 여러 개의 결과가 출력되는 문제가 있었다.

DAY 07에서는 `bool` 변수를 사용해 검색 여부를 저장하고, `break`로 반복문을 종료한 뒤 최종 결과를 출력하도록 개선하였다.

```cpp
bool Item = false;

for (int a = 0; a < items.size(); a++) {
    if (playerItem == items[a]) {
        Item = true;
        break;
    }
}
```

이를 통해 검색 결과를 한 번만 출력하도록 구현하였다.

### 2. 변수명 개선

실습에서는 다음과 같이 작성하였다.

```cpp
bool Item = false;
```

추후에는 변수의 의미를 명확하게 나타내도록 `found` 또는 `itemFound`와 같은 이름을 사용할 수 있다.

### 3. 반복문 인덱스 자료형

`vector::size()`는 부호 없는 정수형을 반환한다.

따라서 `int`와 비교하면 컴파일러에서 부호 불일치 경고가 발생할 수 있다.

추후에는 `std::size_t`를 사용하거나 범위 기반 for문을 활용할 수 있다.

### 4. 코드의 역할 분리

이번 실습에서는 모든 코드를 `main()` 함수에 작성하였다.

이후 학습에서는 인벤토리 출력, 아이템 추가 및 검색을 별도의 함수로 분리하여 재사용성을 높일 수 있다.

---

## 8. 학습 회고

이번 학습에서는 고정 크기 배열과 동적 배열인 `std::vector`의 차이를 이해하였다.

`push_back()`과 `pop_back()`으로 인벤토리의 요소를 추가하고 제거했으며, `size()`로 요소 개수를 확인하였다.

또한 일반 for문, 범위 기반 for문, 반복자를 이용하는 세 가지 순회 방식을 연습하였다.

특히 DAY 06에서 구현했던 아이템 검색 기능을 `bool`과 `break`로 개선하여 검색 결과가 한 번만 출력되도록 구현하였다.

이를 통해 vector를 활용한 기본적인 게임 인벤토리 관리 방법을 학습하였다.

---

