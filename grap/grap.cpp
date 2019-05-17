//masih errorrrrrrrrrrrrrrrrrrrr
#include <iostream>
using namespace std;

int main(){
bool ketemu,nolsemua;
int matrix[10] [10];
int i,j,jumlah_simpul,jumlah_sisi,asal,tujuan;
//isnisialisasi matrix
cout<<"jumlah simpul:";
cin>>jumlah_simpul;
cout<<"jumlah_sisi:";
cin>>jumlah_sisi;
for (i=1;i<=jumlah_simpul;i++)
for (j=1;j<=jumlah_simpul;j++)
matrix[i][j]=0;
//isi matrix sesuai input graf
for (i=1;i<=jumlah_sisi;i++){
cout<<"simpul asal:";
cin>>asal;
cout<<"simpul tujuan:";
cin>>tujuan;
matrix[asal][tujuan]=1;
matrix[tujuan][asal]=1;
}
//telusuri graf
i=1;nolsemua=false;
while (i<=jumlah_simpul && !nolsemua){
j=1;ketemu=false;
while (j<=jumlah_simpul && !ketemu){
if (matrix[i][j]==1)
ketemu=true;
else
j++;
}
if (!ketemu)
nolsemua=true;
else
i++;
}

if(nolsemua)
cout<<"graf tidak terhubung";
else
cout<<"graf terhubung";
//getch();

}
