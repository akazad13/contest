// Can be used a graph where each of the node weights 0 or x
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 1010// node limit
#define Clear(a,b) memset(a,b,sizeof a)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ll long long int

int n,m;
ll cost[Max][Max];
char g[Max][Max];

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

#define valid(i,j) i>=0 && i<n && j>=0 && j<m

ll zero_one_bfs()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cost[i][j]=1000000000000000;
        }
    }
    deque< pair< int,int> > deq;
    pair<int,int> p;

    p = make_pair(0,0);
    cost[0][0]=0;  // start at (0,0).... i can change that
    deq.push_front(p);

    while(!deq.empty())
    {
        p = deq.front(); deq.pop_front();

        int x = p.first;
        int y = p.second;

        if(x==n-1 && y==m-1)  // destination at (n-1,m-1).. can change that
            return cost[x][y];
        for(int i=0;i<4;i++)
        {
            int xx = x+fx[i];
            int yy = y+fy[i];

            if(valid(xx,yy))
            {
                if(g[x][y]==g[xx][yy]) // if same than 0 cost here .. 0 cost first
                {
                    if(cost[x][y]<cost[xx][yy])
                    {
                        cost[xx][yy]=cost[x][y]+0;
                        p = make_pair(xx,yy);
                        deq.push_front(p);
                    }
                }
                else
                {
                    if(cost[x][y]+1<cost[xx][yy])  // not same , k cost added
                    {
                        cost[xx][yy]=cost[x][y]+1;
                        p = make_pair(xx,yy);
                        deq.push_back(p);
                    }

                }
            }
        }
    }
    return -1;
}

int main()
{
    int test;
    char ch;
    si(test);

    for(int Case=1; Case<=test; Case++)
    {
        si(n); si(m);
        ch = getchar();
        for(int i=0;i<n;i++)
        {
           scanf("%s",&g[i]);
        }


        zero_one_bfs();
        printf("Case %d: %lld\n",Case,cost[n-1][m-1]);
    }
    return 0;
}
