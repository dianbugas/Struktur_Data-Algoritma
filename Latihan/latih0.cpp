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
	int a, b, c, posisi;

/*	tambahdepan(2);
	tambahdepan(1);
	tambahbelakang(27);
	tambahbelakang(14);*/

	while (true){
		int pilih;
		cout<<"[1] Input Depan\n";
		cout<<"[2] Input Tengah\n";
		cout<<"[3] Input Belakang\n";
		cout<<"[4] Hapus Depan\n";
		cout<<"[5] Hapus Tengah\n";
		cout<<"[6] Hapus Belakang\n";
		cout<<"[7] Cetak\n";
		cout<<"[8] Exit\n";
		cout<<"Masukan pilihan : ";cin>>pilih;

		switch(pilih){
			case 1 :
				cout<<"Input Data : ";cin>>a;
				tambahdepan(a);
				cout<<endl;
				break;
			case 2 :
				cout<<"Input posisi : ";cin>>posisi;
				cout<<"Input Data : ";cin>>c;
				tambahtengah(c,posisi);
				break;
			case 3 :
				cout<<"Input Data : ";cin>>b;
				tambahbelakang(b);
				cout<<endl;
				break;
			case 4 :
				hapusdepan();
				cout<<endl;
				break;
			case 5 :
				cout<<"Input Posisi yang mau dihapus : "; cin>>posisi;
				hapustengah(posisi);
				cout<<endl;
				break;
			case 6 :
				hapusbelakang();
				break;
			case 7 :
				tampilkanisi();
				cout<<endl;
				break;
			case 8 :
				cout<<"Exit\n";
				return 0;
				break;
			default :
				cout<<"Inputan Salah, silahkan masukin antara 1-8 \n\n";
				break;
		}
	}
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
	bantu = first;
	while(bantu!=NULL){
		if(bantu->info == 50){
			cout<<"ADA\n";
		}else{
			cout<<"TIDAK ADA\n";
		}
		bantu = bantu->link;
	}
}
