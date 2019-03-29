#include <iostream>
using namespace std;

struct TNode {
        int data;
        TNode *next;
};
TNode *head, *tail, *data1, *baru, *bantu;

void tambahdepan();
void tambahbelakang();
void cetak();

int main(){
    data1 = new TNode;
    data1->data = 2;
    data1->next = NULL;
    head = data1;
    tail = data1;
    tambahdepan();
    tambahbelakang();
    cetak();
}

void tambahdepan(){
    baru = new TNode;
    baru->data = 4;
    baru->next = NULL;
    baru->next = head;
    head = baru;
}

void tambahbelakang(){
    baru = new TNode;
    baru->data =5;
    baru->next = NULL;
    baru = tail;
    tail = baru;
}

void cetak(){
    bantu = head;
    int jumlah=1;
	while(bantu != NULL){
            jumlah=jumlah+1;
		cout<<bantu->data<<" -> "<<bantu->data;
		bantu=bantu->next;
	}

	if (bantu == NULL){
		cout << "NULL";
	}
}

