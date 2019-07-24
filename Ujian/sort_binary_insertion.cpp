#include <iostream>
using namespace std;

int main(){
	int data[10] = {3,0,1,8,7,2,5,4,9,6};
	
	cout << "Data sebelum di urut : ";
	for (int i = 0; i<10; i++){
		cout << data[i] << " ";
	} 
	cout << endl;
	
	// Binary insertion sort
	int i=1;
	int j, x, l, r, m;
	while(i<10){
		x = data[i];
		l = 0;
		r = i-1;
		while(l<=r){
			m = (l+r)/2;
			if(x<data[m]){
				r = m-1;
			}
			else {
				l = m+1;
			}
		}
		j = i-1;
		while (j>=l){
			data[j+1] = data[j];
			j--;
		}
		data[l] = x;
		i++;
	}
	
	cout << "Data sesudah di urut : ";
	for (int i = 0; i<10; i++){
		cout << data[i] << " ";
	} 
	
}
