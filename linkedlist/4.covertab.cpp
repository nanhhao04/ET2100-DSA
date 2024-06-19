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
void convert(int a, int b) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == a) {
                temp->data = b;
            }
            temp = temp->next;
        }
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
    int a,b;
    cin >> a >> b;
    l.convert(a,b);
    l.printList();
}

