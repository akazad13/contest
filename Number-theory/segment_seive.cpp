#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
//Macros
 
#define READ(a) scanf("%d",&a)
#define write(a) printf("%d\n",a)
#define Cwrite(i,a) printf("Case %d: %d\n",i,a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>
#define MA(a,b) map<a,b>
 
#define lld long long
#define PI acos(-1.0)
 
 
//End Macros
 
/*Basic Function
 
bool cheak_palindrome(char *str)
{
    int len = strlen(str);
 
    for(int i=0;i<=len/2;i++)
    {
        if(str[i]!=str[len-i-1])
            return 0;
    }
    return 1;
}
 
*/
 
#define MAX 1000010
bool prime[MAX+10];
//vector<int>primeList;
//int Vsize;
 
void seive()
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
 
  /*  for(int i=2;i<=MAX;i++)
    {
        if(prime[i]==0)
        {
            primeList.push_back(i);
        }
    }
 
    Vsize = primeList.size();
 
    //cout<<"seive OK"<<endl;
    */
}
/*
 
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
 
bool cheak_prime(lld n)
{
    if(n<=MAX)
    {
        if(prime[n]==0)
            return 1;
        return 0;
    }
 
 
    for(int i=0;primeList[i]*primeList[i]<=n && i<=Vsize;i++)
    {
        if(n%primeList[i]==0)
            return 0;
    }
    return 1;
}
 
 
vec<int> prime_div;
void Prime_DIV(lld n)
{
    for(int i=0;primeList[i]*primeList[i]<=n && i<=Vsize;i++)
    {
        if(n%primeList[i]==0)
        {
            while(n%primeList[i]==0)
            {
                n/=primeList[i];
            }
            prime_div.push_back(primeList[i]);
        }
    }
 
    if(n>1 && prime_div.size()>0)
    {
        prime_div.push_back(n);
    }
}
*/
 
bool seg_seive[100010];
 
lld first(lld lo,lld i)
{
    if(lo%i==0)
            return (lld)max(lo,i*i);
    else
        return (lld)max(lo + (i-lo%i),i*i);
}
 
 
void segment_seive(lld a, lld b)
{
    CLEAR(seg_seive,0);
        if(a==1)
        {
            seg_seive[a]=1;
        }
 
        for(lld k=first(a,2);k>=a&&k<=b;k=k+2)
            seg_seive[k-a+1]=1;
 
        int max1 = sqrt(b);
        for(int j=3;j<=max1;j+=2)
        {
            if(prime[j]==0)
            {
                for(lld k=first(a,j);k>=a&&k<=b;k=k+j)
                    seg_seive[k-a+1]=1;
            }
 
        }
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
    seive();
 
    int test;
    long long int low,up,count;
 
    READ(test);
 
    for(int i=1;i<=test;i++)
    {
        scanf("%lld %lld",&low,&up);
        segment_seive(low,up);
 
        count=0;
 
        for(int j=low;j<=up;j++)
        {
            if(seg_seive[j-low+1]==0)
            {
 
            //cout<<j<<endl;
                count++;
            }
        }
 
        printf("Case %d: %lld\n",i,count);
 
    }
 
    return 0;
 
}
