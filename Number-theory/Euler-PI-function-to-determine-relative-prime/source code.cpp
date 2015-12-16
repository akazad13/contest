                        /* Md. Abul Kalam Azad */
                         /* CSE-13  , @RUET */
                         /* cell-01686871012*/
                       /* Cool Ur head & Think */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>

#define lld long long int
#define ulld unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

//End Macros

#define MAX 10000010
bool prime[MAX+10];
vector<int>primeList;
int Vsize;

void sieve()
{
    for(int i=4;i<=MAX;i+=2)
        prime[i]=1;
    int srt = sqrt(MAX);
    for(int i=3;i<=srt;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=MAX;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[0]=prime[1]=1;

    for(int i=2;i<=MAX;i++)
    {
        if(prime[i]==0)
        {
            primeList.push_back(i);
        }
    }

    Vsize = primeList.size();

    //cout<<"seive OK"<<endl;
}

int PI_function(int n)
{
    if(prime[n]==0)
    {
        //cout<<n-1;
        return n-1;
    }
    int count;
    int res=1;
    for(int i=0;i<=Vsize;i++)
    {
        count=0;
        while(n%primeList[i]==0 && n!=1)
        {
            n/=primeList[i];
            count++;
        }
        if(count>=1)
            res*=((pow(primeList[i],count))-(pow(primeList[i],count-1)));

        if(n<=1)
            break;

        if(prime[n]==0)
        {
            res*=(n-1);
            break;
        }
    }
   // cout<<res;

    return res;

}


/* My note:-
    1. Can i solve the sub-problem of that problem
    2. Can i solve the whole problem
    3. Do i check the parameter
    4. Did i clear all the memory
    5. check whether DP is cleared
    6. Understand the prob?! check again!!!

End of my note */



int main()
{
    sieve();
    int res = PI_function(1000);
    cout<<res<<endl;
    return 0;

}

