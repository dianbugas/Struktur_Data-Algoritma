#include <iostream>
using namespace std;

//deklarasi
struct node{
	int data;
	node * next;
};
node *head = NULL, *tail = NULL, *entry, *temp;

void enqueue(){
	int a;

	cout << "input data : "; cin >> a;

	entry = new node;
	entry->data = a;
	 //head= head->next; memindahkan kepalanya
	entry->next = NULL;
	if (head == NULL) {
		head = entry;
		tail = entry;
	}else{
		tail->next = entry;
		tail = entry;
	}
}

void display(){
	if(head == NULL) {
		cout<<"\n Tidak tidak ada"<<endl;
	}else{
		temp = head;
		while (temp != NULL) {
			cout<<temp->data<<" -> ";
			temp = temp->next;
		}
		cout<<"NULL";
	}
}

int main()
{
	while(true){
	int pilih;
	cout << "[1] input bos qu"<<endl;
	cout << "[2] Cetak BOS QU" << endl;
	cout << "Masukan Pilihan:"; cin >> pilih;
	//untuk pilihannya
	switch(pilih){
		case 1 : enqueue();
			break;
		case 2 : display();
			break;

		default: cout << "inputan salah";
			break;
	}
 }
}
