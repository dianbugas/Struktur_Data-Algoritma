#include <iostream>
using namespace std;

void insertsort(int data[], int n);
void insertsortdesc(int data[], int n);

int main(){
	int data[10] = {3,0,1,8,7,2,5,4,9,6};
	int n = 10;

	cout << "Data sebelum di urut : ";
	for (int i = 0; i<10; i++){
		cout << data[i] << " ";
	}
	cout << endl;

	insertsort(data, n); //tinggal di ganti aja mau pakai fungsi asc atau desc

	cout << "Data sesudah di urut : ";
	for (int i = 0; i<10; i++){
		cout << data[i] << " ";
	}

}

// Insertion sort asc
void insertsort(int data[], int n){
	int temp, j;
	for (int i=1; i<n; i++){
		temp = data[i];
		j = i;
		while (data[j]<data[j-1] && j>0){
			data[j] = data[j-1];
			data[j-1] = temp;
			j--;
		}
	}
}


//insert sorut desc
void insertsortdesc(int data[], int n){
    int temp, j;
	for (int i=0; i<n; i++){
		temp = data[i];
		j = i;
		while (data[j]>data[j-1] && j>0){
			data[j] = data[j-1];
            data[j-1] = temp;
            j--;
		}
	}
}

