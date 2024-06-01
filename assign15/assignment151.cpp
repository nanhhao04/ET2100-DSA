#include <iostream>
using namespace std;

// Kieu cua cac nut tren cay (chua so nguyen).
struct Node {
    int value; // gia tri nut
    Node* left; // Con tro toi nut con trai
    Node* right; // Con tro toi nut con phai

    // Ham tao.
    Node(int v, Node* l = NULL, Node* r = NULL)
        : value(v), left(l), right(r) {}
};

// Lop cay nhi phan tim kiem.
class BSTree {
private:
    Node* root;

public:
    // Ham tao (ban dau cay rong).
    BSTree() : root(NULL) {}

    // Ham huy (xoa het cac nut tren cay).
    ~BSTree() {
        makeEmpty();
    }

    // Kiem tra cay co rong hay khong.
    bool isEmpty() const {
        return root == NULL;
    }

    // Xoa het cac nut tren cay.
    void makeEmpty() {
        makeEmpty(root);
    }

    // Chen mot nut val1 moi vao cay.
    void insert(int val1) {
        insert(val1, root);
    }

    // Tim nut val2
    Node* search(int val2) {
        return search(val2, root);
    }

    // Duyet in cay
    void printTree(ostream& out = cout) const {
        if (isEmpty())
            out << "Empty tree" << endl;
        else
            printTree(root, out);
    }

private:
    // Xoa rong cay (viet theo kieu de quy).
    void makeEmpty(Node*& t) {
        if (t == NULL)
            return;

        makeEmpty(t->left); // Xoa rong cay con trai
        makeEmpty(t->right); // Xoa rong cay con phai
        delete t; // Xoa nut goc
        t = NULL; // Khong con nut goc de tro den, phai cho t thanh NULL
    }

    // Chen mot nut val1 moi vao cay (viet theo kieu de quy).
    void insert(int val1, Node*& t) {
        if (t == NULL) // Cay dang rong thi nut moi se thanh nut goc
            t = new Node(val1);
        else if (val1 < t->value)
            insert(val1, t->left);
        else if (val1 > t->value)
            insert(val1, t->right);
        // Neu val1 da ton tai trong cay thi khong lam gi ca
    }

    // Tim nut co gia tri cho truoc (viet theo kieu de quy).
    Node* search(int val2, Node* t) const {
        if (t == NULL)
            return NULL;

        if (val2 < t->value)
            return search(val2, t->left);
        else if (val2 > t->value)
            return search(val2, t->right);
        else
            return t;
    }

    void printTree(Node* t, ostream& out) const {
        if (t != NULL) {
            printTree(t->left, out);
            out << t->value << " ";
            printTree(t->right, out);
        }
    }
};

void PREORDER_travl(Node* t) {
    if (t != NULL) {
        cout << t->value << " ";
        PREORDER_travl(t->left);
        PREORDER_travl(t->right);
    }
}

int main() {
    BSTree bst;

    // Chen cac node co gia tri duoi day .
    bst.insert(5);
    bst.insert(6);
    bst.insert(3);
    bst.insert(8);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);

    Node* root = bst.search(5);

    cout << "Duyet cay thu tu truoc" << endl;
    PREORDER_travl(root);
    cout << endl;

    // Tim hai node co gia tri 4 va 9.
    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);

    // In ket qua tim kiem
    if (n1 != NULL)
        cout << "Node co gia tri = 4 la " << n1->value << endl;
    if (n2 == NULL)
        cout << "Khong tim thay node co gia tri = 9" << endl;

    // Lam rong cay.
    bst.makeEmpty();

    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;

    return 0;
}

