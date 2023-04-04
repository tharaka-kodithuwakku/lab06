#include <iostream>
#include <chrono>
using namespace std;

const int MAX_SIZE = 100000;

// Array implementation of Stack
class StackArray {
private:
    int arr[MAX_SIZE];
    int top;

public:
    StackArray() {
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

// Linked List implementation of Stack
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class StackLL {
private:
    Node* top;

public:
    StackLL() {
        top = NULL;
    }

    bool is_empty() {
        return top == NULL;
    }

    void push(int x) {
        Node* new_node = new Node(x);
        new_node->next = top;
        top = new_node;
    }

    int pop() {
        if (is_empty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1;
        }
        Node* temp = top;
        int val = top->data;
        top = top->next;
        delete temp;
        return val;
    }

    int stack_top() {
        if (is_empty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if (is_empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* curr = top;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    // Array implementation
    StackArray sa;

    auto start_time = chrono::high_resolution_clock::now();

    sa.push(8);
    sa.push(10);
    sa.push(5);
    sa.push(11);
    sa.push(15);
    sa.push(23);
    sa.push(6);
    sa.push(18);
    sa.push(20);
    sa.push(17);
    sa.display();
    sa.pop();
    sa.pop();
    sa.pop();
    sa.pop();
    sa.pop();
    sa.display();
    sa.push(4);
    sa.push(30);
    sa.push(3);
    sa.push(1);
    sa.display();

    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Time taken for Array implementation: " << duration.count() << " microseconds" << endl;

    // Linked List implementation
    StackLL sll;

    start_time = chrono::high_resolution_clock::now();

    sll.push(8);
    sll.push(10);
    sll.push(5);
    sll.push(11);
    sll.push(15);
    sll.push(23);
    sll.push(6);
    sll.push(18);
    sll.push(20);
    sll.push(17);
    sll.display();
    sll.pop();
    sll.pop();
    sll.pop();
    sll.pop();
    sll.pop();
    sll.display();
    sll.push(4);
    sll.push(30);
    sll.push(3);
    sll.push(1);
    sll.display();

    end_time = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Time taken for Linked List implementation: " << duration.count() << " microseconds" << endl;

    return 0;
}
