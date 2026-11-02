# Day 02. 변수, 자료형, 입력과 연산자

> 학습 주제: C++ 변수와 자료형, 표준 입력, 산술 연산자

## 1. 오늘의 학습 목표

- 변수 선언과 초기화 이해하기
- C++의 기본 자료형 익히기
- `std::cin`을 사용하여 입력받기
- 산술 연산자와 복합 대입 연산자 이해하기
- 게임 캐릭터의 체력, 공격력, 경험치 계산 구현하기

---

## 2. 변수(Variable)

변수는 프로그램에서 데이터를 저장하고 사용할 수 있도록 이름을 붙인 대상이다.

```cpp
int hp = 100;
```

- `int`: 정수형 자료형
- `hp`: 변수 이름
- `100`: 초기값
- `=`: 오른쪽 값을 왼쪽 변수에 대입

변수는 선언한 이후에도 값을 변경할 수 있다.

```cpp
int hp = 100;
hp = 70;

std::cout << hp << '\n'; // 70
```

## 3. 기본 자료형(Data Type)

| 자료형 | 설명 | 사용 예시 |
|---|---|---|
| `int` | 정수 | 체력, 레벨 |
| `float` | 실수 | 이동 속도 |
| `double` | 실수, 일반적으로 float보다 정밀함 | 계산값 |
| `char` | 문자 하나 | 등급 |
| `bool` | 참 또는 거짓 | 생존 여부 |
| `std::string` | 문자열 | 플레이어 이름 |

```cpp
#include <string>

std::string playerName = "yr";
int level = 10;
int hp = 50;
float speed = 3.5f;
bool isAlive = true;
```

`std::string`은 문자열을 다루는 표준 라이브러리 자료형이다.

## 4. 표준 입력 std::cin

`std::cin`은 키보드 등의 표준 입력에서 데이터를 읽을 때 사용한다.

```cpp
int damage;

std::cout << "Enter damage: ";
std::cin >> damage;
```

### cout과 cin 비교

| 코드 | 의미 |
|---|---|
| `std::cout << damage;` | 변수의 값을 출력 |
| `std::cin >> damage;` | 입력받은 값을 변수에 저장 |

`<<`는 출력 스트림에 데이터를 삽입하고, `>>`는 입력 스트림에서 데이터를 추출한다.

## 5. 산술 연산자

| 연산자 | 의미 | 예시 |
|---|---|---|
| `+` | 덧셈 | `10 + 5` |
| `-` | 뺄셈 | `10 - 5` |
| `*` | 곱셈 | `10 * 5` |
| `/` | 나눗셈 | `10 / 5` |
| `%` | 나머지 | `10 % 3` |

정수끼리 나누면 소수 부분이 버려진다.

```cpp
std::cout << 10 / 3 << '\n';   // 3
std::cout << 10.0 / 3 << '\n'; // 약 3.33333
```

## 6. 복합 대입 연산자

연산과 대입을 한 번에 수행할 수 있다.

```cpp
hp += 10; // hp = hp + 10;
hp -= 20; // hp = hp - 20;
hp *= 2;  // hp = hp * 2;
hp /= 2;  // hp = hp / 2;
```

게임에서는 체력 감소, 체력 회복, 경험치 획득 등에 사용할 수 있다.

---

## 7. 오늘의 실습

### 실습 1. 캐릭터 정보 출력

캐릭터의 이름, 레벨, 체력, 이동 속도를 변수로 선언하고 `cout`으로 출력하였다.

### 실습 2. 몬스터 데미지 계산

몬스터의 초기 체력을 150으로 설정하고, 공격력을 입력받아 체력을 감소시켰다.

```cpp
int monsterHp = 150;
int damage;

std::cout << "Enter player damage: ";
std::cin >> damage;

monsterHp -= damage;

std::cout << "Monster HP: " << monsterHp << '\n';
```

### 실습 3. 체력 회복

플레이어의 기존 체력에 회복량을 더하는 기능을 구현하였다.

```cpp
int hp = 50;
int heal;

std::cout << "Enter heal: ";
std::cin >> heal;

hp += heal;

std::cout << "HP: " << hp << '\n';
```

### 실습 4. 경험치 획득

기존 경험치에 사용자가 입력한 경험치를 추가하였다.

```cpp
int exp = 50;
int getExp;

std::cout << "Enter getExp: ";
std::cin >> getExp;

exp += getExp;

std::cout << "EXP: " << exp << '\n';
```

## 8. 오류 및 해결 기록

### LNK1168 오류

Visual Studio에서 빌드 중 다음 오류가 발생하였다.

`LNK1168: 실행 파일을 쓰기용으로 열 수 없습니다.`

기존 실행 파일이 사용 중이거나 다른 프로세스에 의해 잠겨 있을 때 발생할 수 있는 링커 오류이다.

확인 및 해결 방법:
1. 기존 콘솔 실행 창 종료
2. Visual Studio 디버깅 중지
3. 실행 파일이 사용 중인지 확인
4. 다시 빌드

C++ 소스 코드의 문법 오류와 링커 오류를 구분하는 것이 중요하다는 점을 배웠다.

## 9. 오늘의 회고

- 변수의 선언과 초기화 방법을 학습하였다.
- `std::cin`을 사용하여 사용자 입력을 처리하였다.
- `+=`, `-=` 연산자로 체력과 경험치를 계산하였다.
- 콘솔 프로그램을 통해 게임 시스템의 기본적인 수치 처리를 연습하였다.

### 다음 학습 목표

- 비교 연산자와 논리 연산자
- `if`, `else if`, `else` 조건문
- 체력이 0 이하일 때 몬스터 사망 판정 구현

---

## 참고 자료

**공식 문서**

- [Microsoft Learn — C++ 언어 설명서](https://learn.microsoft.com/ko-kr/cpp/cpp/?view=msvc-170)
- [Microsoft Learn — iostream](https://learn.microsoft.com/en-us/cpp/standard-library/iostream)
