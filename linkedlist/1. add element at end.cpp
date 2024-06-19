#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head; // node head
    LinkedList() { 
    head = NULL; // khai báo head là null
    }
// hàm chèn vào cu?i ll
    void insertAtEnd(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
// hàm chèn v? trí b?t kì
    void insertAtPosition(int newData, int position) {
        Node* newNode = new Node;
        newNode->data = newData;
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "vi tri nam ngoai gioi han" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n, x, k;
    cin >> n;
    
    LinkedList l;// khai báo ll l
    
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        l.insertAtEnd(value);//nh?p các giá tr? và chèn vào cu?i ll
    }
    
    cin >> k >> x;
    l.insertAtPosition(x, k);
    l.printList();

    return 0;
}
