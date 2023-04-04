#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
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
