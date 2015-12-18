#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Disjoint_Set{
    map<int, int> parent;
    map<int,int> Rank;
    map<int, int> setSize;
    int numOfset;

public:
    void make_set(int n)
    {
        numOfset=n;
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            Rank[i]=0;
            setSize[i]=1;
        }

    }
    void Union(int i, int j)
    {
        if(Find(i)!=Find(j))
        {
            numOfset--;
            int item1 = Find(i);
            int item2 = Find(j);

            if(Rank[item1]>Rank[item2])
            {
               parent[item2]=item1;
               setSize[item1]+=setSize[item2];
            }
            else
            {
                parent[item1]=item2;
                setSize[item2]+=setSize[item1];

                if(Rank[item1]==Rank[item2])
                    Rank[item2]++;
            }
        }
    }
    int Find(int item)
    {
        if(parent[item]==item)
            return item;
        //cout<<parent[item]<<endl;
        parent[item]=Find(parent[item]);

        return parent[item];
    }
    int sizeOfset(int item)
    {
        return setSize[Find(item)];
    }

    int numOfDisjoint_set()
    {
        return numOfset;
    }
};


int main()
{

    Disjoint_Set myset;
    
    myset.make_set(10);
    return 0;
}

