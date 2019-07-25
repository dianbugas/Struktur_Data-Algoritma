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

	// Shell sort
    bool sudah;
    int j, temp;
    int gap = n;
    while (gap>1){
    	gap = gap/2;
    	sudah = false;
    	while (sudah == false){
    		sudah = true;
    		j = 0;
    		while (j<n-gap){
    			if (data[j+gap]<data[j]){
    				temp = data[j+gap];
    				data[j+gap] = data[j];
					data[j] = temp; 
				}
				j++;
			}
		}
	}
	
	cout << "Data sesudah di urut : ";
	for (int i = 0; i<10; i++){
		cout << data[i] << " ";
	} 
	
}
