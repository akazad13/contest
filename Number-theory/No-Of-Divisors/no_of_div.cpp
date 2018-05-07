            /************************************************/
            /************************************************/
            /**                                            **/
            /**                 *           *    *         **/
            /**                * *          *   *          **/
            /**               *   *         *  *           **/
            /**              *     *        * *            **/
            /**             *********       * *            **/
            /**            *         *      *  *           **/
            /**           *           *     *   *          **/
            /**          *             *    *    *         **/
            /**                                            **/
            /**             Md. Abul Kalam Azad            **/
            /**           CSE - 13 series , RUET,BD        **/
            /**        Email : akazad.cse13@gmail.com      **/
            /**                cell-01686871012            **/
            /**           Cool Ur head & Think :-)         **/
            /**        codeforce & uva id: akazad133032    **/
            /**         fb id: facebook.com/akazad.cse13   **/
            /**                                            **/
            /**                                            **/
            /**                                            **/
            /************************************************/
            /************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int

#define MAX 10000110
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

lld No_of_div(lld n)
{
    if(n<MAX && prime[n]==0)
    {
        //cout<<n-1;
        return 2;
    }
    lld count;
    lld res=1;
    for(int i=0;i<=Vsize && n>1 && primeList[i]*primeList[i]<=n;i++)
    {
        if(n<MAX)
        {
            if(prime[n]==0)
            {
                return res*2;
            }
        }
        count=0;
        while(n%primeList[i]==0 && n!=1)
        {
            n/=primeList[i];
            count++;
        }
        res*=(count+1);

        if(n<=1)
            break;
    }
    if(n!=1)
        return res*2;
    return res;

}



int main()
{
    sieve();

    lld a;
    int test;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%lld",&a);

       cout<<No_of_div(a)<<endl;

    }
    return 0;

}


