#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node *insert(node *t, int x){
	if (t == NULL){
		node *temp = new node;
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else {
		if (x < t->data){
			t->left = insert(t->left, x);
		} else {
			t->right = insert(t->right, x);
		}
	}
	return t;
}

bool isLeafNode(node *l){
	return (l->left == NULL && l->right == NULL);
}

int treeLevel(node *t){
	if (t == NULL) return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

bool checkAvl(node *t){
	if (t == NULL) return true;
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
}

int main(){
	int n, temp;
	cin >> n;
	node *t = NULL;
	for (int i = 0; i < n; i++){
		cin >> temp;
		t = insert(t, temp);
	}
	// Chuy?n d?i d?u ra t? 0, 1 sang false, true
	cout << (checkAvl(t) ? "true" : "false") << endl;

	return 0;
}
