                       /* Md. Abul Kalam Azad */
                         /* CSE-13  , @RUET */
                         /* cell-01686871012*/
                       /* Cool Ur head & Think */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define uud unsigned int

#define MAX 100000000
uud prime[(MAX/32)+10]={0};
uud primeList[5761456];
int Vsize;


bool Check(int n, int pos)
{
    return  n&(1<<pos);
}
int Set(int n, int pos)
{
    return n= n|(1<<pos);
}


void sieve()
{
    for(int i=4;i<=MAX;i+=2)
    {
        prime[i>>5]= Set(prime[i>>5],i&31);
    }
    int srt = sqrt(MAX);
    for(int i=3;i<=srt; i+=2)
    {
        if( Check(prime[i>>5],i&31)==0)
        {
            for(int j=i*i;j<=MAX;j+=(i<<1) )
            {
                prime[j>>5]=Set(prime[j>>5],j&31);
            }
        }
    }
    Vsize=0;
    for(int i=2;i<MAX;i++)
    {
        if( Check(prime[i>>5],i&31)==0)
        {
            primeList[Vsize++]=i;
        }
    }
    cout<<Vsize<<endl;
}

int main()
{
     sieve();
}
