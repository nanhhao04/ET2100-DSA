#include <iostream>
using namespace std; 

template <typename T>
class Vector {
public:

Vector(int initCapacity = 16) {
size = 0;
capacity = initCapacity;
array = new T[capacity]; }

~Vector() {
delete[] array;}

Vector& operator=(Vector& rhs) {
if (this != &rhs) {
delete[] array; 
size = rhs.size; 
capacity = rhs.capacity;
array = new T[capacity]; 
for (int i = 0; i < size; i++) {
array[i] = rhs.array[i];}
}
return *this; 
}

int getSize(){
return size;}

bool isEmpty(){
return (size == 0);}

T& operator[](int index){
return array[index];}

void pushBack(T newElement) { 
    if (size == capacity) expand (capacity++);
    size++;  
    array[size-1] = newElement; 
}

void insert(int pos, T newElement){
    if (size==capacity) expand(capacity++); 
    size++; 
    for (int i = size-1; i>pos-1; i--) {
        array[i] = array[i-1]; 
    }
    array[pos] = newElement; 
}

void popBack() {
size--;
}

void clear() {
size = 0;
}

void erase(int pos) {
size--;
for (int i = pos; i<size; i++) {
    array[i] = array[i+1]; 
}
}

void print() {
for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
    cout << endl; }
}

private:
int size;
int capacity; 
T * array; 

void expand(int newCapacity) {
if (newCapacity <= size) return;
T * old = array; 
array = new T[newCapacity]; 
for (int i = 0; i < size; i++) {
array[i] = old[i]; }
delete[] old; 
capacity = newCapacity; 
}
};

int main() {
Vector<int> v;
v.pushBack(6);
v.pushBack(2);
v.pushBack(9);
v.pushBack(1);
v.pushBack(8);
cout << "Cac phan tu: ";
v.print();
cout << "Kich thuoc: " << v.getSize() << endl;
v.insert(2, 7);
cout << "Sau khi chen 7 vao vi tri 2: ";
v.print();
v.popBack();
v.erase(1);
cout << "Sau khi xoa 8 va 2: ";
v.print(); 
return 0;
}

