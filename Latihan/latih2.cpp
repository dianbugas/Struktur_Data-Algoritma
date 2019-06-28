#include<iostream>
using namespace std;

void tampilkanisi();
void tambahdepan(int a);
void tambahbelakang(int b);
void tambahtengah(int c,int posisi);
int menghitunglist();
void cetakjumlahsimpul();
bool teskosong();
void cetakjumlahINFO();
void limapuluh(int jumlah);

struct node{
	int info;
	node *link;
} *first, *last, *Q, *baru, *bantu, *curr;


int main(){
	tambahdepan(2);
	tambahdepan(1);
	tambahbelakang(27);
	tambahbelakang(14);
	tambahtengah(3,3);
	tambahtengah(30,4);
	tambahtengah(50,5);
	tambahtengah(32,6);


	//3.a. menghitung dan mencetak jumlah simpul.
	cout<<"\n3.a. menghitung dan mencetak jumlah simpul\n";
	//cetaksimpul();

	//3.c. mencetak semua nilai INFO ke layar.
	tampilkanisi();

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

//menhitunglist
int menghitunglist(){
	if(teskosong()){
		cout<<"simpul kosong\n";
	}else{
		bantu=first;
		int jumlah=1;
		while(bantu->link != NULL){
			jumlah=jumlah+1;
			bantu=bantu->link;
		}
	}

}

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
/*
	int jumlah=menghitunglist();
	if(jumlah>=posisi){
		bantu=first;
		int bantuposisi=1;
		for(int i=1; i<(posisi-1); i++){
			bantu=bantu->link;
		}
		//sisipkan data baru
		baru = new node;
		baru->info=c;
		baru->link=NULL;
		baru->link=bantu->link;
		bantu->link=baru;
	}else{
		baru = new node;
		baru->info=c;
		baru->link=NULL;
		last->link=baru;
		last=baru;
	}*/
}

//tambah belakang
void tambahbelakang(int b){
	baru = new node;
	baru->info = b;
	baru->link = NULL;
	last->link = baru;
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
		cout<<" NULL \n";
	}
}

//menampilkan jumlah simpul
void cetakjumlahsimpul(){
	if(teskosong()){
		cout<<"List Kosong";
	}else{
		bantu=first;
		int jumlah=1;
		while(bantu->link != NULL){
			jumlah=jumlah+1;
			bantu=bantu->link;
		}
			cout<<"Jumlah simpulnya adalah "<<jumlah<<endl;
	}
}

/*//menempatkan pointer q
void pointerq(){
	for(int i=1; i=tail; i)
}
*/

/*//mencetak total data
void cetakjumlahINFO(){
	bantu = first;
	 jumlah=0;
	while(bantu!= NULL){
		bantu = bantu->link;
		jumlah= jumlah + bantu;

	}
}*/

//Info=50
/*void limapuluh(int jumlah){
	bantu = first;
	cout<<"Jumlah simpul = "; cin>>jumlah;
	for(int i=1; i<=jumlah; i++){
		if(bantu == 50){
			cout<<bantu->info<<" ";
		}
	}
}*/
