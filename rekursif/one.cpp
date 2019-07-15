#include <iostream>
using namespace std;

long rekursiffaktorial(int f,int n)
{
    if (f == 0)
        return 1;
    else
        return n * rekursiffaktorial(f - 1,n);
}

int main()
{
    int n = 4;
    int f =2;
    cout <<"nilai "<< n << " pangkat "<<f<<" = "<< rekursiffaktorial(n,f) << endl;
}
