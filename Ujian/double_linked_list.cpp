#include <iostream>
using namespace std;

void menu();
int jumlah();
void input(int dt);
void tambahDepan(int dt);
void tambahTengah(int pos, int value);
void hapusDepan();
void hapusBelakang();
void hapusTengah(int pos);
void ubahDepan(int dt);
void ubahTengah(int pos, int dt);
void ubahBelakang(int dt);
void cetakDariDepan();
void cetakDariBelakang();
void cetakDepan();
void cetakTengah(int pos);
void cetakBelakang();

struct node{
      int data;
      node *next;
      node *prev;
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
    	system("cls");
    	cout<<"DOUBLE LINKED LIST NON CIRCULAR"<<endl;
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
      	cout<<"[10] Cetak Data dari depan"<<endl;
      	cout<<"[11] Cetak Data dari belakang"<<endl;
      	cout<<"[12] Cetak Depan"<<endl;
      	cout<<"[13] Cetak Tengah"<<endl;
      	cout<<"[14] Cetak Belakang"<<endl;
      	cout<<"[15] Jumlah Linked list"<<endl;
      	cout<<"[16] Exit"<<endl;
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
            	cetakDariDepan();
            	break;
            case 11 :
            	cetakDariBelakang();
            	break;
            case 12 :
            	cetakDepan();
            	break;
            case 13 :
            	cout<<"\nTampilkan data pada posisi ke : "; cin>>pos;
            	cetakTengah(pos);
            	break;
            case 14 :
            	cetakBelakang();
            	break;
            case 15 :
            	cout << "\nTotal Linked list ada : " << jumlah();
            	break;
      		case 16 :
            	exit(0);
            	break;
      		default :
            	cout<<"\nPilih ulang"<<endl;
		}
		//aaauzannn
		
      	cout<<"\nKembali ke menu?(y/n)";
      	cin>>ulang;
      	
	} while (ulang=='y' || ulang=='Y');
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

void input(int dt){
      entry = new node;
      entry->data = dt;
      entry->next = NULL;
      entry->prev = NULL;
      if(head==NULL){
            head = entry;
            tail = entry;
            //entry = NULL;
      }
      else {
            tail->next = entry;
            entry->prev = tail;
            tail = entry;
      }
      // aauuuzzann
}

void tambahDepan(int dt){
	entry = new node;
    entry->data = dt;
    entry->next = NULL;
    entry->prev = NULL;
    //auuuzan
    if (head == NULL){
    	//entry->next = head;
    	head = entry;
    	tail = entry;
	}
	else {
		entry->next = head;
		head->prev = entry;
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
	curr->prev = entry;
	entry->prev = pre;
}

void hapusDepan(){
	if(head==NULL){
		cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
    }
    else if (jumlah() == 1){
    	temp = head;
		head = NULL;
		delete temp;
	}
    //auuzzzzannn
    else{
		temp = head;
		head = head->next;
		head->prev = NULL;
		temp->next = NULL;
		delete temp;
	}
}
		
void hapusBelakang(){
	if(head==NULL){
		cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
    }
    else {
		curr = head;
		while (curr->next != NULL){
			pre = curr;
			curr = curr->next;	
		}
		tail = pre;
		curr->prev = NULL;
		tail->next = NULL;
		//auzan
	}
}
		
void hapusTengah(int pos){
	if(head==NULL){
		cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
    }
    else if (pos > jumlah() || pos < 1){
    	cout << "\nPosisi tidak ada pada linked list"<<endl;
	}
    else {
    	curr = head;
		//auuuuuzaaan
		for(int i=1; i<pos; i++){
			pre = curr;
			curr = curr->next;
		}
		temp = curr->next;
		pre->next = temp;
		temp->prev = pre;
		curr->next = NULL;
		curr->prev = NULL;
		delete curr;
	}
	
	
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

void cetakDariDepan(){
	//node *temp=new node;
	////aaauzan
	temp=head;
	if(head == NULL)
        cout<<"\ntidak ada data dalam linked list"<<endl;
    else{
    	cout<<"\nData yang ada dalam linked list adalah"<<endl;
    	cout << "NULL <-> ";
		while(temp!=NULL){
			cout<<temp->data<<" <-> ";
			temp=temp->next;
		}
		cout<<"NULL";
        cout<<endl;
	}
}

void cetakDariBelakang(){
	//node *temp=new node;
	////aaauzan
	temp=tail;
	if(tail == NULL)
        cout<<"\ntidak ada data dalam linked list"<<endl;
    else{
    	cout<<"\nData yang ada dalam linked list adalah"<<endl;
    	cout << "NULL <-> ";
		while(temp != NULL){
			cout << temp->data << " <-> ";
			temp = temp->prev;
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
    else if (pos > jumlah() || pos < 1){
    	cout <<"\nPosisi tidak ada di linked list"<< endl;
	}
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


