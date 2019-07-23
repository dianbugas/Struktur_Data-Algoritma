#include <iostream>
using namespace std;

void menu();
int jlhData();
bool isEmpty();
bool isFull();
void enqueue();
void dequeue();
void clear();
void read();
//aauuzzaannnnn

struct node{
	int data;
	node *next;
};

node *head = NULL, *tail = NULL, *entry, *temp;

int main(){
	char ulang;
	do{
		system("cls");
		menu(); //aaauuuzaaan
		cout<<"\nKembali ke menu?(y/n)";
      	cin>>ulang;
      	
	} while (ulang=='y' || ulang=='Y');
}

void menu(){
	int pilih;
	cout << "======== Menu Queue ========" << endl;
	cout << "[1] Input Data" << endl;
	cout << "[2] Hapus Data" << endl;
	cout << "[3] Hapus Seluruh Data" << endl;
	cout << "[4] Jumlah Data" << endl; 
	cout << "[5] Tampilkan Data" << endl;
	cout << "[6] Exit" << endl; //auzaan
	cout << "Masukkan pilihan : ";
	cin >> pilih;
	switch(pilih){
		case 1 : 
			enqueue();
			break;
		case 2 :
			dequeue();
			break;
		case 3 :
			clear();
			break;
		case 4 :
			cout << "\nJumlah Data = " << jlhData() << endl;
			break;
		case 5 :
			read();
			break;
		case 6 :
			exit(0);
			break;
		default : 
			//auzzzann
			cout << "\nInputan salah, coba lagi" << endl;
	}
}

int jlhData(){
	int jlh = 0;
	temp = head; //auuuzzzan
	while (temp != NULL){
		temp = temp->next;
		jlh++;
	}
	
	return jlh;
}

bool isEmpty(){
	if (head == NULL){
		return true;
	} else { //aauzzan
		return false;
	}
}

bool isFull(){
	if (jlhData() == 10){
		return true;
	} else { //auuuzzaan
		return false;
	}
}

void enqueue(){
	int a;
	if (isFull()){
		cout << "\nData sudah penuh" << endl;
	}
	else { 
		cout << "\nMasukkan data : "; cin >> a;
		entry = new node; //aaaauuuzannn
		entry->data = a;
		entry->next = NULL;
		if (head == NULL){
			head = entry;
			tail = entry;
		} else { //aauzzann
			tail->next = entry;
			tail = entry;
		}
	}
}

void dequeue(){
	if (isEmpty()){
		cout << "\nTidak tidak ada" << endl;
	}
	else {
		temp = head;
		head = temp->next; //auuzaan
		cout << "\nData " << temp->data << " dihapus" << endl;
		delete temp;
	}
}

void clear(){
	if (isEmpty()){
		cout << "\nTidak tidak ada" << endl;
	}
	else {
		temp = head; //auzannnn
		while (temp != NULL){
			head = temp->next;
			delete temp;
			temp = head;
		}
	}
}

void read(){
	if (isEmpty()){
		cout << "\nTidak tidak ada" << endl;
	}
	else{
		temp = head;
		cout<<"\nData yang ada dalam stact adalah"<<endl;
		while (temp != NULL){ //aaaauuzzaaaan
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL";
		cout << endl;
	}
}


