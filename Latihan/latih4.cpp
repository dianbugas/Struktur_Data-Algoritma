#include <iostream>
using namespace std;


void tambahBaru();
void cetak();
void tambahTengah(int pos, int data);
void hapusTengah(int pos);
struct node {
	int data;
	node* next;
};

node *data1, *entry, *head, *tail, *bantu, *prev, *curr;

int main (){
	int pos, data;
	data1 = new node;
	data1->data = 1;
	data1->next = NULL;
	head = data1;
	tail = data1;

	while(true){
		int pilih;
		cout << "[1] Input di belakang" << endl;
		cout << "[2] Tambah tengah" << endl;
		cout << "[3] Cetak" << endl;
		cout << "[4] Hapus belakang" << endl;
		cout << "[5] Hapus tengah" << endl;
		cout << "Masukkan pilihan : "; cin >> pilih;

		switch(pilih){
			case 1 : tambahBaru();
				break;
			case 2 : cetak();
				cout << "Input posisinya : "; cin >> pos;
				cout << "Input Datanya : "; cin >> data;
				tambahTengah(pos, data);
				break;
			case 3 : cetak ();
				break;
			//case 4 : hapusBelakang();
				break;
			case 5 :
				cout << "posisi yang ingin di hapus : "; cin >> pos;
				hapusTengah(pos);
				break;
			default : cout << "inputan salah" << endl;
				break;
		}
	}


//	tambahBaru();
//	cetak();

}

void tambahBaru(){
	int a;

	cout << "Input data : "; cin >> a;
	entry = new node;
	entry->data = a;
	entry->next = NULL;
	tail->next = entry;
	tail = entry;
}

void cetak(){
	bantu = head;
	while(bantu!=NULL){
		cout<<bantu->data<<" -> ";
		bantu=bantu->next;
	}

	if (bantu == NULL){
		cout << "NULL" << endl;
	}
}
void tambahTengah(int pos, int data) {
	entry = new node;
	curr = head;
	for (int i=1; i<pos; i++){
		prev = curr;
		curr = curr->next;
	}

	entry->data = data;
	prev->next = entry;
	entry->next = curr;
}
void hapusTengah(int pos){
	curr = head;
	for (int i=1; i<pos; i++){
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	//delete curr
}

