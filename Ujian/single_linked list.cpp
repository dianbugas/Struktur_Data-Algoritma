#include <iostream>
using namespace std;

void menu();
void input(int dt);
void tambahDepan(int dt);
void tambahTengah(int pos, int value);
void hapusDepan();
void hapusBelakang();
void hapusTengah(int pos);
void ubahDepan(int dt);
void ubahTengah(int pos, int dt);
void ubahBelakang(int dt);
void cetak();
void cetakDepan();
void cetakTengah(int pos);
void cetakBelakang();

struct node{
      int data;
      node* next;
};

node *head, *tail, *curr, *pre, *entry, *del, *temp;

void inisialisasi(){
    head = NULL;
    tail = NULL;
}

int main(){
    menu();
}

void menu(){
	char ulang;
    int data, pilih, pos;

    do {
//    	system("cls");
    	cout<<"SINGLE LINKED LIST NON CIRCULAR"<<endl;
      	cout<<"-------------------------------"<<endl;
      	cout<<"Menu : "<<endl;
		cout<<"[1] Input data"<<endl;
      	cout<<"[2] Tambah Depan"<<endl;
      	cout<<"[3] Tambah Tengah"<<endl;
      	cout<<"[4] Hapus Depan"<<endl;
      	cout<<"[5] Hapus Belakang"<<endl;
      	cout<<"[6] Hapus Tengah"<<endl;
      	cout<<"[7] Ubah Depan"<<endl;
      	cout<<"[8] Ubah Tengah"<<endl;
      	cout<<"[9] Ubah Belakang"<<endl;
      	cout<<"[10] Cetak Data"<<endl;
      	cout<<"[11] Cetak Depan"<<endl;
      	cout<<"[12] Cetak Tengah"<<endl;
      	cout<<"[13] Cetak Belakang"<<endl;
      	cout<<"[14] Exit"<<endl;
      	cout<<"Masukkan pilihan Anda : ";
      	cin>>pilih;

      	switch(pilih) {
      		case 1 :
    			cout<<"\nMasukkan data : ";
            	cin>>data;
            	input(data);
            	break;
			case 2 :
		    	cout<<"\nMasukkan data : ";
		        cin>>data;
		        tambahDepan(data);
		        break;
		    case 3 :
		        cout<<"\nMasukkan data : ";cin>>data;
		        cout<<"\nPada posisi ke : ";cin>>pos;
		        tambahTengah(pos, data);
		        break;
      		case 4 :
            	hapusDepan();
            	break;
            case 5 :
            	hapusBelakang();
            	break;
            case 6 :
            	cout<<"\nPada posisi ke : ";cin>>pos;
            	hapusTengah(pos);
            	break;
            case 7 :
		    	cout<<"\nMasukkan data baru : "; cin>>data;
		        ubahDepan(data);
		        break;
		    case 8 :
		    	cout<<"\nMasukkan data baru : "; cin>>data;
		    	cout<<"\nPada posisi ke : "; cin>>pos;
		        ubahTengah(pos, data);
		        break;
		    case 9 :
		    	cout<<"\nMasukkan data baru : ";
		        cin>>data;
		        ubahBelakang(data);
		        break;
      		case 10 :
            	cetak();
            	break;
            case 11 :
            	cetakDepan();
            	break;
            case 12 :
            	cout<<"\nTampilkan data pada posisi ke : "; cin>>pos;
            	cetakTengah(pos);
            	break;
            case 13 :
            	cetakBelakang();
            	break;
      		case 14 :
//            	exit(0);
            	break;
      		default :
            	cout<<"\nPilih ulang"<<endl;
		}
		//aaauzannn

      	cout<<"\nKembali ke menu?(y/n)";
      	cin>>ulang;

	} while (ulang=='y' || ulang=='Y');
}

void input(int dt){
      entry = new node;
      entry->data = dt;
      entry->next = NULL;
      if(head==NULL){
            head = entry;
            tail = entry;
            entry=NULL;
      }
      else
      {
            tail->next = entry;
            tail = entry;
      }
      // aauuuzzann
}

void tambahDepan(int dt){
	entry = new node;
    entry->data = dt;
    entry->next = NULL;
    //auuuzan
    if (head == NULL){
    	//entry->next = head;
    	head = entry;
    	tail = entry;
	}
	else {
		entry->next = head;
    	head = entry;
	}
}

void tambahTengah(int pos, int dt){
	entry = new node;
	curr = head;
	for (int i=1;i<pos;i++){
		pre = curr;
		curr = curr->next;
	}
	//auzaaan
	entry->data = dt;
	pre->next = entry;
	entry->next = curr;
}

void hapusDepan(){
	if(head==NULL){
		cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
    }
    //auuzzzzannn
    else{
		temp=head;
		head=head->next;
		delete temp;
	}
}

void hapusBelakang(){
	curr = head;
	while (curr->next!=NULL){
		pre = curr;
		curr = curr->next;
	}
	tail = pre;
	pre->next = NULL;
	delete curr;
	//auzan
}

void hapusTengah(int pos){
	curr = head;
	//auuuuuzaaan
	for(int i=1;i<pos;i++){
		pre = curr;
		curr = curr->next;
	}
	pre->next = curr->next;
}

void ubahDepan(int dt){
	if(head==NULL){
		cout<<"\nlinked list kosong, perubahan tidak bisa dilakukan"<<endl;
    }
    else {
    	head->data = dt;
	}
}

void ubahTengah(int pos, int dt){
	curr=head;
	for(int i=1;i<pos;i++){
		curr=curr->next;
	}
	curr->data = dt;
}

void ubahBelakang(int dt){
	if(head==NULL){
		//auuzzaan
		cout<<"\nlinked list kosong, perubahan tidak bisa dilakukan"<<endl;
    }
    else {
    	tail->data = dt;
	}
}

void cetak(){
	//node *temp=new node;
	////aaauzan
	temp=head;
	if(head == NULL)
        cout<<"\ntidak ada data dalam linked list"<<endl;
    else{
    	cout<<"\nData yang ada dalam linked list adalah"<<endl;
		while(temp!=NULL){
			cout<<temp->data<<" -> ";
			temp=temp->next;
		}
		cout<<"NULL";
        cout<<endl;
	}
}

void cetakDepan(){
	if(head == NULL)
        cout<<"\nTidak ada data dalam linked list"<<endl;
    else{
    	cout<<"\nData pertama adalah " << head->data << endl;;
	}
}

void cetakTengah(int pos){
	if (head == NULL)
        cout<<"\nTidak ada data dalam linked list"<<endl;
    else{
    	cout<<"\nData ke-"<<pos<<" adalah ";
		curr=head;
		for(int i=1;i<pos;i++){
			curr=curr->next;
		}
		cout << curr->data << endl;;
	}

}

void cetakBelakang(){
	if (head == NULL)
        cout << "\nTidak ada data dalam linked list"<<endl;
    else{
    	cout << "\nData terakhir adalah " << tail->data << endl;
	}
	//aauzan
}


