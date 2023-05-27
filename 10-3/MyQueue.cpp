/***************************************************************/
/*             HW#7 : ������ �Լ� ���                         */
/*  �ۼ��� : ȫ�浿                    ��¥ : 2023�� 5�� 20��  */
/*                                                             */
/* ���� ���� :    BaseArray Ŭ������ ��ӹ޾� ťó�� �۵��ϴ�  */
/*                MyQueue Ŭ���� �ۼ�            */
/***************************************************************/

#include <iostream>
using namespace std;
class BaseArray {
private:
    int capacity; // ���� �Ҵ�� �޸� �뷮
    int* mem; // ���� �迭�� ����� ���� �޸� ������
protected:
    BaseArray(int capacity = 100) {
        this->capacity = capacity; mem = new int[capacity]; // �뷮���� �迭 �Ҵ�
    }
    ~BaseArray() { delete[] mem; } // ���� �Ҵ��� �޸� ����
    void put(int index, int val) { mem[index] = val; } // index��ġ�� �� ����
    int get(int index) { return mem[index]; } // index��ġ �� ��ȯ
    int getCapacity() { return capacity; } // �뷮 ��ȯ
};
class MyQueue : protected BaseArray { // ���� ť ���
    int front; // ù ��° ��ҷκ��� �ð� �������� �ϳ� ��
    int rear; // ������ ���
public:
    MyQueue(int capacity) : BaseArray(capacity) { front = rear = 0; } // front�� rear �ʱ�ȭ
    void enqueue(int n) { // ť�� ����
        rear = (rear + 1) % getCapacity(); // rear ��ġ�� �� ĭ �ڷ� �̵�
        put(rear, n); // rear ��ġ�� �� ����
    }
    int dequeue() { // ť�� �ִ� �����͸� ����
        front = (front + 1) % getCapacity(); // front ��ġ�� �� ĭ �ڷ� �̵�
        return get(front); // front ��ġ �� ��ȯ
    }
    int capacity() { return getCapacity(); } // �迭�� ũ�� ����
    int length() { return (rear - front) % getCapacity(); } // ť�� ���� ����
};
int main() {
    MyQueue mQ(100);
    int n;
    cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mQ.enqueue(n); // ť�� ����
    }
    cout << "ť�� �뷮 : " << mQ.capacity() << ", ť�� ũ�� : " << mQ.length() << endl;
    
    cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
    while (mQ.length() != 0) { // ���̰� 0�� �ƴ� ���� �ݺ�
        cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
    }
    cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}