#include<iostream>

using namespace std;
long int temp;

long int BigMod(long int a,long int p,long int m)
{
    if(p==0)
        return 1;
    if(p%2==1)
        return ((a%m)*(BigMod(a,p-1,m))%m);
    else
         temp=BigMod(a,p/2,m)%m;
    return (temp*temp)%m;
}


int main()
{
    long int a,p,m;

    while(cin>>a>>p>>m)
    {
        cout<<BigMod(a,p,m)<<endl;
    }
    return 0;
}

