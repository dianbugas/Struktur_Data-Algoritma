#include <iostream>
using namespace std;

#define MAX_QUEUE 5

int queue[MAX_QUEUE];
int jumlah;
int depan;
int belakang;

void inisialisasi(){
	jumlah = 0;
	depan = -1;
	belakang = -1;
}

bool isEmpty(){
	if (jumlah == 0){
		return true;
	} else {
		return false;
	}
}

bool isFull(){
	if (jumlah == MAX_QUEUE){
		return true;
	} else {
		return false;
	}
}

void enqueue(int data){
	if (isFull()){
		cout << "Antrian Penuh" << endl;
	} else if (jumlah == 0){
		depan = 0;
		belakang = 0;
		queue[belakang] = data;
		jumlah++;
		cout << "Data berhasil di masukkan" << endl;
	} else {
		belakang++;
		queue[belakang] = data;
		jumlah++;
		cout << "Data berhasil di masukkan" << endl;
	}
}

void dequeue(){
	if (isEmpty()){
		cout << "Antrian kosong" << endl;
	} else if (jumlah == 1){
		cout << queue[depan] << endl;
		depan--;
		belakang--;
		jumlah--;
		cout << "Data berhasil di proses" << endl;
	} else {
		cout << queue[depan] << endl;
		//int counter = jumlah;
		for (int counter = 0; counter < (jumlah-1); counter++){
			queue[counter] = queue[counter+1];
		}
		belakang--;
		jumlah--;
		cout << "Data berhasil di proses" << endl;
	}
}

void read(){
	if (isEmpty()){
		cout << "Queue Kosong" << endl;
	} else {
		for (int counter = 0; counter <= jumlah-1; counter++){
			cout << queue[counter] << " ";
		}
		cout << endl;
	}
}

int main(){
		int pilih;
	int data;
	char jawab;
	awal:

	do {
		pilih = 0;
		//system("cls");
		cout << "========= MENU ========="	<< endl;
		cout << "[1] isEmpty"	<< endl;
		cout << "[2] isFull"	<< endl;
		cout << "[3] Enqueue"	<< endl;
		cout << "[4] Dequeue"	<< endl;
		cout << "[5] Read"	<< endl;
		cout << "[6] Selesai"	<< endl;
		cout << "Pilih angka pada menu : ";
		cin >> pilih;
		if (pilih < 1 || pilih > 5){
			cout << "pilihan salah" << endl;
		}
	} while (pilih < 1 || pilih > 5);

	switch(pilih){
		case 1 :
			if (isEmpty()){
				cout << "Antrian Kosong" << endl;
			} else {
				cout << "Antrian Tidak Kosong" << endl;
			}
			break;
		case 2 :
			if (isFull()){
				cout << "Antrian Full" << endl;
			} else {
				cout << "Antrian Tidak Full" << endl;
			}
			break;
		case 3 :
			cout << "Masukkan data : "; cin >> data;
			enqueue(data);
			break;
		case 4 :
			dequeue();
			break;
		case 5 :
			read();
			break;
		case 6 :
			//exit(0);
			break;
		default :
			cout << "Pilihan salah";
			break;
	}
	kembali:
	cout << "kembali ke menu (y/t) : "; cin >> jawab;
	if (jawab == 'y' || jawab == 'Y'){
		goto awal;
	} else if (jawab != 't' && jawab != 'T'){
		cout << "Tekan (y/t)" << endl;
		goto kembali;
	}
}
