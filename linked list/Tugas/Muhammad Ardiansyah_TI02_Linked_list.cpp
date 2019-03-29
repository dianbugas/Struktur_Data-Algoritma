#include<iostream>

using namespace std;

struct TNode{
	int data;
	TNode *next;
	TNode *prev;
};

TNode *head;
TNode *tail;
TNode *baru;
TNode *help;
TNode *delet;


void inisialisasi(){
	head = NULL;
}

bool apakahKosong(){
	if (head == NULL)
		return true;
	else
		return false;
}

void tambahDepan(int dataBaru){
	//buat node baru
	baru = new TNode;
	baru->data = dataBaru;
	baru->next = NULL;

	//cek apakah list kosong atau tidak
	if (apakahKosong()){
		head = baru;
		tail = baru;
		head->next = NULL;
	}else{
		baru->next = head;
		head = baru;
	}
}
int menghitungList(){
	if (apakahKosong()){
		cout<<"list kosong"<<endl;
		return 0;
	}else{

		help = head;
		int jumlah=1;
		while (help->next != NULL){
			jumlah=jumlah+1;
			help = help->next;
		}
		return jumlah;
	}
}
//untuk menampilkan data yg kedepan
void menampilkanIsi(){
	if(apakahKosong()){
		cout<<"List kosong"<<endl;
	}else if(head->next == NULL){
		cout<<head->data<<endl;
	}else{
		help = head;
		while (help != NULL){
			cout<<help->data<<" ";
			help = help->next;
		}
		cout<<endl;
	}
}
//untuk menambahkan data di tengah
void tambahTengah(int dataBaru, int posisi){
	int jumlah = menghitungList();
	if(jumlah >= posisi){
		help = head;
		int posisiBantu=1;
		for(int i=1; i<(posisi-1); i++){
			help = help->next;
		}
		//sisipkan baru
		baru = new TNode;
		baru->data = dataBaru;
		baru->next = NULL;

		baru->next = help->next;
		help->next = baru;
}
}

//untuk menambahkan data di akhir
void tambahBelakang(int dataBaru){
	//buat node baru
	baru = new TNode;
	baru->data = dataBaru;
	baru->next = NULL;

	//cek apakah list kosong atau tidak
	if (apakahKosong()){
		head = baru;
		tail = baru;
		head->next= NULL;
	}else{
		tail->next= baru;
		tail = baru;
	}
}
//Delete
void gadel()
{
	cout<<"TIDAK ADA DATA YANG DIHAPUS\n";
}

void menghapusdepan(){
	if(apakahKosong()){
		cout<<"List kosong"<<endl;
	}else{
		delet = head;
		head = head->next;
		delet->next = NULL;
		delete(delet);
	}
}

void menghapusbelakang(){
	if(apakahKosong()){
		cout<<"list kosong"<<endl;
	}else if(head->next== NULL){
		delet = head;
		head = NULL;
		tail = NULL;
		delete(delet);
	}else{
		help = head;
		while (help->next != tail){
			help = help->next;
		}

		delet = tail;
		tail = help;
		tail->next= NULL;
		delete(delet);
	}
}

void menghapustengah(int s)
{
	delet=head;
	int cek=0;
	while(delet->data!=s)
	{
		if(delet->next==NULL)
		{
			cek=1;
			break;
		}
		delet = delet->next;
	}
	if(cek==0)
	{
		delet->prev->next = delet->next;
		delet->next->prev = delet->prev;
		delete(delet);
	}
	else
		gadel();
}







int main(){
    inisialisasi();
    tambahDepan(2);
    tambahBelakang(5);
    tambahBelakang(6);
    tambahDepan(1);
    tambahBelakang(7);
    tambahTengah(3,3);
    tambahTengah(4,4);


    cout<<"=====================Tugas======================="<<endl;
    cout<<"1 kaitkan node baru di depan head"<<endl;
    cout<<"2 kaitkan node baru di belakang tail"<<endl;
    cout<<"3 kaitkan node baru di antara head dan tail"<<endl;
    cout<<"4,5,6 (hapus depan, hapus tengah, dan hapus belakang"<<endl;
    cout<<"================================================="<<endl;//
	cout<<"isi list: ";
	menampilkanIsi();
	cout<<"Jumlah List :"<<menghitungList()<<endl;
	//delete
	menghapusdepan();
	menghapusbelakang();
	menghapustengah(3);
	cout<<"isi list: ";
	menampilkanIsi();
	cout<<"Jumlah List :"<<menghitungList()<<endl;
}

//Latihan sebelumnya
//baru = new TNode;
	//baru->data = 10;
	//baru->next = NULL;

	//head = baru;
	//tail = baru;
	//cout<<"nilai baru : "<<baru->data<<endl;
	//cout<<"nilai head : "<<head->data<<endl;
	//cout<<"nilai tail : "<<tail->data<<endl;
    //cout<<"==============="<<endl;
	//baru = new TNode;
	//baru->data = 15;
	//baru->next = NULL;
	//cout<<"nilai head : "<<head->data<<endl;
	//cout<<"nilai baru : "<<baru->data<<endl;
	//head->next = baru;
	//tail = baru;

	//baru = new TNode;
	//baru->data = 20;
	//baru->next = NULL;

