#include<iostream>
#include<string>

using namespace std;
//deklarasi tinggi stack
int const MAX_QUEUE=10;
//deklarasi struct sebagai tipe data stack
struct data{
	string nama;
	string merek;
	int cc;
	int tahunPembuatan;
};
//deklarasikan sebuah variabel stack
data queue[MAX_QUEUE];
//mendeklarasikan sebuah variabel
//yang berfungsi untuk menunjuk stack
//paling atas dan menginisialisasi dengan -1
int tail = -1;
void enqueue(data databaru);
void dequeue();
void clear();
bool isEmpty();
bool isFull();
void read();

int main(){
	data kendaraan1;
	kendaraan1.nama = "supra x 125";
	kendaraan1.merek = "honda";
	kendaraan1.cc = 125;
	kendaraan1.tahunPembuatan = 2019;
	enqueue(kendaraan1);
	cout<<queue[0].nama<<endl;
	data kendaraan2;
	read();
	kendaraan2.nama = "vespa";
	kendaraan2.merek = "vespa";
	kendaraan2.cc = 110;
	kendaraan2.tahunPembuatan = 2008;
	enqueue(kendaraan2);
	read();
	//clear();
	//read();
	dequeue();
	read();
}

void enqueue(data databaru){
	//cek apakah stack penuh atau tidak
	if(isFull()){
		cout<<"Maaf, queue penuh!"<<endl;
	}else{
		tail++;
		queue[tail] = databaru;
		cout<<"data berhasil dimasukan"<<endl;
	}

}
void dequeue(){

	if(isEmpty()){
		cout<<"queue kosong"<<endl;
	}else{
		data kendaraan = queue[0];
		cout<<"data yang dikeluarkan: ";
		cout<<kendaraan.nama<<endl;
		for(int i=0; i<tail; i++){
			queue[i] = queue[i+1];
		}
		tail--;
	}

}
void clear(){
	tail = -1;
	cout<<"queue berhasil dikosongkan!"<<endl;
}
bool isEmpty(){
	if (tail == -1){
		return true;
	}else{
		return false;
	}
}
bool isFull(){
	if(tail == (MAX_QUEUE-1)){
		return true;
	}else{
		return false;
	}
}
void read(){
	if(isEmpty()){
		cout<<"maaf, queue kosong!"<<endl;
	}else{
		cout<<"isi queue :"<<endl;
		for(int i=0; i<=tail; i++){
			cout<<queue[i].nama<<endl;
		}
	}

}


