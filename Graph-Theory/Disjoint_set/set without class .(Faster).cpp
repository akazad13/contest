#include<iostream>
#include<cstdio>



using namespace std;

#define rep(i,p,n) for(int i=p;i<n;i++)
#define read(a) scanf("%d",&a)
#define Max 100050

int par[Max];
int setSize[Max];
int numOfset;

void make_set(int n) // 0 to n-1
{
    numOfset=n;
    rep(i,0,n)
    {
        setSize[i]=1;
        par[i]=i;
    }
}

void Union(int a,int b) // a and b are the parent node of the given node
{
    par[b]=a;
    setSize[a]+=setSize[b];
    numOfset--;
}

int Find(int item)
{
    if(par[item]==item)
            return item;
        //cout<<parent[item]<<endl;
    par[item]=Find(par[item]);

    return par[item];
}

int sizeOfset(int item)
{
    return setSize[Find(item)];
}
int numOfDisjoint_set()
{
    return numOfset;
}
int main()
{
    int num,u,v;
    int m,n,p,a,b;
    scanf("%d",&num);
    make_set(Max);

    int total=0;

    for(int i=0;i<num;i++)
    {
        scanf("%d %d",&u,&v);
        a = Find(u);
        b = Find(v);

        if(a!=b)
        {
            m=sizeOfset(a);
            n=sizeOfset(b);
            Union(a,b);
            p=sizeOfset(a);
           // p = m+n;

          // cout<<m<<" "<<n<<" "<<p<<endl;
            total += ((p*(p-1))/2) - ((m*(m-1))/2)-((n*(n-1))/2);

        }



        //cout<<myset.Find(a)<<endl;

        printf("%d\n",total);

    }
    return 0;
}
