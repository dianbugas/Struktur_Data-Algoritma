#include <iostream>
//#include <windows.h>

using namespace std;

struct vertex{
	string info;
	vertex *right;
	vertex *left;
}*top = NULL, *bottom = NULL, *entry, *temp, *from, *to, *point, *ver, *edge;

void menu();
void tambahVertex();
void tambahEdge();
void lihatGraph();
bool vertexIsEmpty();
vertex* getVertex(string x);
vertex* bikinEdge(string x);

int main(){
	char pilih;
	do {
//		system("cls");
		menu();
		cout << "Kembali ke menu (y/t) ? ";
		cin >> pilih;
		pilih = toupper(pilih);
	} while (pilih == 'Y');
}

void menu(){
	char pilih;
	cout << "===== Menu =====" << endl;
	cout << "[1] Tambah Vertex" << endl;
	cout << "[2] Tambah Edge" << endl;
	cout << "[3] Lihat Graph" << endl;
	cout << "[4] Exit" << endl;
	cout << "Masukkan pilihan : ";
	cin >> pilih;
	switch (pilih){
		case '1' :
			tambahVertex();
			break;
		case '2' :
			tambahEdge();
			break;
		case '3' :
			lihatGraph();
			break;
		case '4' :
//			exit(0);
			break;
		default :
			cout << "Inputan salah, coba lagi" << endl;
//			Sleep(2000);
			menu();
			break;
	}
}

bool vertexIsEmpty(){
	if (top == NULL){
		return true;
	} else {
		return false;
	}
}

bool cariVertex(string x){
	bool ketemu = false;
	temp = top;
	while (!ketemu){
		if (temp->info == x){
			ketemu = true;
			return ketemu;
		} else if (temp->left == NULL) {
			return ketemu;
		}else {
			temp = temp->left;
		}
	}
}

vertex* getVertex(string x){
	if (cariVertex(x)){
		return temp;
	}
	else {
		return NULL;
	}
}

void tambahVertex(){
	string data;
	cout << "Masukkan Nama Vertex : ";
	cin >> data;

	entry = new vertex;
	entry->info = data;
	entry->left = NULL;
	entry->right = NULL;
	if (top == NULL){
		top = entry;
		bottom = entry;
	} else {
		bottom->left = entry;
		bottom = entry;
	}

}

void tambahEdge(){
	string data, awal, tujuan;
	a:
	cout << "Hubungkan Edge dari vertex : ";
	cin >> awal;

	if (cariVertex(awal)){
		from = getVertex(awal);
		b:
		cout << "Ke vertex : ";
		cin >> tujuan;

		if (cariVertex(tujuan)){
			to = getVertex(tujuan);
			cout << "Masukkan Nama Edge : ";
			cin >> data;

			edge = bikinEdge(data);

			if (from->right == NULL){
				from->right = edge;
				edge->left = to;
			} else {
				temp = from->right;
				while (temp->right != NULL){
					temp = temp->right;
				}
				temp->right = edge;
				edge->left = to;
			}

		} else {
			cout << "Vertex tidak di temukan" << endl;
//			Sleep(2000);
			goto b;
		}
	} else {
		cout << "Vertex tidak di temukan" << endl;
//		Sleep(2000);
		goto a;
	}

}

vertex* bikinEdge(string x){
	entry = new vertex;
	entry->info = x;
	entry->left = NULL;
	entry->right = NULL;

	return entry;
}

void lihatGraph(){
	temp = top;
	if (vertexIsEmpty()){
		"Tidak ada graph";
	} else {
		while(temp != NULL){
			cout << "Vertex " << temp->info << " : ";
			edge = temp->right;
			while (edge != NULL){
				point = edge->left;
				cout << edge->info << " ke " << point->info << ", ";
				edge = edge->right;
			}
			cout << endl;
			temp = temp->left;
		}
	}

}
