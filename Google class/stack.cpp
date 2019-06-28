#include <iostream>
#define maxstack 5
using namespace std; //untuk melegalkan header iostream

//pendeklarasian struct
struct STACK
{
      int top;
      float data[4];
};
float dta;

/*struct yang telah dibuat (STACK) dijadikan suatu Tipe data, dimana disebut tipe data abstrak*/
struct STACK stackbaru;

//fungsi boolean untuk mengetahui apakah stack penuh
bool isfull()
{
      if(stackbaru.top == maxstack)
            return true;
      else
            return false;
}

//fungsi boolean untuk mengetahui apakah stack kosong
bool isempty()
{
      if(stackbaru.top == -1)
            return true;
      else
            return false;
}

//fungsi untuk menambahkan data pada stack
void push(float dta)
{
     if(isfull() == true) /*panggil fungsi isempty(), jika kondisi benar pernyataan dijalankan*/
      {
            cout<<"Maaf, stack penuh";
      }
      else{
            stackbaru.top++;
            stackbaru.data[stackbaru.top]=dta;
      }
}

//fungsi untuk mengambil data pada stack
void pop()
{
      if(isempty() == true) //panggil fungsi isempty(), jika kondisi benar pernyataan dijalankan
      {
            cout<<"Data telah kosong!";
      }
      else
      {
            cout<<"Data yang terambil : " <<stackbaru.data[stackbaru.top]<<endl;
            stackbaru.top--;
      }
}

//fungsi untuk mencetak data pada stack
void print()
{
      cout<<"\nData yang terdapat dalam stack : \n";
      cout<<"--------------------------------\n";
      for(int i=0; i<=stackbaru.top; i++)
      {
            cout<<stackbaru.data[i]<<"    ";
      }
}

//fungsi untuk membersihkan data dalam stack
void clear()
{
      stackbaru.top = -1;
      cout<<"\nSekarang stack kosong";
}

//fungsi utama
int main()
{
      stackbaru.top = -1;
      //pendeklarasian variabel
      char menu;
      char ulang;
      //perulangan dengan do-while
      do
      {
//            system("cls");
            cout<<"\t PROGRAM STACK\n";
            cout<<"\t===============\n";
            cout<<"Menu : ";
            cout<<"\n1. Pop stack"<<endl;
            cout<<"2. Push stack"<<endl;
            cout<<"3. Cetak"<<endl;
            cout<<"4. Bersihkan stack"<<endl;
            cout<<"5. Exit"<<endl;

            cout<<"Menu pilihan Anda : ";
            cin>>menu;

            if(menu == '1')
            {
                  pop(); //panggil fungsi pop()
                  ulang = 'y';
//                  getch();
            }
            else if(menu == '2')
            {
                  cout<<"\nTambah Data";
                  cout<<"\n-----------";
                  cout<<"\nData yang akan disimpan di stack : ";
                  cin>>dta;
                 push(dta); /*panggil fungsi push(dta)--dta sesuai dengan data ynag diinput*/
                  ulang = 'y';
            }
            else if(menu == '3')
            {
                  print(); /*panggil fungsi untuk mencetak data dalam stack*/
                  cout<<"\n\nUlang ? (y/t)";
                  cin>>ulang;
            }
            else if(menu == '4')
            {
                  clear(); //panggil fungsi untuk membersihkan stack
                  cout<<"\n\nUlang ? (y/t)";
                  cin>>ulang;
            }
            else if(menu == '5')
            {
                  //exit(); //keluar dari program
            }
       }while(ulang == 'Y' || ulang == 'y'); /*akan selalu diulang ketika ulang == 'y' || ulang'Y'*/
}
