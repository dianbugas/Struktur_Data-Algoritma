#include <iostream>
using namespace std;

long faktorial (int f){
    if(f==0)
        return 1;
    else
        return f * faktorial(f-1);
}

int main()
{
    int x;
    cout<<"input faktorial";
    cin>>x;
    cout<<"faktorial dari"<<x<<"adalah"<<faktorial(x)<<endl;
    return 0;
}
