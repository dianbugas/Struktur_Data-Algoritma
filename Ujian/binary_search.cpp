#include <iostream>

using namespace std;

int main(){
 const int array[5] = {1,2,3,4,5};
 int cari;
 int posisiTerendah=0, posisiTertinggi=5, posisiTengah;

 for(int i=0;i<5;i++){
  cout<<"Data "<<array[i]<<" Tersimpan Pada Urutan Ke-"<<i+1<<endl;
 }

 cout<<endl;

 cout<<"Masukkan Angka Yang Akan Di Cari : ";
 cin>>cari;

 while (posisiTerendah <= posisiTertinggi){
  posisiTengah = (posisiTerendah + posisiTertinggi)/2;
    if (cari > array[posisiTengah] ){
   posisiTerendah = posisiTengah + 1;
  }
    else if (cari < array[posisiTengah]){
     posisiTertinggi= posisiTengah - 1;
  }
    else {
     posisiTerendah = posisiTertinggi +1;
  }
   }

 if (cari == array[posisiTengah]){
     cout<<"Data Di Temukan Pada Urutan Ke-"<<posisiTengah+1<<endl;
 }
 else{
  cout<<"Data Yang Anda Cari Tidak Ada."<<endl;
 }

}
