/***************************************************************/
/*             HW#7 : 개선된 함수 기능                         */
/*  작성자 : 홍길동                    날짜 : 2023년 5월 20일  */
/*                                                             */
/* 문제 정의 :    BaseArray 클래스를 상속받아 큐처럼 작동하는  */
/*                MyQueue 클래스 작성            */
/***************************************************************/

#include <iostream>
using namespace std;
class BaseArray {
private:
    int capacity; // 동적 할당된 메모리 용량
    int* mem; // 정수 배열을 만들기 위한 메모리 포인터
protected:
    BaseArray(int capacity = 100) {
        this->capacity = capacity; mem = new int[capacity]; // 용량으로 배열 할당
    }
    ~BaseArray() { delete[] mem; } // 동적 할당한 메모리 해제
    void put(int index, int val) { mem[index] = val; } // index위치에 값 저장
    int get(int index) { return mem[index]; } // index위치 값 반환
    int getCapacity() { return capacity; } // 용량 반환
};
class MyQueue : protected BaseArray { // 원형 큐 사용
    int front; // 첫 번째 요소로부터 시계 방향으로 하나 앞
    int rear; // 마지막 요소
public:
    MyQueue(int capacity) : BaseArray(capacity) { front = rear = 0; } // front와 rear 초기화
    void enqueue(int n) { // 큐에 삽입
        rear = (rear + 1) % getCapacity(); // rear 위치를 한 칸 뒤로 이동
        put(rear, n); // rear 위치에 값 저장
    }
    int dequeue() { // 큐에 있는 데이터를 꺼냄
        front = (front + 1) % getCapacity(); // front 위치를 한 칸 뒤로 이동
        return get(front); // front 위치 값 반환
    }
    int capacity() { return getCapacity(); } // 배열의 크기 리턴
    int length() { return (rear - front) % getCapacity(); } // 큐의 길이 리턴
};
int main() {
    MyQueue mQ(100);
    int n;
    cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mQ.enqueue(n); // 큐에 삽입
    }
    cout << "큐의 용량 : " << mQ.capacity() << ", 큐의 크기 : " << mQ.length() << endl;
    
    cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
    while (mQ.length() != 0) { // 길이가 0이 아닐 동안 반복
        cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
    }
    cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}