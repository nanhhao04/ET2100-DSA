#include <iostream>
#include <cstring>
using namespace std; 
struct Ngay {
    int ngay, thang, nam; }; 
	
struct SinhVien {
    int maSV;
	char hoTen[50]; 
	int gioiTinh; 
	Ngay ngaySinh; 
	char diaChi[100]; 
	char lop[12]; 
	char khoa[7]; };


struct Node {
    SinhVien data; 
	Node* link; }; 

struct List {
    Node* first; 
	Node* last; };

void init_List (List* list) {
	list -> first = list -> last = 0; }
	
Node* Input (Node*& node) {
	cout << "Hay nhap thong tin cua sinh vien:" << endl;
	cout << "Ma sinh vien: "; 
	cin >> node->data.maSV;
	cin.ignore(); 
	cout << endl << "Ho va ten: "; 
	cin.getline (node->data.hoTen, 50); 
	cout << endl << "Gioi tinh (nhap 1 cho nam, 2 cho nu) : ";
	cin >> node->data.gioiTinh; 
	cin.ignore(); 
	cout << endl << "Ngay sinh: "; 
	cin >> node->data.ngaySinh.ngay;  
	cout << endl << "Thang sinh: "; 
	cin >> node->data.ngaySinh.thang; 
	cout << endl << "Nam sinh: "; 
	cin >> node->data.ngaySinh.nam; 
	cin.ignore(); 
	cout << endl << "Dia chi: "; 
	cin.getline (node->data.diaChi, 100); 
	cout << endl << "Lop: "; 
	cin.getline(node->data.lop, 12); 
	cout << endl << "Khoa: ";
	cin.getline (node->data.khoa, 7);
	cout << endl; 
	return node; }

void InsertionSort (List* list) {
	Node* p = list->first->link; 
	while (p != 0) {
	    Node* q = list -> first; 
	    while (q != p) {
	    	if (q->data.maSV > p->data.maSV) { 
	    	SinhVien temp2 = q->data; 
	    	q->data = p->data; 
	    	p->data = temp2; }
	    q = q->link; }
	    p = p->link; }
	}
	
void List_Insert (List* list) {
	char c;
	do {
	Node* newnode = new Node;
	if (list->first == 0) {
		list->first = list->last = Input (newnode); }
	else {list->last->link = Input (newnode);
	list -> last = newnode; }
	cout << "Nhap tiep (Y/N): ";
	cin >> c; 
	} 
	while (c != 'N' && c != 'n');
	InsertionSort (list); 
	}

void Output (Node* p) {
		cout << "Ma sinh vien: " << p->data.maSV << endl; 
		cout << "Ho va ten: " << p->data.hoTen << endl; 
		if (p->data.gioiTinh == 1) cout << "Gioi tinh: Nam" << endl; 
		else if (p->data.gioiTinh == 2) cout << "Gioi tinh: Nu" << endl; 
		cout << "Ngay thang nam sinh: " << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang <<"/"<< p->data.ngaySinh.nam << endl; 
		cout << "Dia chi: "<< p->data.diaChi<< endl; 
		cout << "Lop: "<<p->data.lop << endl; 
		cout << "Khoa: "<<p->data.khoa<< endl; 
		cout << endl; 
	}
void Whole_list_Output (List* list) {
        Node* p = list->first; 
        while (p != 0) {
        	Output (p); 
        	p = p->link; } }
        
void Sort_Samebirthday (List* list) {
	Node* p = list->first->link; 
	while (p != 0) {
	    Node* q = list -> first; 
	    while (q != p) {
	    	if (q->data.ngaySinh.ngay > p->data.ngaySinh.ngay) { 
	    	SinhVien temp2 = q->data; 
	    	q->data = p->data; 
	    	p->data = temp2; }
	    q = q->link; }
	    p = p->link; } 

void Find_Samebirthday (List* list) {
    Sort_Samebirthday (list);	
	int count = 0;
	p = list->first; 
	while (p != 0) {
		if (p->link!=0 && p->data.ngaySinh.ngay == p->link->data.ngaySinh.ngay) {
			count++;
			cout << "Sinh vien sinh cung ngay " <<p->data.ngaySinh.ngay<<" la:" << endl; 
			Output (p);
			while (p->link!=0 && p->data.ngaySinh.ngay == p->link->data.ngaySinh.ngay) {
				p = p->link; 
				Output(p) ;} }
		p = p->link; }
	if (count == 0) cout << "Khong co sinh vien nao cung ngay sinh"<< endl; 
	}
				

int main () {
	List list1; 
	init_List (&list1);
	List_Insert(&list1);  
	Whole_list_Output(&list1);
	Find_Samebirthday (&list1); 
	}
