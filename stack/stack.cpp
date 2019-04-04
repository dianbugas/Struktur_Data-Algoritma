#include <iostream>
using namespace std;

#define MAX_QUEUE 5

int stack[MAX_QUEUE];
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

void pop(int data){
	if (isFull()){
		cout << "Antrian Penuh" << endl;
	} else if (jumlah == 0){
		depan = 0;
		belakang = 0;
		stack[belakang] = data;
		jumlah++;
		cout << "Data berhasil di masukkan" << endl;
	} else {
		belakang++;
		stack[belakang] = data;
		jumlah++;
		cout << "Data berhasil di masukkan" << endl;
	}
}

void push(){
	if (isEmpty()){
		cout << "Antrian kosong" << endl;
	} else if (jumlah == 1){
		cout << stack[depan] << endl;
		depan--;
		belakang--;
		jumlah--;
		cout << "Data berhasil di proses" << endl;
	} else {
		cout << stack[depan] << endl;
//		//int counter = jumlah;
//		for (int counter = 0; counter < (jumlah-1); counter++){
//			queue[counter] = queue[counter+1];
//		}
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
			cout << stack[counter] << " ";
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
		//system("cls"); //untuk membersihkan inputan
		cout << "========= MENU ========="	<< endl;
		cout << "[1] isEmpty"	<< endl;
		cout << "[2] isFull"	<< endl;
		cout << "[3] push"	<< endl;
		cout << "[4] pop"	<< endl;
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
			pop(data);
			break;
		case 4 :
			push();
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
