#include<iostream>
using namespace std;

int main(){
    int array[5],index[5];
    int caridata,y,x=0;

    for(y=0;y<5;y++){
        cout<<"Masukkan Angka Pada Urutan Ke-"<<y<<" : ";
        cin>>array[y];
    }
        cout<<endl;
        cout<<"Masukkan Data Yang Ingin Di Cari : ";
        cin>>caridata;
            for(y=0;y<=5;y++){
                if(array[y]==caridata){
                    index[x]=y;
                       x++;
                      }
            }
            if(x>0){
              cout<<"Data "<<caridata<<" Terletak Pada Array Urutan Ke-";
              for(y=0;y<x;y++){
               cout<<index[y]<<" ";
              }
              cout<<endl;
             } else {
              cout<<"Data Tidak Di Temukan";
             }
}
