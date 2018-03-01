template<typename T>inline T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}

// PList is the prime List
// prime is the sieve

int PI_f(int m)
{
    if(prime[m]==0)
    {
        return m-1;
    }
    ll res=1;

    for(int i=0;i<Vsize && pList[i]*pList[i]<=m;i++)
    {
        if(m<=1)
            break;
        if(m%pList[i]==0)
        {
            int cnt=0;
            while(m%pList[i]==0)
            {
                m/=pList[i];
                cnt++;
            }
            res = res*(pList[i]-1)*round(pow(pList[i],cnt-1)); // PI(n) = (p1^(a1-1))*(p1-1)*(p2^(a2-1))*(p2-1)*...
        }
        if(prime[m]==0 && m>1)
        {
            res = res*(m-1);
            break;
        }
    }

    return res;
}
