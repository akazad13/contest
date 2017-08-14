#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
string str[100010];
int len;

struct node
{
    bool endmark;
    node *next[26];
    ll cnt;

    node()
    {
        for(int i=0;i<26;i++)
            next[i]=NULL;
        endmark=false;
        cnt=0;
    }

    ~node()
    {
        for(int i=0;i<26;i++)
        {
            if(next[i]!=NULL)
                delete(next[i]);
        }
    }
};

void insert_trie(int i, node *curr)
{
    for(int j=0;j<len;j++)
    {
        int id=str[i][j]-'a';

        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }

    curr->endmark=true;
    curr->cnt++;

}

ll cnt=0;

void search_trie(int i, int j, node *curr, bool flag)
{

    if(j<len)
    {
        int id=str[i][j]-'a';

        for(int k = 0 ; k<26 ;k++)
        {
            if(k==id)
            {
                if(curr->next[k]!=NULL)
                    search_trie(i, (j+1), curr->next[k], flag);
            }
            else if(flag)
            {
                if(curr->next[k]!=NULL)
                    search_trie(i, (j+1), curr->next[k], 0);
            }
        }
    }

   if(curr->endmark && flag==0)
    {
        cnt+=curr->cnt;
        return ;
    }
   return ;
}


int main()
{
   // freopen("out.txt","w",stdout);


    int n, m;

    scanf("%d %d",&n,&m);

    len = m;
    char ch = getchar();


    for(int i= 0;i<n; i++)
    {
       cin>>str[i];
    }

    node *root=new node();

    for(int i=0;i<n;i++)
    {
        insert_trie(i, root);
        search_trie(i,0, root, 1);
    }

    delete root;

    printf("%lld\n",cnt);
}

