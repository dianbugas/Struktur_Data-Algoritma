#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <stddef.h>
#include <iomanip>
#include <ctime>
using namespace std;

struct barang {
	int no;
	string nama;
	double berat;
	double harga;
	int stock;
	barang *next;
	barang *prev;
};

struct belanja {
	int no;
	string nama;
	double berat;
	double harga;
	int jlh;
	double totalBarang;
	belanja *next;
	belanja *prev;
};

struct penjualan {
	int no;
	double harga;
	double bayar;
	double kembali;
	penjualan *next;
	penjualan *prev;
};

barang *head = NULL, *tail = NULL, *temp, *entry, *entry1, *entry2;
belanja *atas = NULL, *bawah = NULL, *bantu, *sebelum, *sesudah, *baru;
penjualan *pala = NULL, *buntut = NULL, *tolong, *baru1;

void menu();
void laporan();
void pembelian();
void dataAwal();
void tambahBarang();
bool cariBarang(int x);
barang* getBarang(int x);
void tambahBelanja(barang *temp, int jlh);
int jumlahBelanja();
void hapusDepanBelanja();
void hapusBelakangBelanja();
void hapusTengah(int pos);
void hapusBelanja(int x);
void pembayaran();
void ubahStock();
void tambahLaporanPenjualan(double harga, double bayar, double kembali);
void clearBelanja();
void gotoxy(int x, int y);

int main(){
	dataAwal();
	char ulang;
	awal:
	do {
		system("cls");
		menu();
		cout <<"\nKembali ke menu?(y/n)";
		cin >> ulang; //(ulang=='y' || ulang=='Y')
		ulang = toupper(ulang);
	} while (ulang=='Y');
}

void dataAwal(){
	head = new barang;
	entry = new barang;
	entry1 = new barang;
	entry2 = new barang;
	tail = new barang;

	head->no = 1;
	head->nama = "Indiemie Goreng";
	head->berat = 0.005;
	head->harga = 2300;
	head->stock = 50;
	head->next = entry;
	head->prev = NULL;

	entry->no = 2;
	entry->nama = "Minyak Goreng Sisi";
	entry->berat = 1;
	entry->harga = 30000;
	entry->stock = 10;
	entry->next = entry1;
	entry->prev = head;

	entry1->no = 3;
	entry1->nama = "Kecap CBA botol kecil";
	entry1->berat = 0.06;
	entry1->harga = 6000;
	entry1->stock = 50;
	entry1->next = entry2;
	entry1->prev = entry;

	entry2->no = 4;
	entry2->nama = "Sabun LifeGirl";
	entry2->berat = 0.06;
	entry2->harga = 3500;
	entry2->stock = 50;
	entry2->next = tail;
	entry2->prev = entry1;

	tail->no = 5;
	tail->nama = "Sabun Ronso";
	tail->berat = 0.06;
	tail->harga = 10500;
	tail->stock = 50;
	tail->next = NULL;
	tail->prev = entry2;
}

void menu(){
	char pilih;
	system("cls");
	cout << "=============================================================================================" << endl;
	cout << "|                                       Selamat Datang                                      |" << endl;
	cout << "=============================================================================================" << endl;
	cout << endl;
	cout << "=============================================================================================" << endl;
	cout << "|   No    |                                   Menu                                          |" << endl;
	cout << "=============================================================================================" << endl;
	cout << "|   [1]   |                                 Pembelian                                       |" << endl;
	cout << "|   [2]   |                                Stock Barang                                     |" << endl;
	cout << "|   [3]   |                               Tambah Barang                                     |" << endl;
	cout << "|   [4]   |                             Laporan Penjualan                                   |" << endl;
	cout << "|   [5]   |                                    Exit                                         |" << endl;
	cout << "=============================================================================================" << endl;
	cout << "Masukkan pilihan : "; cin >> pilih;
	switch(pilih){
		case '1' :
			pembelian();
			break;
		case '2' :
			ubahStock();
			break;
		case '3' :
			system("cls");
			tambahBarang();
			break;
		case '4' :
			system("cls");
			laporan();
			break;
		case '5' :
			exit(0);
			break;
		default :
			cout << "Inputan salah";
			break;
	}
}

int jumlah(){
	int jlh = 0;
	temp = head;
	while (temp != NULL){
		temp = temp->next;
		jlh++;
	}
	return jlh;
}

bool cariBarang(int x){
	bool ketemu = false;
	temp = head;
	while (!ketemu){
		if (temp->no == x){
			ketemu = true;
			return ketemu;
		} else if (temp->next == NULL) {
			return ketemu;
		}else {
			temp = temp->next;
		}
	}
}

barang* getBarang(int x){
	if (cariBarang(x)){
		return temp;
	}
	else {
		return NULL;
	}
}

void pembelian(){
	int pilih;
	int jlh, y = 7;
	char tanya;

	pilihBarang:
	system("cls");
	cout << "=============================================================================================" << endl;
	cout << "|                                        List Barang                                        |" << endl;
	cout << "=============================================================================================" << endl;
	cout << endl;
	cout << "=============================================================================================" << endl;
	cout << "|   No    |                           Nama Barang                         |      Harga      |" << endl;
	cout << "=============================================================================================" << endl;


	temp=head;
	if(head == NULL){
        cout << "|                                      Tidak Ada Barang                                     |" << endl;
	}
    else{
    	// Menampilkan List Barang Dagangan
		while (temp != NULL){ //aaaauuzzaaaan
			cout << "|";
			gotoxy (4,y); cout << "[" << temp->no << "] "; gotoxy(10,y); cout << "|";
			gotoxy (14,y); cout<< temp->nama << endl; gotoxy(74,y); cout << "|";
			gotoxy (80,y); cout << temp->harga; gotoxy(92,y); cout << "|" << endl;

			temp = temp->next;
			y++;
		}
	}
	cout << "=============================================================================================" << endl;

	cout << "\n[0] Kembali" << endl;
	cout << "[99] Pembayaran" << endl;
	cout << "Masukkan no barang yg ingin di beli: "; cin >> pilih;
	switch(pilih){
		case 0 :
			main();
			break;
		case 99 :
			pembayaran();
			break;
		default :
			if (cariBarang(pilih)){
				// Mengambil barang dari list berdasarkan no nya
				// Kemudian menyimpannya di temp
				temp = getBarang(pilih);

				jlh:
				cout << "Masukkan Jumlah : "; cin >> jlh;
				if (jlh <= temp->stock){
					tambahBelanja(temp, jlh);

					tanya:
					cout << "pilih lagi (y/t) ? "; cin >> tanya;
					tanya = toupper(tanya);
					switch (tanya){
						case 'Y' :
							pembelian();
							break;
						case 'T' :
							pembayaran();
							break;
						default :
							cout << "Pilihan salah" << endl;
							Sleep(2000);
							goto tanya;
							break;
					}
				} else {
					cout << "Stock tidak mencukupi" << endl;
					Sleep(2000);
					goto jlh;
				}

			} else {
				cout << "Tidak di temukan" << endl;
				Sleep(2000);
				goto pilihBarang;
			}
			break;
	}
}

void tambahBelanja(barang *temp, int jlh){
	baru = new belanja;
	baru->nama = temp->nama;
	baru->berat = temp->berat;
	baru->harga = temp->harga;
	baru->jlh = jlh;
	baru->totalBarang = baru->harga * jlh;
	baru->next = NULL;
	baru->prev = NULL;
	temp->stock = temp->stock - baru->jlh;

    if(atas == NULL){
    	baru->no = 1;
    	atas = baru;
        bawah = baru;
        //entry = NULL;
    } else {
    	baru->no = bawah->no + 1;
        bawah->next = baru;
        baru->prev = bawah;
        bawah = baru;
    }  // aauuuzzann
}

bool cariBelanja(int x){
	bool ketemu = false;
	bantu = atas;
	while (!ketemu){
		if (bantu->no == x){
			ketemu = true;
			return ketemu;
		} else if (bantu->next == NULL) {
			return ketemu;
		}else {
			bantu = bantu->next;
		}
	}
}

belanja* getBelanja(int x){
	if (cariBelanja(x)){
		return bantu;
	}
	else {
		return NULL;
	}
}

int jumlahBelanja(){
	int jlh = 0;
	bantu = atas;
	while (bantu != NULL){
		bantu = bantu->next;
		jlh++;
	}
	return jlh;
}

void hapusDepanBelanja(){
	if(atas==NULL){
		cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
    }
    else if (jumlahBelanja() == 1){
    	bantu = atas;
		atas = NULL;
		delete bantu;
	}
    //auuzzzzannn
    else{
    	bantu = atas;
		atas = atas->next;
		atas->prev = NULL;
		bantu->next = NULL;
		delete bantu;
	}
}

void hapusBelakangBelanja(){
	if(atas==NULL){
		cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
    }
    else {
		bantu = atas;
		while (bantu->next != NULL){
			sebelum = bantu;
			bantu = bantu->next;
		}
		bawah = sebelum;
		bantu->prev = NULL;
		bawah->next = NULL;
		delete bantu;
		//auzan
	}
}

void hapusBelanja(int x){
	bantu = getBelanja(x);
	sebelum = bantu->prev;
	sesudah = bantu->next;

	if (sebelum == NULL){
		hapusDepanBelanja();
	} else if (sesudah == NULL){
		hapusBelakangBelanja();
	} else {
		sebelum->next = sesudah;
		sesudah->prev = sebelum;
		delete bantu;
	}
}

void pembayaran(){
	system("cls");
	double hargaTotal = 0;
	double bayar, kembali;
	double x = 0;
	int y = 7;
	int pilih;
	char tanya;
	cout << "=============================================================================================" << endl;
	cout << "|                                       Pembayaran                                          |" << endl;
	cout << "=============================================================================================" << endl;
	cout << endl;
	cout << "=============================================================================================" << endl;
	cout << "|   No    |                   Nama Barang                   |   Jumlah    |      Harga      |" << endl;
	cout << "=============================================================================================" << endl;

	bantu = atas;
	if(atas == NULL){
		cout << "|                            Tidak Ada Barang Dalam Keranjang                               |" << endl;
	} else {
		while(bantu != NULL){
			cout << "|";
			gotoxy (5,y); cout << bantu->no; gotoxy(10,y); cout << "|";
			gotoxy (12,y); cout << bantu->nama; gotoxy(60,y); cout << "|";
			gotoxy (67,y); cout << bantu->jlh; gotoxy(74,y); cout << "|";
			gotoxy (80,y); cout << bantu->totalBarang; gotoxy(92,y); cout << "|" << endl;
			x = bantu->totalBarang;
			bantu = bantu->next;
			hargaTotal = hargaTotal + x;
			y++;
		}
	}
	cout << "=============================================================================================" << endl;
	cout << "|                                   TOTAL                                 |     " << hargaTotal; gotoxy(92,y+1); cout << "|" << endl;
	cout << "=============================================================================================" << endl;
	cout << endl;
	cout << "[0] Kembali" << endl;
	cout << "[1] Hapus Barang di Keranjang" << endl;
	cout << "[99] Bayar" << endl;
	pil:
	cout << "Masukkan pilihan : "; cin >> pilih;
		switch(pilih){
			case 0 :
				pembelian();
				break;
			case 1 :
				cout << "Pilih no belanja yg ingin di hapus : "; cin >> pilih;
				if (cariBelanja(pilih)){
					cout << "Data berhasil di hapus" << endl;
					hapusBelanja(pilih);
					pembayaran();
				} else {
					cout << "Barang tidak di temukan" << endl;
					pembayaran();
				}
				break;
			case 99 :
				q:
				cout << "Pembayaran  = "; cin >> bayar;
				if (bayar < hargaTotal){
					cout << "Uang tidak cukup, masukkan uang lagi (y/n) ? ";
					cin >> tanya;
					tanya = toupper(tanya);

					switch (tanya){
						case 'Y' :
							goto q;
							break;
						case 'N' :
							cout << "Maaf uang tidak mencukupi" << endl;
							cout << "Pembayaran tidak bisa dilakukan terima kasih" << endl;
							clearBelanja();
							break;
						default :
							cout << "Inputan salah" << endl;
							break;
					}
				} else {
					kembali = bayar-hargaTotal;
					cout << "Kembali     = " << kembali << endl;;
					cout << "\nTerima kasih telah melakukan pembayaran" << endl;
					tambahLaporanPenjualan(hargaTotal, bayar, kembali);
					clearBelanja();
				}
				break;
			default :
				goto pil;
				break;
		}

}

void ubahStock(){
	system("cls");
	back:
	int y = 7;
	int pilih, stock;
	char tanya;
	cout << "=============================================================================================" << endl;
	cout << "|                                       Stock Barang                                        |" << endl;
	cout << "=============================================================================================" << endl;
	cout << endl;
	cout << "=============================================================================================" << endl;
	cout << "|   No    |                   Nama Barang                   |              Stock            |" << endl;
	cout << "=============================================================================================" << endl;

	temp = head;
	if(head == NULL){
		cout << "|                                 Tidak Ada Barang List                                     |" << endl;
	} else {
		while(temp != NULL){
			cout << "|";
			gotoxy (5,y); cout << temp->no; gotoxy(10,y); cout << "|";
			gotoxy (12,y); cout << temp->nama; gotoxy(60,y); cout << "|";
			gotoxy (77,y); cout << temp->stock; gotoxy(92,y); cout << "|" << endl;
			temp = temp->next;
			y++;
		}
	}
	cout << "=============================================================================================" << endl;

	cout << "\n[0] Kembali" << endl;
	cout << "Pilih No barang yang ingin dirubah stocknya : "; cin >> pilih;

	switch(pilih){
		case 0 :
			main();
			break;
		default :
			if (cariBarang(pilih)){
				temp = getBarang(pilih);

				stck:
				cout << "Masukkan stock yang baru : "; cin >> stock;

				if (stock > 0 ){
					q:
					cout << "Apakah anda yakin (y/t) ? "; cin >> tanya;
					tanya = toupper(tanya);
					switch(tanya){
						case 'Y' :
							temp->stock = stock;
							cout << "Stock Barang " << temp->nama << " berhasil diubah" << endl;
							t:
							cout << "Ingin ubah stock lagi (y/t) ? "; cin >> tanya;
							tanya = toupper(tanya);

							switch(tanya){
								case 'Y' :
									ubahStock();
									break;
								case 'T' :
									menu();
									break;
								default :
									cout << "Inputan salah" << endl;
									Sleep(2000);
									goto t;
									break;
							}
							break;
						case 'T' :
							goto stck;
							break;
						default :
							cout << "Inputan salah" << endl;
							Sleep(2000);
							goto q;
					}
				} else {
					cout << "Stock tidak boleh kurang dari 0" << endl;
					goto stck;
				}

			} else {
				cout << "Stock tidak ditemukan" << endl;
				Sleep(2000);
				ubahStock();
			}
			break;
	}
}

void tambahBarang(){
	char pilih;
	string nama;
	double berat;
	double harga;
	int stock;

	cout << "=============================================================================================" << endl;
	cout << "|                                      Tambah Barang                                        |" << endl;
	cout << "=============================================================================================" << endl;
	cout << endl;
	cout << "=============================================================================================" << endl;
	cout << "|          Keterangan          |                            Input                           |" << endl;
	cout << "=============================================================================================" << endl;
	cout << "|   Masukkan Nama Barang       :    "; gotoxy(92,7); cout << "|" << endl;
	cout << "|   Masukkan Berat Barang /pcs :    "; gotoxy(92,8); cout << "|" << endl;
	cout << "|   Masukkan Harga Barang      :    "; gotoxy(92,9); cout << "|" << endl;
	cout << "|   Masukkan Stock Barang      :    "; gotoxy(92,10); cout << "|" << endl;
	cout << "=============================================================================================" << endl;

	cin.ignore();
	gotoxy(38,7); getline(cin, nama);
	gotoxy(38,8); cin >> berat;
	gotoxy(38,9); cin >> harga;
	gotoxy(38,10); cin >> stock;

	entry = new barang;
    entry->nama = nama;
    entry->berat = berat;
    entry->harga = harga;
    entry->stock = stock;
    entry->next = NULL;
    entry->prev = NULL;
    if (head==NULL){
    	entry->no = 1;
        head = entry;
        tail = entry;
        //entry = NULL;
    }
    else {
    	entry->no = tail->no + 1;
        tail->next = entry;
        entry->prev = tail;
        tail = entry;
    }
      // aauuuzzann
    pil:
    gotoxy(0,12); cout << "Kembali ke menu (y/t) ? ";
    cin >> pilih;
    pilih = toupper(pilih);
    switch(pilih){
    	case 'Y' :
    		menu();
    		break;
    	case 'T' :
    		system("cls");
    		tambahBarang();
    		break;
    	default :
    		cout << "Inputan salah";
    		Sleep(2000);
    		goto pil;
	}
}

void tambahLaporanPenjualan(double harga, double bayar, double kembali){
	baru1 = new penjualan;
	baru1->harga = harga;
	baru1->bayar = bayar;
	baru1->kembali = kembali;
	baru1->next = NULL;
	baru1->prev = NULL;

    if(pala == NULL){
    	baru1->no = 1;
    	pala = baru1;
        buntut = baru1;
        //entry = NULL;
    } else {
    	baru1->no = buntut->no+1;
        buntut->next = baru1;
        baru1->prev = buntut;
        buntut = baru1;
    }  // aauuuzzann
}

void laporan(){
	system("cls");
	back:
	int y = 7;
	char pilih;
	double totalPenjualan, x;
	char tanya;
	cout << "=============================================================================================" << endl;
	cout << "|                                    Laporan Penjualan                                      |" << endl;
	cout << "=============================================================================================" << endl;
	cout << endl;
	cout << "=============================================================================================" << endl;
	cout << "|   No    |           Harga          |          Bayar         |           Kembali           |" << endl;
	cout << "=============================================================================================" << endl;


	tolong = pala;
	if(pala == NULL){
		cout << "|                              Tidak Ada Riwayat Penjualan                                  |" << endl;
		cout << "=============================================================================================" << endl;
		cout << "Total Penjualan : Rp -" << endl;
	} else {
		while(tolong != NULL){
			cout << "|";
			gotoxy (5,y); cout << tolong->no; gotoxy(10,y); cout << "|";
			gotoxy (20,y); cout << "Rp " << tolong->harga; gotoxy(37,y); cout << "|";
			gotoxy (47,y); cout << "Rp " << tolong->bayar; gotoxy(62,y); cout << "|";
			gotoxy (73,y); cout << "Rp " << tolong->kembali; gotoxy(92,y); cout << "|" << endl;
			x = tolong->harga;
			tolong = tolong->next;
			totalPenjualan = totalPenjualan + x;
			y++;
		}
		cout << "=============================================================================================" << endl;
		cout << "Total Penjualan : Rp " << totalPenjualan << endl;
	}

	cout << "\n[0] Kembali" << endl;
	cout << endl;
	cout << "Pilih : "; cin >> pilih;
		switch (pilih){
			case '0' :
				menu();
				break;
			default :
				cout << "Inputan salah" << endl;
				Sleep(2000);
				laporan();
				break;
		}
}

void clearBelanja(){
	if (atas != NULL){
		bantu = atas; //auzannnn
		while (bantu != NULL){
			atas = bantu->next;
			delete bantu;
			bantu = atas;
		}
	}
}

void gotoxy(int x, int y) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}
