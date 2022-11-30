#include <bits/stdc++.h>
using namespace std;

struct node{
	//du lieu
	int data;
	// lien ket : link
	node *next;//con tro luu dia chi
};

node* makeNode(int x){
	node *newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//duyet danh sach lien ket
void duyet(node *head){
	cout << "DSLK : ";
	while(head != NULL){
		cout << head->data << " ";
		head = head->next; // di chuyen node hien tai sang node ke tiep
	}
	cout << endl;
}

//dem kich thuoc
int SZ(node *head){
	int dem = 0;
	while(head != NULL){
		++dem;
		head = head->next;
	}
	return dem;
}

//Them node : dau, cuoi, giua
void themdau(node *&head, int x){
	node *newNode = makeNode(x);
	//cho node moi luu dia chi cua node dau tien trong dslk
	newNode->next = head;
	head = newNode;
}

//Them cuoi
void themcuoi(node *&head, int x){
	node *newNode = makeNode(x);
	if(head == NULL){
		head = newNode; return;
	}
	//lan tu dau
	node *tmp = head; // NULL
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	//tmp : node cuoi
	tmp->next = newNode;
}

//Them giua
void themgiua(node *&head, int x, int k){
	node *newNode = makeNode(x);
	node *tmp = head;
	int n = SZ(head);
	if(k < 1 || k > n){
		return; // vi tri chen ko hop le
	}
	if(k == 1){
		themdau(head, x); return;
	}
	for(int i = 1; i <= k - 2; i++){
		tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
}

void xoadau(node *&head){
	if(head == NULL) return;
	node *firstNode = head;
	head = head->next;
	delete firstNode;
}

void xoacuoi(node *&head){
	if(head == NULL) return;
	node *tmp = head;
	if(head->next == NULL){
		// co 1 node
		delete head;
		head = NULL; return;
	}
	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}
	node *lastNode = tmp->next;
	tmp->next = NULL;
	delete lastNode;
}

void xoagiua(node *&head, int k){
	int n = SZ(head);
	if(k < 1 || k > n) return;
	if(k == 1){
		xoadau(head); return;
	}
	node *tmp = head;
	for(int i = 1; i <= k - 2; i++){
		tmp = tmp->next;
	}
	node *kNode = tmp->next; // node thu k
	tmp->next = tmp->next->next;
	delete kNode;
}
void sx(node *&head) {
	for(node *i=head; i!= NULL;i=i->next) {
		node*min=i;
		for(node *j=i->next;j!=NULL;j=j->next) {
			if(j->data < min->data) min=j;
		}
		swap(min->data,i->data);
	}
}

int main(){
	node *head = NULL;
	while(1){
		cout << "---------------------MENU---------------------\n";
		cout << "1. Them 1 node vao dau DSLK\n";
		cout << "2. Them 1 node vao cuoi DSLK\n";
		cout << "3. Them 1 node vao giua DSLK\n";
		cout << "4. Xoa dau\n";
		cout << "5. Xoa cuoi\n";
		cout << "6. Xoa giua\n";
		cout << "7. Duyet\n";
		cout << "0. Thoat !\n";
		cout << "----------------------------------------------\n";
		int lc; cout << "Nhap lua chon : ";
		cin >> lc;
		if(lc == 1){
			cout << "Nhap gia tri can them : ";
			int x; cin >> x; 
			themdau(head, x); 
		}
		else if(lc == 2){
			cout << "Nhap gia tri can them : ";
			int x; cin >> x; 
			themcuoi(head, x); 
		}
		else if(lc == 3){
			cout << "Nhap gia tri can them : ";
			int x; cin >> x; 
			cout << "Nhap vi tri chen :";
			int k; cin >> k;
			themgiua(head, x, k); 
		}
		else if(lc == 4){
			xoadau(head);
		}
		else if(lc == 5){
			xoacuoi(head);
		}
		else if(lc == 6){
			cout << "Nhap vi tri xoa :";
			int k; cin >> k;
			xoagiua(head, k);
		}
		else if(lc == 7){
			duyet(head);
		}
		else if(lc == 0){
			break;
		}
	}
	return 0;
}
