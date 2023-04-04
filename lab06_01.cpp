#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == MAX_SIZE - 1;
    }

    void push(int x) {
        if (is_full()) {
            cout << "Error: Stack is full!" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (is_empty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int stack_top() {
        if (is_empty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (is_empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};