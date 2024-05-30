#define maxlength 100
#include <iostream>
#include <cmath>
using namespace std; 

struct Tree {
    int Data[maxlength]; 
    int flag[maxlength];
}; 


int Left_Child (Tree T, int p){
    return 2*(p+1)-1;
}

int Right_Child (Tree T, int p){
    return 2*(p+1); 
}

void AddTree (Tree& T, int p, int a){
    T.Data[p] = a;
    T.flag[p] = 1;
}

void LRN (Tree T, int p) {
    if (T.flag[p] == 1) {
        LRN (T, Left_Child(T,p)); 
        LRN (T, Right_Child(T,p));
        cout << T.Data[p]<<" ";  
    }
}

void LNR (Tree T, int p) {
    if(T.flag[p]==1) {
        LNR (T, Left_Child(T,p));   
        cout << T.Data[p]<<" ";
        LNR (T, Right_Child(T,p));
    }
}

void NLR (Tree T, int p) {
    if(T.flag[p]==1) {
        cout << T.Data[p]<<" ";
        NLR (T, Left_Child(T,p));   
        NLR (T, Right_Child(T,p));
    }
}

void CreateHeap(Tree& T, int i, int n) {
    int j = (2 * i) + 1; 
    int key = T.Data[i];
    while (j <= (n - 1)) 
	{
        if ((j < n - 1) && (T.Data[j] < T.Data[j + 1])) { j = (j + 1); }
        if (key > T.Data[j]) {
            T.Data[(int)floor((j - 1) / 2)] = key;
        }
        else { 
				T.Data[(int)floor((j - 1) / 2)] = T.Data[j]; 
				T.Data[j] = key;
			 }
        key = T.Data[j];
        j = j * 2 + 1;
    }
}

void output (Tree T) {
    for (int i = 0; i < 10; i++) {
        cout << T.Data[i] << " ";
    }
}

void heapsort(Tree& T, int n) {
    for (int i = (n - 1) / 2; i >= 0; i--) {
        CreateHeap(T, i, n - 1);
        output (T);
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--) {
        swap(T.Data[0], T.Data[i]);
        CreateHeap(T, 0, i);
        output (T);
        cout << endl;
    }
}



int main () {
    Tree T1; 
    AddTree (T1, 0, 4);
    AddTree (T1, 1, 1);
    AddTree (T1, 2, 3); 
    AddTree (T1, 3, 2); 
    AddTree (T1, 4, 16); 
    AddTree (T1, 5, 9); 
    AddTree (T1, 6, 10); 
    AddTree (T1, 7, 14); 
    AddTree (T1, 8, 8); 
    AddTree (T1, 9, 7); 
    heapsort(T1, 10);
    }
