#include <iostream>
using namespace std;

struct NodeSK {
    int data; 
    NodeSK* link;
};

struct Stack {
    NodeSK* top;
};


void Init(Stack& s) {
    s.top = NULL;
}


bool stack_is_empty(const Stack& s) {
    return s.top == NULL;
}

void push(Stack& s, int x) {
    NodeSK* newNode = new NodeSK;
    newNode->data = x;
    newNode->link = s.top;
    s.top = newNode;
}


int pop(Stack& s) {
    if (stack_is_empty(s)) {
        cout << "Stack is empty" << endl;
        return -1; 
    }
    int topData = s.top->data;
    NodeSK* temp = s.top;
    s.top = s.top->link;
    delete temp;
    return topData;
}


bool stack_is_full() {
    return false; 
}


void printStack(Stack s) {
    while (!stack_is_empty(s)) {
        cout << pop(s) << " ";
    }
    cout << endl;
}

int main() {
    Stack s;
    Init(s);

    int A[] = {73, 89, 96, 99, 60, 55, 52, 66, 67, 79};

    for (int i = 0; i < 10; i++) {
        if (A[i] < A[0] && A[i] % 2 == 0) {
            if (!stack_is_empty(s)) {
                pop(s);
            }
        } else {
            if (!stack_is_full()) {
                push(s, A[i]);
            }
        }
    }
    printStack(s);

    return 0;
}

