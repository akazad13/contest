#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
char str[10010];
int len;

int Next[100010][52];
ll End[100010];
int sz;
bool created[100010]={0};

ll res;

int idx(char c)
{
	if(c >= 'a' && c <= 'z')
		return c - 'a'+26;
	else
		return c - 'A';
}

void insert_trie()
{
	int u = 0;
	for(int i = 0; i < len; i++)
	{
		int c = idx(str[i]);
		if(!created[Next[u][c]])
		{
			Next[u][c] = sz++;
			created[Next[u][c]] = 1;
		}
		u = Next[u][c];
	}
	End[u]++;
}
void search_trie(int l)
{
	int u = 0;
	for(int i = 0; i < l; i++)
	{
		int c = idx(str[i]);


		if(!created[Next[u][c]])
        {
            res = 0;
            return ;
        }

        u = Next[u][c];
	}

	res*=End[u];

	return ;
}

int main()
{
 //  freopen("in.txt","r",stdin);

    int kk=0;
    char str1[10010];
    int test, Case, n,m;

    char ch;

    scanf("%d",&test);

    for(Case = 1; Case<=test; Case++)
    {
        memset(Next,0,sizeof(Next));
        memset(created,0,sizeof(created));
        memset(End,0,sizeof(End));
        sz=1;

        scanf("%d",&n);
        ch = getchar();

        for(int i= 0;i<n; i++)
        {
           scanf("%s",&str);

           len = strlen(str);

           insert_trie();
        }

        scanf("%d",&m);

        ch = getchar();

        printf("Case %d:\n",Case);

        printf("%lld\n",res);


    }

    return 0;
}
