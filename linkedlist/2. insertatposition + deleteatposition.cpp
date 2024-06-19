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
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty" << endl;
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
            cout << "Position out of bounds" << endl;
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
};
int main(){
    int n,k;
    cin>>n;
    linkedlist l;
    for(int i=0; i<n; i++){
        int value;
        cin >> value;
        l.addelementatend(value);
    }
    cin >> k;
    l.deleteAtPosition(k);
    l.printList();
}
