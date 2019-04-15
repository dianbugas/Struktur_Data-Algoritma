//Efrizal
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *first, *last, *bantu, *baru, *hapus, *tempNode, *tempHead, *tempNext;

void inisialisasi ();

bool apakahKosong ();

void tambahBelakang ();

void urut ();

void cetak ();

int main()
{
    inisialisasi();
    tambahBelakang();
    tambahBelakang();
    tambahBelakang();
    tambahBelakang();
    tambahBelakang();
    tambahBelakang();
    tambahBelakang();
    tambahBelakang();
    tambahBelakang();
    cout << "--------------Simpul yang tersedia---------------" << endl;
    cetak();

    cout << "Setelah diurutkan : " << endl;


    return 0;
}

void inisialisasi (){
    first = NULL;
}

bool apakahKosong(){
	if (first == NULL){
        return true;
	}else{
		return false;
    }
}

void tambahBelakang (){

    baru = new node;
    cout << "Data : " ; cin >> baru -> data;
    baru -> next = NULL;

    if (apakahKosong()){
        first = baru;
        last = baru;
        first -> next = NULL;
    }else {
        last -> next = baru;
        last = baru;
    }

}

void urut(){


}

void cetak (){
    if(apakahKosong()){
		cout<<"List kosong"<<endl;
	}else if(first -> next == NULL){
		cout<<first -> data<<endl;
	}else{
		bantu = first;
		while (bantu != NULL){
			cout<<bantu -> data<<" -> ";
			bantu = bantu -> next;
		}
		cout << "NULL";
		cout<<endl;
	}
}
