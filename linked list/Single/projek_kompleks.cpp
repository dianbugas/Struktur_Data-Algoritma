#include<iostream>
using namespace std;

//deklarasi fungsi
bool apakahKosong();
void tambahdepan(int depan);
void tambahtengah(int pos, int data);
void tambahbelakang();
void hapusdepan(int pos);
void hapustengah(int pos);
void hapusbelakang(int pos);
//cetak
void cetak();

//deklarasi struct
struct node{
	int data;
	node* next;
};

node *data1, *entry, *head, *tail, *bantu, *curr, *prev;

int main (){
	//untuk tambah tengah
	int pos, data, depan;
	//data kepala
	data1 = new node;
	data1->data = 1;
	data1->next = NULL;
	head = data1;
	tail = data1;
	//pengulangannya
	while(true){
	int pilih;
	cout << "[1] Tambah Belakang" << endl; //suskses
	cout << "[2] Tambah Tengah" <<endl; //suskses
	cout << "[3] Tambah Depan" << endl;//suskses
	cout << "[4] Hapus belakang"<< endl; //suskses
	cout << "[5] Hapus Tengah"<<endl; //suskses
	cout << "[6] Hapus Depan"<<endl; //suskses
	cout << "[7] Cetak Bos Qu"<<endl; //suskses
	cout << "Masukan Pilihan:"; cin >> pilih;
	//untuk pilihannya
	switch(pilih){
		case 1 : tambahbelakang();
			break;
		case 2 : cout<<"input posisinya : ";
				 cin>>pos;
				 cout<<"input posisinya : ";
				 cin>>data;
				 tambahtengah(pos, data);
				 break;
		case 3 : tambahdepan(depan);
			break;
		case 4 :
				hapusbelakang(pos);
			break;
		case 5 : cout<<"posisi yg ngin di hapus : "; cin>>pos;
				hapustengah(pos);
			break;
		case 6 :
				hapusdepan(pos);
			break;
        case 7 : cetak();
			break;
		default: cout << "inputan salah solahkan coba lagi";
			break;
        }
    }
}

//cek ada nilai atau tidak
bool apakahKosong(){
	if (head == NULL)
		return true;
	else
		return false;
}
//tambah belakang
void tambahbelakang(){
	int a;

	cout << "input data : "; cin >> a;

	entry = new node;
	entry->data = a;
	entry->next = NULL;
	tail->next = entry;
	tail = entry;
}
//tambah tengah error
void tambahtengah(int pos, int data){
	entry = new node;
	curr = head;
	for(int i =1; i<pos; i++){
		prev = curr;
		curr = curr->next;
	}

	entry->next = prev->next;
	prev->next = entry;

}
//tambah depan
void tambahdepan(int depan){
	int b;
	cout <<"Input data : "; cin>>b;
	entry = new node;
	entry->data = b;
	entry->next = NULL;

	//cek apakah list kosong atau tidak
	if(apakahKosong()){
		head = entry;
		tail = entry;
		head->next = NULL;
	}else{
		entry->next = head;
		head = entry;
	}

}
//hapus depan
void hapusbelakang(int pos){
    if(apakahKosong()){
		cout<<"list kosong"<<endl;
	}else if(head->next== NULL){
		curr = head;
		head = NULL;
		tail = NULL;
		delete(curr);
	}else{
		bantu = head;
		while (bantu->next != tail){
			bantu = bantu->next;
		}

		curr = tail;
		tail = bantu;
		tail->next= NULL;
		delete(curr);
		cout<< "berhasil di hapus!!!!!!"<<endl;
	}
}
//hapus tengah
void hapustengah(int pos){
	curr = head;
	for (int i=1; i<pos; i++){
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	//delete curr
}
//hapus depan
void hapusdepan(int pos){
	if(apakahKosong()){
		cout<<"List kosong"<<endl;
	}else{
		curr = head;
		head = head->next;
		curr->next = NULL;
		delete(curr);
		cout <<"berhasil di hapus!!!!!!!"<<endl;
	}
}
//cetak
void cetak(){
	bantu = head;
	while(bantu!=NULL){
		cout<<bantu->data<<"->";
		bantu=bantu->next;
	}
	if (bantu==NULL){
		cout<<"NULL"<<endl;
	}
}
