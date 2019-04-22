#include <iostream>
using namespace std;

//daftar fungsi
int pil;
void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void hapus_belakang();
void hapus_depan();
void tampil();
void tambah_tengah();
void hapus_tengah();

//membuat sebuah struct node
struct node
{
char nama [20];
int umur;
float tinggi;
node *prev, *next;
};
node *baru, *head=NULL, *tail=NULL,*hapus,*bantu,*bantu2;

//fungsi main
int main()
{
do{

				cout<<"MENU DOUBLE LINKEDLIST"<<endl;
				cout<<"1. Tambah Depan"<<endl;
				cout<<"2. Tambah Belakang"<<endl;
				cout<<"3. Hapus Depan"<<endl;
				cout<<"4. Hapus Belakang"<<endl;
				cout<<"5. Tampilkan"<<endl;
				cout<<"6. Tambah Tengah"<<endl;
				cout<<"7. Hapus Tengah"<<endl;
				cout<<"8. Selesai"<<endl;
				cout<<"Pilihan Anda : ";
				cin>>pil;

				pilih();

	}while(pil!=8);
}

void pilih()
{
if(pil==1)
tambah_depan();
else if(pil==2)
tambah_belakang();
else if(pil==3)
hapus_depan();
else if(pil==4)
hapus_belakang();
else if(pil==5)
tampil();
else if(pil==6)
tambah_tengah();
else if(pil==7)
hapus_tengah();
else
cout<<"selesai";
}

//fungsi membuat node baru
void buat_baru()
{
baru = new(node);
cout<<"input nama : ";cin>>baru->nama;
cout<<"input umur : ";cin>>baru->umur;
cout<<"input tinggi : ";cin>>baru->tinggi;
baru->prev=NULL;
baru->next=NULL;
}
//fungsi menambah node baru di belakang
void tambah_belakang()
{
buat_baru();
if(head==NULL)
{
head=baru;
tail=baru;
}
else
{
tail->next=baru;
baru->prev=tail;
tail=baru;
}
cout<<endl<<endl;
tampil();
}

//fungsi menambah node baru di Depan
void tambah_depan()
{
buat_baru();
if(head==NULL)
{
head=baru;
tail=baru;
 }
else
{
baru->next=head;
head->prev=baru;
head=baru;
}
cout<<endl<<endl;
tampil();
}

//fungsi menghapus node yang berada didepan
void hapus_depan()
{
if (head==NULL)
cout<<"Kosong";
else if (head->next==NULL)
{
hapus=head;
head=NULL;
tail=NULL;
delete hapus;
}
else
{
hapus=head;
head=hapus->next;
head->prev=NULL;
delete hapus;
}
cout<<endl<<endl;
tampil();
}

//fungsi menghapus node yang berada dibelakang
void hapus_belakang()
{
if (head==NULL)
cout<<"Kosong";
else if (head->next==NULL)
{
hapus=head;
head=NULL;
tail=NULL;
delete hapus;
}
else
{
hapus=tail;
tail=hapus->prev;
tail->next=NULL;
delete hapus;
}
cout<<endl<<endl;
tampil();
}

//fungsi menampilkan susunan linked list
void tampil()
{
	if (head==NULL)
	cout<<"Kosong";
	else
	{
	bantu=head;
	while(bantu!=NULL)
		{
			cout<<" nama : "<<bantu->nama;
			cout<<" umur : "<<bantu->umur;
			cout<<" tinggi : "<<bantu->tinggi<<endl;
			bantu=bantu->next;
		}
	}
}


//fungsi menambah di tengah(bagian yang diinginkan)
void tambah_tengah()
{
     int sisip;
     cout<<"Masukan Posisi Sisip Anda : ";cin>>sisip;
     bantu=head;

     for(int i=1;i<sisip-1;i++)
     {
       bantu=bantu->next;
     }

     buat_baru();

     bantu2=bantu->next;
     bantu->next=baru;
     baru->prev=bantu;
     baru->next=bantu2;
     bantu2->prev=baru;
}

//yazidsupriadi14@gmail.com

//fungsi menghapus di tengah(bagian yang diinginkan)
void hapus_tengah()
{
  int sisip;
   cout<<"Masukan Posisi Sisip Anda : ";cin>>sisip;
   bantu=head;

   for(int i=1;i<sisip-1;i++)
   {
    bantu=bantu->next;
   }
   hapus=bantu->next;
   bantu2=hapus->next;
   bantu->next=hapus->next;
   bantu2->prev=bantu;
   delete hapus;

}
