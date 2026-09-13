#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void push(int x) {
        if (rear == 99) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
    }

    void pop() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    int peek() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        return front > rear;
    }

    int size() {
        return rear - front + 1;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.peek() << '\n';

    q.pop();

    cout << q.peek() << '\n';
    cout << q.size() << '\n';
}