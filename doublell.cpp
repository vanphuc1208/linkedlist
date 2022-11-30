#include <bits/stdc++.h>
using namespace std;

struct node{
	//du lieu
	int data;
	// lien ket : link
	node *next;//con tro luu dia chi
    node *prev;
};
node *makeNode(int x) {
    node* newNode= new node;
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
int SZ(node *head){
	int dem = 0;
	while(head != NULL){
		++dem;
		head = head->next;
	}
	return dem;
}
void duyet(node *head) {
    while(head!=NULL) {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void themdau(node*&head, int x) {
    node *newNode=makeNode(x);
    newNode->next=head;

    if (head !=NULL)head->prev=newNode;
    head=newNode;
}
void themcuoi(node *&head, int x) {
    node*newNode=makeNode(x);
    if(head==NULL) {
        head=newNode;
        return;
    }
    node *tmp=head;
    while(tmp->next != NULL) {
        tmp=tmp->next;
    }
    tmp->next=newNode;
    newNode->prev=tmp;
}
void themgiua(node *&head, int x, int k) {
    int n=SZ(head);
	 node*newNode=makeNode(x);
    if(k<1 || k>n) return;
	if(k==1) {
		themdau(head, x);
		return;
	}
    node *tmp=head;
    for(int i=1;i<=k-1;i++) {
        tmp=tmp->next;
    }
    newNode->next=tmp;
    tmp->prev->next=newNode;
    newNode->prev=tmp->prev;
    tmp->prev=newNode;
}
void xoadau(node *&head) {
	if(head==NULL) return;
	node *dnode=head;
	head=head->next;
	if(head!=NULL)head->prev=NULL:
	delete dnode;
}
void xoacuoi(node *&head) {
	if(head==NULL) return;
	node *tmp=head;
	if(head->next=NULL) {
		head=NULL;
		delete tmp;
		return;
	}
	while(tmp->next!=NULL) {
		tmp=tmp->next;
	}
	node*dnode=tmp;
	tmp->prev->next=NULL;
	delete dnode;

}
void xoagiua(node *&head, int k) {
	int n=SZ(head);
	if (k<1||k>n) return;
	if(k==1) xoadau(head);
	 node *tmp=head;
	 for(int i=1; i<=k-1;i++) {
		tmp=tmp->next;
	 }
	 node *dnode=tmp;
	 tmp->prev->next=tmp->next;
	 tmp->next->prev=tmp->prev;
	 delete dnode;
}
void sx(node *&head) {
	for(node *i=head; i !=NULL; i= i->next) {
       node *min=i;
	   for(node  *j=i->next; j!=NULL ;j=j->next) {
		if(min->data > j->data) min=j;
	   }
	   swap(min->data, i->data);
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
