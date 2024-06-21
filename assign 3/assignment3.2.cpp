#include <iostream>
#include <cmath>
using namespace std;

struct NodeDT {
float heso;
int somu;
NodeDT* link;
};
struct ListDT {
NodeDT* fist, * last;
};
//khoi tao danh sach da thuc
void initDT(ListDT *lDT) {
lDT->fist = NULL;
lDT->last = NULL;
}
//tao mot node moi
NodeDT* callNode(float hs,int sm) {
NodeDT* p;
p = new NodeDT;
if (p == NULL) return NULL;
p->heso = hs;
p->somu = sm;
p->link = NULL;
return p;
}
//Gan Node p vao danh sach
void addNode(ListDT* lDT, NodeDT*p) {
if (lDT->fist == NULL) //DS rong
{
lDT->fist = lDT->last = p;
}
else
{
lDT->last->link = p; //gan dia chi nut cuoi bang p

lDT->last = p; //chuyen p thanh nut cuoi

}

}

//them node voi he so va so mu cho truoc

void attachNode(ListDT*lDT, float hs, int sm) {

NodeDT* pDT = callNode(hs,sm);

if (pDT == NULL) return;

addNode(lDT, pDT);

}

//tao da thuc

void taoDT(ListDT *lDT) {

float hs;

int sm = 0;

//int sm;

int i = 0; //dem so phan tu

cout << "-Bat dau nhap da thuc (nhap he so 0 de ket thuc): " << endl;

do

{

i++;

cout << "Nhap so phan tu thu " << i << endl;

cout << "\nSo mu " << sm;

cout << "\nNhap he so = ";

cin >> hs;

if (hs == 0) break;

//cout << "\nNhap so mu = ";

//cin >> sm;

attachNode(lDT, hs, sm);

sm++;

} while (hs != 0);

cout << "ket thuc nhap" << endl;

}

void inDT(ListDT lDT) {

NodeDT* p;

p = lDT.fist;

cout << "\nf(x) = ";

while (p != NULL) {

cout << p->heso << " * x^" << p->somu;

if (p->link != NULL && p->heso!= 0) cout << " + ";

p = p->link;

}

}

// cong da thuc : DT3 = DT1 +
void congDT(ListDT DT1, ListDT DT2, ListDT &DT3) {
    NodeDT *p1 = DT1.fist;
    NodeDT *p2 = DT2.fist;
    DT3.fist = NULL;
    DT3.last = NULL;
    bool isFirstTerm = true;

    cout << "\nKet qua cong hai da thuc: f(x) = ";

    while (p1 != NULL || p2 != NULL) {
        float hs;
        int sm;

        if (p1 != NULL && p2 != NULL && p1->somu == p2->somu) {
            hs = p1->heso + p2->heso;
            sm = p1->somu;
            p1 = p1->link;
            p2 = p2->link;
        }
        else if (p1 != NULL && (p2 == NULL || p1->somu > p2->somu)) {
            hs = p1->heso;
            sm = p1->somu;
            p1 = p1->link;
        }
        else {
            hs = p2->heso;
            sm = p2->somu;
            p2 = p2->link;
        }

        NodeDT *pDT = callNode(hs, sm);
        if (pDT == NULL) return;

        addNode(&DT3, pDT);

        
        if (hs != 0) {
            if (!isFirstTerm) {
                if (hs > 0) cout << " + ";
                else cout << " - ";
            }
            cout << abs(hs) << " * x^" << sm;
            isFirstTerm = false;
        }
    }

    if (isFirstTerm) cout << "0"; 
}




int main()
{

ListDT DT1;

initDT(&DT1);

taoDT(&DT1);

inDT(DT1);

cout << "\n";

ListDT DT2;

initDT(&DT2);

taoDT(&DT2);

inDT(DT2);

cout << "\n";

ListDT DT3;
congDT( DT1,  DT2, DT3);

}
