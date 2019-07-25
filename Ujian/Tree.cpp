//header file
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//pendeklarasian struct sebuah tree awal
struct Node{
      int data;
      Node *kiri;
      Node *kanan;
};

//fungsi untuk menambahkan node baru
void tambah(Node **root, int databaru)
{
      //jika root masih kosong
      if((*root) == NULL)
      {
            //pembuatan node baru
            Node *baru;
            //pengalokasian memori dari node yang telah dibuat
            baru = new Node;
            //inisialisasi awal node yang baru dibuat
            baru->data = databaru;
            baru->kiri = NULL;
            baru->kanan = NULL;
            (*root) = baru;
            (*root)->kiri = NULL;
            (*root)->kanan = NULL;
            printf("Data bertambah!");
      }
     //jika data yang akan dimasukkan lebih kecil daripada elemen root, maka akan diletakkan di node sebelah kiri.
      else if(databaru<(*root)->data)
            tambah(&(*root)->kiri, databaru);
     //jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan
      else if(databaru>(*root)->data)
            tambah(&(*root)->kanan, databaru);
     //jika saat dicek data yang akan dimasukkan memiliki nilai yang sama dengan data pada root
      else if(databaru == (*root)->data)
            printf("Data sudah ada!");
}

//fungsi yang digunakan untuk mencetak tree secara preOrder
void preOrder(Node *root)
{
      if(root != NULL){
            printf("%d ", root->data);
            preOrder(root->kiri);
            preOrder(root->kanan);
      }
}

//fungsi yang digunakan untuk mencetak tree secara inOrder
void inOrder(Node *root)
{
      if(root != NULL){
            inOrder(root->kiri);
            printf("%d ", root->data);
            inOrder(root->kanan);
      }
}

//fungsi yang digunakan untuk mencetak tree secara postOrder
void postOrder(Node *root)
{
      if(root != NULL){
            postOrder(root->kiri);
            postOrder(root->kanan);
            printf("%d ", root->data);
      }
}

//fungsi utama
int main()
{
      //deklarasikan variabel
      int pil, data;// c;
      Node *pohon; //*t;
      pohon = NULL; //inisialisasi node pohon
      //perulangan do-while
      do
      {
            system("cls"); //bersihkan layar
            printf("\t#PROGRAM TREE C++#");
            printf("\n\t==================");
            printf("\nMENU");
            printf("\n----\n");
            printf("1. Tambah\n");
            printf("2. Lihat pre-order\n");
            printf("3. Lihat in-order\n");
            printf("4. Lihat post-order\n");
            printf("5. Exit\n");
            printf("Pilihan : ");
            scanf("%d", &pil);
            switch(pil)
            {
            //jika pil bernilai 1
            case 1 :
                  printf("\nINPUT : ");
                  printf("\n-------");
                  printf("\nData baru : ");
                  scanf("%d", &data);
                  //panggil fungsi untuk menambah node yang berisi data pada tree
                  tambah(&pohon, data);
                  break;
                 
            //jika pil bernilai 2
            case 2 :
                  printf("\nOUTPUT PRE ORDER : ");
                  printf("\n------------------\n");
                  if(pohon!=NULL)
                       //panggil fungsi untuk mencetak data secara preOrder
                        preOrder(pohon);
                  else
                        printf("Masih kosong!");
                  break;
                 
            //jika pil bernilai 3
            case 3 :
                  printf("\nOUTPUT IN ORDER : ");
                  printf("\n------------------\n");
                  if(pohon!=NULL)
                       //panggil fungsi untuk mencetak data secara inOrder
                        inOrder(pohon);
                  else
                        printf("Masih kosong!");
                  break;
           
            //jika pil bernilai 4
            case 4 :
                  printf("\nOUTPUT POST ORDER : ");
                  printf("\n------------------\n");
                  if(pohon!=NULL)
                       //panggil fungsi untuk mencetak data secara postOrder
                        postOrder(pohon);
                  else
                        printf("Masih kosong!");
                  break;
            }
            _getch();
      }while(pil != 5); //akan diulang jika input tidak samadengan 5
      return EXIT_FAILURE;
}


