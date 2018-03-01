#define MAX 10000010
bool prime[MAX+10];
vector<int>primeList; //for saving prime number in a vector
int Vsize;


void seive()
{
    //generating prime table
    for(int i=4; i<=MAX; i+=2)
        prime[i]=1;
    int srt = sqrt(MAX);
    for(int i=3; i<=srt; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=MAX; j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[0]=prime[1]=1;


    //for saving the prime in one place
    for(int i=2; i<=MAX; i++)
    {
        if(prime[i]==0)
        {
            primeList.push_back(i);
        }
    }

    Vsize = primeList.size();

    // cout<<"seive OK"<<endl;
}


// PList is the prime List
// prime is the sieve

ll PI_f(int m)
{
    if(prime[m]==0)
    {
        return m-1;
    }
    ll res=1;

    for(int i=0; i<Vsize && primeList[i]*primeList[i]<=m; i++)
    {
        if(m<=1)
            break;
        if(m%primeList[i]==0)
        {
            ll cnt=0;
            while(m%primeList[i]==0)
            {
                m/=primeList[i];
                cnt++;
            }
             res = res - (res/cur);
        }
        if(prime[m]==0 && m>1)
        {
             res = res - (res/m);
            break;
        }
    }

    return res;
}
