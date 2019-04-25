#include<iostream>
using namespace std;

//deklrasi fungsi
void tampilkanisi();
void tambahdepan(int a);
void tambahbelakang(int b);
void tambahtengah(int c,int posisi);
bool teskosong();
void hapusdepan();
void hapustengah(int posisi);
void hapusbelakang();
void cek50();

//deklarasi struct node
struct node{
	int info;
	node *link;
} *first, *last, *Q, *baru, *bantu, *curr, *prev;


int main(){

	tambahdepan(25);
	tambahbelakang(30);
	tambahtengah(50,2);
	tambahbelakang(40);
	tambahdepan(32);
	tambahbelakang(50);
	tambahtengah(70,4);
	tambahbelakang(50);
	tampilkanisi();
	cek50();
}

//Apakah kosong
bool teskosong(){
	if(first==NULL){
		return true;
	}else{
		return false;
	}
}

//tambah depan
void tambahdepan(int a){
	baru = new node;
	baru->info = a;

	if(teskosong()){
		baru->link = NULL;
		first= baru;
		last = baru;
	}else{
		baru->link=first;
		last=first;
		first=baru;
	}

}

//tambah tengah
void tambahtengah(int c,int posisi){
	baru = new node;
	curr = first;
	for(int i=1; i<posisi; i++){
		bantu = curr;
		curr = curr->link;
	}
	baru->info= c;
	bantu->link= baru;
	baru->link= curr;
}

//tambah belakang
void tambahbelakang(int b){
	baru = new node;
	baru->info = b;
	bantu = first;
	while(bantu->link!=NULL){
		bantu = bantu->link;
	}
	bantu->link=baru;
	baru->link = NULL;
	last = baru;
}

//tampilkan isi
void tampilkanisi(){
	bantu = first;
	while(bantu!= NULL){
		cout<<bantu->info<<" ";
		bantu = bantu->link;
	}

	if(bantu == NULL){
		cout<<" NULL \n\n";
	}
}

//hapus depan
void hapusdepan(){
	bantu = first;
	first = first -> link;
	bantu -> link = NULL;
	delete bantu;
	cout<<"Simpul berhasil dihapus!!!\n\n";
}

//hapus tengah
void hapustengah(int posisi){
	curr = first;
	for(int i= 1; i<(posisi); i++){
		prev = curr;
		curr = curr->link;
	}
	prev->link = curr->link;
	delete curr;
	cout<<"Simpul berhasil dihapus!!!\n\n";
}

//haput belakang
void hapusbelakang(){
	bantu = first;
	while(bantu->link != NULL){
		prev = bantu;
		bantu = bantu -> link;
	}
	prev->link=NULL;
	delete bantu;
	cout<<"Simpul berhasil dihapus!!!\n\n";
}

//mengecek apakah ada INFO 50
void cek50(){
	int jumlah = 0;
	bantu = first;
	while(bantu!=NULL){
		if(bantu->info == 50){
			jumlah = 1+jumlah;
			cout<<"ADA\n";
		}else{
			cout<<"TIDAK ADA\n";
		}
		bantu = bantu->link;
	}
	cout<<"Jumlah INFO 50 ada : "<<jumlah;
}
