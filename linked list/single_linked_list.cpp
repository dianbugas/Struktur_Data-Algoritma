#include <iostream>
using namespace std;

//deklarasi tnode
struct TNode{
    int data;
    TNode *next;
};
TNode *head, *tail, *baru, *entry, *bantu;

//deklarasi fungsi
void tambahbaru();
void cetak();
void hapusdata();

int main(){
    baru = new TNode;
    baru->data = 1;
    baru->next = NULL;
    head = baru;
    tail = baru;

    while(true){
            int pilih;
        cout<<"[1] Input Data "<<endl;
        cout<<"[2] Cetak "<<endl;
        cout<<"[3] Hapus "<<endl;
        cout<<"Masukan Pilihan : "; cin>>pilih;
        switch(pilih)
        {
            case 1: tambahbaru();
                break;
            case 2: cetak();
                break;
            case 3: hapusdata();
                break;
            default : cout<<"Maaf input salah! silahkan pilih lagi"<<endl;
                break;
        }
    }
}

void tambahbaru(){
   int a;
   cout<<"input data : ";cin>>a;
   entry = new TNode;
   entry->data = a;
   entry->next = NULL;
   tail->next =  entry;
   tail= entry;
}

void hapusdata(){

}

void cetak(){
    bantu = head;
	while(bantu!=NULL){
		cout<<bantu->data<<" -> ";
		bantu=bantu->next;
	}

	if (bantu == NULL){
		cout << "NULL";
	}
}


