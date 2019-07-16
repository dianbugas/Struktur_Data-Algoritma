#include <iostream>
using namespace std;

//fungsi dari rekursif
long rekursiffaktorial(int f,int n)
{
    if (f == 0)
        return 1;
    else
        return n * rekursiffaktorial(f - 1,n);
}

int main()
{
    int n,f;
    cout<<"masukkan nilai : ";
    cin>>f;
    cout<<"masukan pangkat : ";
    cin>>n;
    cout <<"nilai "<< f << " pangkat "<<n<<" = "<< rekursiffaktorial(n,f) << endl;
}
