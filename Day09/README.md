# Day 09 — Text Battle Game v1

## 1. 학습 목표

DAY 01~08에서 학습한 C++ 문법을 종합하여 콘솔 기반의 턴제 전투 게임을 구현했습니다.

이번 실습의 목표는 단순히 문법을 사용하는 것을 넘어, 여러 기능을 연결하여 실제로 동작하는 프로그램을 작성하고 오류를 수정하는 것입니다.

**주요 학습 내용**
- 변수와 자료형을 이용한 게임 상태 관리
- `while` 반복문을 이용한 턴제 전투 구현
- `switch-case`를 이용한 플레이어 행동 선택
- `std::mt19937`과 `std::uniform_int_distribution`을 이용한 난수 생성
- `std::vector`를 이용한 포션 인벤토리 관리
- 함수를 이용한 공격 및 회복 기능 분리
- 매개변수와 반환값을 이용한 데이터 전달
- 조건문을 이용한 전투 종료 및 승패 판정

---

## 2. 구현한 게임

### 게임 개요

플레이어가 몬스터와 턴제 전투를 진행하는 콘솔 RPG 게임입니다.

플레이어는 매 턴 세 가지 행동 중 하나를 선택할 수 있습니다.

| 선택 | 행동 | 설명 |
|---|---|---|
| 1 | Attack | 몬스터를 공격합니다. |
| 2 | Use Potion | 포션을 사용하여 HP를 회복합니다. |
| 3 | Escape | 전투에서 도망칩니다. |

### 게임 규칙

| 항목 | 설정 |
|---|---|
| 플레이어 초기 HP | 100 |
| 플레이어 최대 HP | 100 |
| 몬스터 초기 HP | 100 |
| 플레이어 공격력 | 10~30 (랜덤) |
| 몬스터 공격력 | 5~15 (랜덤) |
| 치명타 확률 | 20% |
| 치명타 효과 | 공격 데미지 2배 |
| 초기 포션 개수 | 3개 |
| 포션 회복량 | 30 HP |

몬스터가 공격을 받고도 살아 있다면 플레이어에게 반격합니다. 포션을 사용한 경우에도 몬스터의 반격이 발생합니다.

몬스터 HP가 0이 되면 승리하고, 플레이어 HP가 0이 되면 패배합니다. 도망가기를 선택하면 즉시 전투가 종료됩니다.

---

## 3. 주요 구현 코드

### 3.1 난수 생성

```cpp
std::random_device rd;
std::mt19937 gen(rd());

std::uniform_int_distribution<int> playerAttack(10, 30);
std::uniform_int_distribution<int> monsterAttack(5, 15);
std::uniform_int_distribution<int> criticalPer(1, 100);
```

- `std::random_device`: 난수 생성 엔진의 초기 시드에 사용할 값을 생성합니다.
- `std::mt19937`: 메르센 트위스터 알고리즘을 사용하는 의사 난수 생성 엔진입니다.
- `std::uniform_int_distribution<int>`: 지정한 범위의 정수를 균등한 확률로 생성합니다.

```cpp
int playerAt = playerAttack(gen);
int monsterAt = monsterAttack(gen);
```

플레이어와 몬스터의 공격력을 랜덤으로 생성합니다.

### 3.2 공격 함수

```cpp
int attack(int c, int playerAt, int monsterHp) {
    if (c <= 20) {
        std::cout << "Critical Hit!" << '\n';
        std::cout << "공격 데미지: " << playerAt * 2 << '\n';
        monsterHp -= playerAt * 2;
    }
    else {
        std::cout << "공격 데미지: " << playerAt << '\n';
        monsterHp -= playerAt;
    }
    return monsterHp;
}
```

치명타 판정값 `c`가 20 이하이면 데미지를 두 배로 적용합니다.

함수는 변경된 몬스터 HP를 반환합니다.

```cpp
int c = criticalPer(gen);
monsterHp = attack(c, playerAt, monsterHp);
```

반환값을 `monsterHp`에 저장하여 실제 게임 상태를 갱신합니다.

### 3.3 포션 회복 함수

```cpp
int usePotion(int playerHp, int playerHpMax, int heal) {
    std::cout << "포션을 사용했습니다." << '\n';

    if (playerHp + heal <= playerHpMax) {
        std::cout << "Player HP: " << playerHp + heal << '\n';
        playerHp += heal;
    }
    else {
        std::cout << "Player HP: " << playerHpMax << '\n';
        playerHp = playerHpMax;
    }

    return playerHp;
}
```

현재 HP에 회복량을 더하되, 최대 HP를 초과하지 않도록 처리합니다.

```cpp
playerHp = usePotion(playerHp, playerHpMax, heal);
```

회복된 HP를 반환받아 실제 플레이어 HP에 반영합니다.

### 3.4 vector를 이용한 포션 관리

```cpp
std::vector<int> potion = { 1, 2, 3 };
```

포션 세 개를 벡터에 저장합니다.

```cpp
if (potion.size() > 0) {
    playerHp = usePotion(playerHp, playerHpMax, heal);
    potion.pop_back();
}
else {
    std::cout << "포션을 사용할 수 없습니다.";
}
```

- `size()`: 현재 포션 개수를 확인합니다.
- `pop_back()`: 사용한 포션을 마지막 요소부터 제거합니다.

포션이 없으면 회복할 수 없도록 구현했습니다.

### 3.5 전투 반복과 종료 조건

```cpp
bool running = true;

while (monsterHp > 0 && playerHp > 0 && running == true) {
    // 전투 진행
}
```

몬스터와 플레이어가 모두 살아 있고, 전투가 진행 중일 때만 반복합니다.

도망가기를 선택하면 다음과 같이 처리합니다.

```cpp
case 3: {
    running = false;
    break;
}
```

`break`는 `switch`문을 종료하고, `running`이 `false`가 되면서 다음 반복 조건 검사에서 `while`문도 종료됩니다.

### 3.6 몬스터 반격

```cpp
if (monsterHp > 0) {
    std::cout << "몬스터의 반격: " << monsterAt << '\n';
    playerHp -= monsterAt;

    if (playerHp < 0) {
        playerHp = 0;
    }
}
```

몬스터가 살아 있는 경우에만 반격하도록 구현했습니다.

또한 플레이어 HP가 음수가 되지 않도록 처리했습니다.

---

## 4. 개발 과정에서 발생한 오류와 해결

### 4.1 switch-case 내부의 변수 선언 오류

**문제**

`switch`문 안에서 `case`보다 앞에 변수를 초기화하자 오류가 발생했습니다.

```cpp
switch (playerSelect) {
    int playerAt = playerAttack(gen);

    case 1: {
        // ...
    }
}
```

**원인**

`switch`문은 선택된 `case`로 바로 이동하므로 변수의 초기화를 건너뛸 수 있습니다.

**해결**

공통으로 사용하는 변수는 `switch`문보다 앞에서 선언하도록 수정했습니다.

```cpp
int playerAt = playerAttack(gen);

switch (playerSelect) {
    // ...
}
```

### 4.2 대입 연산자와 비교 연산자 혼동

**문제**

반복 조건에서 `=`를 사용하여 컴파일 오류가 발생했습니다.

```cpp
while (monsterHp > 0 && playerHp > 0 && running = true)
```

**원인**

- `=`: 값을 대입하는 연산자
- `==`: 두 값이 같은지 비교하는 연산자

**해결**

```cpp
while (monsterHp > 0 && playerHp > 0 && running == true)
```

### 4.3 함수 내부에서 변경한 HP가 반영되지 않는 문제

**문제**

공격과 회복을 함수로 분리한 뒤, 함수 안에서 HP를 변경했지만 `main()`의 HP는 바뀌지 않았습니다.

```cpp
void attack(int c, int playerAt, int monsterHp) {
    monsterHp -= playerAt;
}
```

**원인**

C++에서 일반적인 값 매개변수는 **값에 의한 전달(Pass by Value)** 방식으로 처리됩니다.

함수가 전달받은 값의 복사본을 변경해도 원본 변수는 변경되지 않습니다.

**해결**

함수의 반환형을 `int`로 변경하고, 계산된 HP를 반환하도록 수정했습니다.

```cpp
return monsterHp;
```

호출하는 쪽에서도 반환값을 저장하도록 변경했습니다.

```cpp
monsterHp = attack(c, playerAt, monsterHp);
```

**핵심 정리**

- 매개변수는 함수에 값을 전달합니다.
- 값으로 전달된 변수는 함수 내부에서 독립적으로 변경됩니다.
- `return`은 함수의 계산 결과를 호출한 곳으로 전달합니다.
- 반환값을 변수에 대입해야 실제 게임 상태가 갱신됩니다.

### 4.4 함수에서 지역 변수에 접근할 수 없는 문제

**문제**

`main()`에서 선언한 변수를 외부 함수에서 직접 사용하려고 하자 식별자가 정의되지 않았다는 오류가 발생했습니다.

**원인**

지역 변수는 선언된 유효 범위(Scope) 안에서만 접근할 수 있습니다.

**해결**

함수에서 필요한 값을 매개변수로 전달하도록 수정했습니다.

### 4.5 포션 회복 및 데미지 처리 오류

초기 구현에서는 포션 사용 후 HP를 출력하기만 하고 실제 변수에 반영하지 않거나, 치명타 데미지를 두 배로 출력하면서 실제 몬스터 HP에는 기본 공격력만 적용하는 문제가 있었습니다.

이를 수정하면서 **계산 결과를 출력하는 것과 게임 상태를 변경하는 것은 서로 다른 작업**이라는 점을 배웠습니다.

---

## 5. 이번 실습에서 배운 점

### 함수의 역할 분리

처음에는 모든 전투 로직을 `main()` 안에 작성했습니다.

이후 공격 기능을 `attack()`, 회복 기능을 `usePotion()`으로 분리했습니다.

함수를 분리하면 코드의 역할을 구분하고, 수정할 부분을 찾기 쉬워집니다.

### 게임 상태 관리

HP, 포션 개수, 턴 번호, 전투 진행 여부를 각각 변수로 관리했습니다.

특히 전투 조건에 따라 값이 변경되는 시점과 순서가 게임의 동작에 직접적인 영향을 준다는 것을 확인했습니다.

### 디버깅

컴파일 오류와 논리 오류가 서로 다르다는 점을 배웠습니다.

컴파일에 성공하더라도 데미지가 실제 HP에 적용되지 않거나, 몬스터가 사망한 후에도 반격하는 등의 문제가 발생할 수 있습니다.

따라서 문법뿐 아니라 실제 실행 흐름을 확인하는 과정도 중요하다는 것을 알게 되었습니다.

---

## 6. 향후 개선 사항

- 플레이어 이름을 전투 화면에 표시
- 잘못된 입력에 대한 예외 상황 처리
- 인벤토리 아이템 종류 확장
- 게임 상태를 구조체 또는 클래스로 관리
- 공격 및 회복 로직의 추가적인 함수 분리

이번 버전에서는 기본적인 턴제 전투 시스템과 C++ 기초 문법의 통합에 집중했습니다.

---

## 7. 파일 구성

```text
Day09/
├── Day09_Battle.cpp
└── README.md
```

- `Day09_Battle.cpp`: 턴제 전투 게임 구현 코드
- `README.md`: 학습 내용 및 개발 과정 정리

---
