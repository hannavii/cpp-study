Day6. 배열

1. 배열
같은 자료형의 데이터를 여러 개 저장할 때 사용한다.

int hp1 = 100;
int hp2 = 80;
int hp3 = 50;
 

대신

int hp[3] = {100, 80, 50};
2. 배열의 인덱스
배열의 인덱스는 0부터 시작한다.
hp[0]=100
배열의 값을 변경할 수도 있다.
hp[0]=200;을 작성하면, 200,80,50이 된다.
*주의:배열 범위를 벗어나면 안된다 (hp[3]등)-정의되지 않은 동작을 일으킨다. 오류가 표시되지 않더라도 안전한 코드가 아님

3.배열과 for문 함께 사용하기
#include <iostream>

int main() {
	int hp[3] = { 100,80,50 };
	for (int i = 0; i < 3; i++) {
		std::cout << hp[i] << '\n';
	}
}
4. 문자열이란?
문자열(String)은 여러 문자를 묶어 표현한 데이터이다.

#include <string>

std::string playerName="Hanna";
std::string은 C++ 표준 라이브러리에서 제공하는 문자열이다.
char는 문자 하나를, std::string은 문자 여러개를 저장할 수 있다.

char grade='A';
std::string name="Hanna";
문자는 작은 따옴표, 문자열 리터럴은 큰따옴표를 사용한다.

5. 문자열 연결하기
#include <iostream>
#include <string>

int main() {
    std::string firstName = "Dark";
    std::string lastName = "Knight";

    std::string characterName = firstName + " " + lastName;

    std::cout << characterName << '\n';
}
문자열에서의 +는 문자열을 이어붙이는 역할을 한다.

6.문자열 길이 구하기
문자열 길이를 구할 때는 .length()또는 .size()로 구한다.

#include <iostream>
#include <string>

int main() {
	std::string name = "Player";
	std::cout << name.length() << '\n';
}
한글같은 UTF-8 문자열은 글자 수가 아닌 바이트 수를 반환할 수도 있다.

7.문자열도 인덱스로 접근 가능하다
#include <iostream>
#include <string>

int main() {
	std::string name = "Hero";
	std::cout << name[0] << '\n';
	std::cout << name[1] << '\n';
}
출력 결과: H e

8.실습 문제
(1) 정수형 배열 hp에 100, 80, 50, 120, 60을 저장하고, for문을 사용해 모든 HP를 한 줄씩 출력하세요.
(2) 문자열 배열에 Sword, Shield, Potion, Bow를 저장한 뒤 for문으로 모든 아이템을 출력하세요.
(3) std::string 변수에 사용자로부터 플레이어 이름을 입력받으세요. 이름과 이름의 길이를 출력하세요.
(4) Sword, Shield, Potion, Bow가 저장된 문자열 배열을 만드세요. 사용자에게 아이템 이름을 입력받고, 배열을 순회하면서 일치하는 아이템이 있으면 Item Found!, 없으면 Item Not Found!를 출력하세요.

#include <iostream>
#include <string>

int main() {
	int hp[5] = { 100,80,50,120,60 };
	for (int i = 0; i < 5; i++) {
		std::cout << hp[i] << '\n';
	}
	std::string item[4] = { "Sword", "Shield", "Potion", "Bow"};
	for (int a = 0; a < 4; a++) {
		std::cout << item[a] << '\n';
	}
	std::string name = "";
	std::cout << "사용자 이름을 입력하세요: " << '\n';
	std::cin >> name;
	std::cout << name+ " " <<name.length() << '\n';
	std::string itemName = "";
	std::cout << "아이템 이름을 입력하세요: " << '\n';
	std::cin >> itemName;
	for (int b = 0; b < 4; b++) {
		if (itemName == item[b]) {
			std::cout << "Item Found!" << '\n';
		}
		else {
			std::cout << "Item Not Found!" << '\n';
		}
	}
}
2번문제에서 

std::string Sword = "Iron Sword";
std::string Shield = "Wooden Shield";
std::string Potion = "Health Potion";
std::string Bow = "Long Bow";

이런식으로 미리 변수를 선언해두었다면, 큰따옴표가 필요없다.
배열의 크기는 초기화 값의 개수로 자동 결정할 수 있다.([]빈칸으로 두어도 됨)

추가 질문

1.main함수는 void가 될 수 없는가?
2.'\n' 와 "\n"는 다른가?
3.std::string이 그냥 다른 언어에서 사용하는 string A=name 이런식의 문자형인가? 왜 std를 써야하는지
4.include string을 안해주면 string사용이 불가한가?
5.int랑 문자열은 합칠 때 + 사용이 안되나?
답변
1.표준 c++에서는 안된다. int사용필수
2.'\n'은 문자, "\n"은 문자열 리터럴
3.정확히는 문자열을 관리하는 클래스 타입
4.표준에 맞고 이식성 있는 코드를 위해 반드시 사용
5.직접은 안된다. std::to_string()으로 자료형을 변환하면 사용 가능
