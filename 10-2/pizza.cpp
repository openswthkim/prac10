/***************************************************************/
/*             HW#7 : 개선된 함수 기능                         */
/*  작성자 : 홍길동                    날짜 : 2023년 5월 20일  */
/*                                                             */
/* 문제 정의 :    Circle을 상속받은 NamedCircle 클래스 작성    */
/*                면적을 비교해 가장 큰 피자를 출력            */
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
	double getArea() { return 3.14 * radius * radius; } // 반지름을 이용해 면적 리턴
};
class NamedCircle : public Circle { // Circle 클래스를 상속 받은 클래스 정의
	string name; // 이름 변수
public:
    NamedCircle() : Circle(0) { name = ""; } // 기본 생성자
    NamedCircle(int r, string name) : Circle(r) { this->name = name; } // 반지름과 이름을 초기화 하는 생성자
    string getName() { return name; } // 이름을 반환
    void setName(string name) { this->name = name; } // 이름을 설정하는 함수
};
int main() {
    NamedCircle pizza[5]; // 배열 pizza 선언
    string name;
    cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ">> ";
        int n;
        cin >> n >> name; // 반지름과 이름 입력 받음
        pizza[i].setRadius(n); // 반지름 설정
        pizza[i].setName(name); // 이름 설정
    }
    double max = pizza[0].getArea(); // 가장 큰 면적 저장 할 변수 선언
    for (int i = 1; i < 5; ++i) {
        if (max < pizza[i].getArea()) { // 현재 면적이 최대 면적보다 클 경우
            max = pizza[i].getArea(); // 최대 면적에 현재 면적 대입
            name = pizza[i].getName(); // 이름 저장
        }
    }
    cout << "가장 면적이 큰 피자는 " << name << "입니다." << endl;
}