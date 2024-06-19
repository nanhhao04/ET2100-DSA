#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
struct linkedlist{
    Node* head;
    
    linkedlist() {
    head = NULL;
    }

void addelementatend(int newData ){
    Node* newNode= new Node;
    newNode->data = newData;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return ;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        }
    temp->next = newNode;
    }
void insertatposition(int newData, int position){
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
            cout << "vi tri gioi han" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "list empty" << endl;
            return;
        }
        Node* temp = head;
        if (position == 0) {
            head = temp->next;
            delete temp;
            return;
        }
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "vi tri gioi han" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

void printAtPosition(int position) {
        Node* temp = head;
        for (int i = 0; i < position && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "vi tri gioi han" << endl;
        } else {
            cout <<  temp->data << endl;
        }
    }
    // swap các giá tr? a thành b
void convert(int a, int b) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == a) {
                temp->data = b;
            }
            temp = temp->next;
        }
    }
    //xóa ph?n t? l?n hon a
   void deleteelement(int a) {
        while (head != NULL && head->data > a) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data > a) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            } else {
                temp = temp->next;
            }
        }
    }
void hama(int n){
    linkedlist l;
    for(int i=n; i>0; i--){
        l.addelementatend(i);
    }
    for(int i=1;i<=n;i++){
        l.addelementatend(i);
    }
    l.printList();
}
void printFromIndex(int k, int n) {
        if (head == NULL) return;

        // Tìm node t?i ch? s? k
        Node* temp = head;
        for (int i = 0; i < k; i++) {
            temp = temp->next;
        }

        // In t? ch? s? k d?n n-1
        Node* start = temp;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != start);

        // In t? ch? s? 0 d?n k-1
        temp = head;
        for (int i = 0; i < k; i++) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};


int main(){
    int n,k;
    cin >> n;
    linkedlist l;
    for(int i = 0; i<n; i++){
        int value;
        cin >> value;
        l.addelementatend(value);
    }
    cin >> k;
    l.printFromIndex(k,n);
    l.printList();
}


