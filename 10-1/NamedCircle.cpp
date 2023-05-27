/***************************************************************/
/*             HW#7 : 개선된 함수 기능                         */
/*  작성자 : 홍길동                    날짜 : 2023년 5월 20일  */
/*                                                             */
/* 문제 정의 :    Circle을 상속받은 NamedCircle 클래스 작성    */
/*                - - - - - - -                                */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; } // 반지름 초기화
	int getRadius() { return radius; } // 반지름 리턴
	void setRadius(int radius) { this->radius = radius; } // 입력 받은 반지름을 대입
};
class NamedCircle : public Circle { // Circle 클래스를 상속 받은 클래스 정의
	string name; // 이름 변수
public:
	NamedCircle(int r, string name) : Circle(r) { this->name = name; } // 반지름과 이름 초기화
	void show(){
		cout<<"반지름이 "<<getRadius() << "인 " << name << endl; // 반지름과 이름 출력
	}
};
int main() {
	NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 객체 생성
	waffle.show();
}
