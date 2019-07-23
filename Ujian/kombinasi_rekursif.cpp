#include <iostream>
using namespace std;

int faktorialpertama(int a){
    if(a==1){
        return a;
    }else{
        return a * faktorialpertama(a-1);
    }
}
//sama faktorial yg di atas
long int faktorial(int a)
{           int fak, i;
            fak = 1;
            for(i = 1; i<=a ; i++)
            fak = fak * i;
            return(fak);
}

int kombinasirekursif(int a, int b){
    if(a<b){
        return 0;
    }else{
        return faktorialpertama(a) / (faktorialpertama(b) * faktorialpertama(a-b));
    }
}

int pemutasirekursif(int a, int b){
    if(a<b){
        return 0;
    }else{
        return (faktorialpertama(a) / faktorialpertama(a-b));
    }
}


int main(){
	int a,b;
	cout << "jumlah nilainya: ";
	cin >> a;
	cout << "jumlah yg harus kita pilih: ";
	cin >> b;
	cout << "hasil kombinasi = " << kombinasirekursif(a,b) << endl;
	cout << "hasil pemutasi = " << pemutasirekursif(a,b)<<endl;
	cin.get();
	return 0;
}
