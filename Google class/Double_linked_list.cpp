#include<iostream>
using namespace std;

struct simpul
{
	int data;
	node *prev;
	node *next;
};
node *head = NULL, *tail = NULL, *baru;

void allocate_node (int x)
{
	baru = (node *) malloc (sizeof(node));
	if(baru==NULL)
	{
		printf("Alokasi Gagal\n");
		exit(1);
	}
	else
	{
		baru->data=x;
		baru->next=NULL;
		baru->prev=NULL;
	}
}

void buat_list()
{
	printf("Data Masih Kosong, List akan dibuat dengan data tersebut\n");
	system("PAUSE");
	head = tail = baru;
}
void sisip_awal()
{
	if(head==NULL && tail==NULL)
		buat_list();
	else
	{
		baru->next=head;
		head->prev=baru;
		head=baru;
	}
}
void sisip_akhir()
{
	if(head==NULL && tail==NULL)
		buat_list();
	else
	{
		baru->prev=tail;
		tail->next=baru;
		tail=baru;
	}

}
void sisip_sebelum(int s)
{
	node *before=head;
	int cek=0;
	if(before->next==NULL)
		cek=1;
	else
	{
		while(before->next->data!=s)
		{
			before=before->next;
			if(before->next==NULL)
			{
				cek = 1;
				break;
			}
		}
	}
	if(cek==0)
	{
		baru->prev = before;
		baru->next = before->next;
		before->next->prev = baru;
		before->next = baru;
	}
	else
		gatot();
}

void sisip_sesudah(int s)
{
	node *after=tail;
	int cek=0;
	if(after->prev == NULL)
		cek=1;
	else
	{
		while(after->prev->data!=s)
		{
			after=after->prev;
			if(after->prev==NULL)
			{
				cek = 1;
				break;
			}
		}
	}
	if(cek==0)
	{
		baru->next = after;
		baru->prev = after->next;
		after->prev->next = baru;
		after->prev = baru;
	}
	else
		gatot();
}

void free_node(node *p)
{
	free(p);
	p=NULL;
	printf("DATA TERHAPUS\n");
}

void hapus_satu()
{
	node *hapus = head;
	head = NULL;
	tail = NULL;
	free_node(hapus);
}

void hapus_awal()
{
	node *hapus = head;
	head->next->prev = NULL;
	head =  head->next;
	free_node(hapus);
}

void hapus_akhir()
{
	node *hapus = tail;
	tail->prev->next = NULL;
	tail =  tail->prev;
	free_node(hapus);
}

void hapus_tengah(int s)
{
	node *hapus=head;
	int cek=0;
	while(hapus->data!=s)
	{
		if(hapus->next==NULL)
		{
			cek=1;
			break;
		}
		hapus = hapus->next;
	}
	if(cek==0)
	{
		hapus->prev->next = hapus->next;
		hapus->next->prev = hapus->prev;
		free_node(hapus);
	}
	else
		gadel();
}
void gatot()
{
	printf("SIMPUL BARU TIDAK DAPAT DISISIPKAN\n");
	system("PAUSE");
}

void gadel()
{
	printf("TIDAK ADA DATA YANG DIHAPUS\n");
	system("PAUSE");
}

void tampil()
{
	node *p= head;
	printf("\nData Simpul ==>  ");
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n\n");
}

void main()
{
	head=baru;
	int pilih, data, s;
	char lagi='y';
	while(lagi=='y')
	{
		system("CLS");
		awal();
		tampil();
		printf("Menu Pilihan : \n");
		printf("1. Sisip Awal\n");
		printf("2. Sisip Akhir\n");
		printf("3. Sisip Sebelum Simpul\n");
		printf("4. Sisip Sesudah Simpul\n");
		printf("5. Hapus Awal\n");
		printf("6. Hapus Akhir\n");
		printf("7. Hapus Tengah\n");
		printf("\nPilih No            : ");
		scanf("%d", &pilih);
		switch(pilih)
		{
		case 1 :
			printf("Masukkan data       : ");
			scanf("%d", &data);
			allocate_node(data);
			sisip_awal();
			break;
		case 2 :
			printf("Masukkan data       : ");
			scanf("%d", &data);
			allocate_node(data);
			sisip_akhir();
			break;
		case 3 :
			printf("Masukkan data       : ");
			scanf("%d", &data);
			allocate_node(data);
			if(head==NULL && tail==NULL)
				buat_list();
			else
			{
				printf("Dimasukkan sebelum  : ");
				scanf("%d",&s);
				if(s==head->data)
					sisip_awal();
				else
					sisip_sebelum(s);
			}
			break;
		case 4 :
			printf("Masukkan data       : ");
			scanf("%d", &data);
			allocate_node(data);
			if(head==NULL && tail==NULL)
				buat_list();
			else
			{
				printf("Dimasukkan sesudah  : ");
				scanf("%d",&s);
				if(s==tail->data)
					sisip_akhir();
				else
					sisip_sesudah(s);
			}
			break;
		case 5 :
			if(head == NULL && tail == NULL)
				gadel();
			else if(head == tail)
				hapus_satu();
			else
				hapus_awal();
			break;
		case 6 :
			if(head == NULL && tail == NULL)
				gadel();
			else if(head == tail)
				hapus_satu();
			else
				hapus_akhir();
			break;
		case 7 :
			printf("Data yang dihapus   : ");
			scanf("%d", &data);
			if(head == NULL && tail == NULL)
				gadel();
			else if(data == head->data && data == tail->data && head == tail)
				hapus_satu();
			else if(data == head->data)
				hapus_awal();
			else if(data == tail->data)
				hapus_akhir();
			else
				hapus_tengah(data);
			break;
		}
		fflush(stdin);
		printf("Lagi (y/t) ? ");
		scanf("%c", &lagi);
	}
}



