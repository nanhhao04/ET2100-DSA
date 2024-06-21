#include <iostream>
#include <string>
using namespace std;

struct Node {
    int sbd; // So bao danh 
    string hoTen; // Ho ten sinh vien 
    Node* left; // Con tro toi nut con trai 
    Node* right; // Con tro toi nut con phai

    // Ham tao. 
    Node(int v, Node* l, Node* r){
       value = v;
       left = l;
        right = r;
}
};

// Lop cay nhi phan tim kiem. 
class BSTree {
public:
    // Ham tao (ban dau cay rong). 
    BSTree() : root(NULL) {}

    // Ham huy (xoa het cac nut tren cay). 
    ~BSTree() {
        makeEmpty();
    }

    // Kiem tra cay co rong hay khong. 
    bool isEmpty()  {
        return (root == NULL);
    }

    // Xoa het cac nut tren cay. 
    void makeEmpty() {
        makeEmpty(root);
    }

    // Chen mot sinh vien moi vao cay. 
    void insert(int sbd, string hoTen) {
        insert(sbd, hoTen, root);
    }

    // Tim sinh vien theo so bao danh. 
    Node* search(int sbd) const {
        return search(sbd, root);
    }

private:
    Node* root; // Con tro toi nut goc cua cay 

    // Xoa rong cay (viet theo kieu de quy). 
    void makeEmpty(Node*& t) {
        if (t == NULL) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = NULL;
        }
    }

    // Chen mot sinh vien moi vao cay (viet theo kieu de quy). 
    void insert(int sbd, string hoTen, Node*& t) {
        if (t == NULL) {
            t = new Node(sbd, hoTen);
        }
        else if (sbd < t->sbd) {
            insert(sbd, hoTen, t->left);
        }
        else if (sbd > t->sbd) {
            insert(sbd, hoTen, t->right);
        }
        else 
            
             ;
    }

    // Tim sinh vien theo so bao danh (viet theo kieu de quy). 
    Node* search(int sbd, Node* t) const {
        if (t == nullptr || t->sbd == sbd) {
            return t;
        }
        else if (sbd < t->sbd) {
            return search(sbd, t->left);
        }
        else {
            return search(sbd, t->right);
        }
    }
};

int main() {
    BSTree bst;

    // Chen mot so sinh vien moi vao cay.
    bst.insert(5, "Tuan");
    bst.insert(6, "Lan");
    bst.insert(3, "Cong");
    bst.insert(8, "Huong");
    bst.insert(7, "Binh");
    bst.insert(4, "Hai");
    bst.insert(2, "Son");

    // Tim hai sinh vien co so bao danh 4 va 9.
    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);

    // In ket qua tim kiem
    if (n1 != nullptr)
        cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
    else
        cout << "Khong tim thay sinh vien voi SBD=4" << endl;

    if (n2 == nullptr)
        cout << "Khong tim thay sinh vien voi SBD=9" << endl;
    else
        cout << "Sinh vien voi SBD=9 la " << n2->hoTen << endl;

    // Lam rong cay.
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;

    return 0;
}

