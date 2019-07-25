#include <iostream>
using namespace std;

int main(){
	int data[10] = {3,0,1,8,7,2,5,4,9,6};
	int n = 10;
	
	cout << "Data sebelum di urut : ";
	for (int i = 0; i<10; i++){
		cout << data[i] << " ";
	} 
	cout << endl;
	
	// Selection sort
	int temp, i, j;
	for(i=0; i<n-1; i++){
		int min = i;
		for (j=i+1; j<n; j++){
			if (data[j]<data[min]){
				min = j;
			}
		}
		temp = data[min];
		data[min] = data[i];
		data[i] = temp;
	}
	
	
	cout << "Data sesudah di urut : ";
	for (int i = 0; i<10; i++){
		cout << data[i] << " ";
	} 
	
}
