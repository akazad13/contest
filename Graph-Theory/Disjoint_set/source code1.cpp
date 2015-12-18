#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Disjoint_Set{
    map<char, char> parent;
    map<char,int> Rank;
    map<char, int> setSize;
    int numOfset=0;

public:
    void make_set(char item)
    {
        numOfset++;
        parent[item]=item;
        Rank[item]=0;
        setSize[item]=1;
    }
    void Union(char i, char j)
    {
        if(Find(i)!=Find(j))
        {
            numOfset--;
            char item1 = Find(i);
            char item2 = Find(j);

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
    char Find(char item)
    {
        if(parent[item]==item)
            return item;
        //cout<<parent[item]<<endl;
        parent[item]=Find(parent[item]);

        return parent[item];
    }
    int sizeOfset(char item)
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
    myset.make_set('a');
    myset.make_set('b');
    myset.make_set('c');
    myset.make_set('d');
    myset.make_set('e');
    myset.make_set('f');
    myset.make_set('g');
    myset.make_set('h');
    myset.make_set('i');
    myset.make_set('j');
    cout<< myset.Find('c')<<endl; //c
    cout<<myset.numOfDisjoint_set()<<endl; //10
    cout<<myset.sizeOfset('a')<<endl; //1
    myset.Union('a','b');
    myset.Union('e','f');
    myset.Union('c','d');
    //cout<< myset.Find('d')<<endl;
    myset.Union('g','h');
    myset.Union('i','j');

    cout<<myset.numOfDisjoint_set()<<endl; //5
    cout<<myset.sizeOfset('g')<<endl; //2
    cout<< myset.Find('e')<<endl; //f
    cout<< myset.Find('i')<<endl; //j

    myset.Union('i','g');
    myset.Union('c','e');

    cout<<myset.numOfDisjoint_set()<<endl;//3
    cout<<myset.sizeOfset('i')<<endl; //4
    cout<< myset.Find('c')<<endl; //f

    myset.Union('i','a');
    myset.Union('a','c');

    cout<<myset.numOfDisjoint_set()<<endl; //1
    cout<<myset.sizeOfset('e')<<endl; //10
    cout<< myset.Find('a')<<endl;  //f


    return 0;
}
