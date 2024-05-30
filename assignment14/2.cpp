#include <iostream>
using namespace std; 

struct Node {
	int data; 
	Node* left; 
	Node* right; 

Node (int val) {
	data = val; 
	left = NULL; 
	right = NULL; }
};

void NLR (Node* node) {
	if (node != NULL) {
		cout << node->data << " "; 
		NLR (node->left); 
		NLR (node->right); }
	}
		
void LNR (Node* node) {
	if (node != NULL) {
		LNR (node->left); 
		cout << node->data<< " "; 
		LNR (node->right); }
	}

void LRN (Node* node) {
	if (node!= NULL) {
		LRN (node->left); 
		LRN (node->right); 
		cout << node->data<<" "; }
	}
