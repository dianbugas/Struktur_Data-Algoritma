#include <iostream>
using namespace std;

void inputbelakang();
void inputbaru();
void cetak();

struct node{
	int data;
	node* next;
	node* prev;
};

node *head, *tail, *entry, *curr, *bantu;

int main(){
	int pilih;
	head = NULL;
	tail = NULL;
	while(true){
	cout<<"[1] Input belakang" <<endl;
	cout<<"[2] Cetak Data"<<endl;
	cout<<"masukkan pilihan : "; cin>>pilih;

		switch(pilih){
			case 1 : inputbelakang();
			break;
			case 2 : cetak();
			break;
			default :
				cout <<"input salah" <<endl;
				break;
			}
	}
}


void inputbelakang(){
	int nilai;
	cout<<"input nilai : "; cin>>nilai;
	entry = new node;
	entry->data = nilai;
	entry->next = NULL;
	entry->prev = NULL;
	if(head == NULL){
		head = entry;
		tail = entry;
	}else{
		entry->prev = tail;
		tail->next = entry;
		tail = entry;
	}
}

void cetak(){
	bantu = head;
	while(bantu!=NULL){
		cout<<bantu->data<<"<->";
		bantu=bantu->next;
	}
	if (bantu==NULL){
		cout<<"NULL"<<endl;
	}
}
