

// Can be used a graph where each of the node weights 0 or x

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n,m;
int cost[1010][1010];
char g[1010][1010];

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

#define valid(i,j) i>=0 && i<n && j>=0 && j<m

void bfs()
{
    deque< pair< int,int> > deq;

    pair<int,int> p;

    p = make_pair(0,0);
    cost[0][0]=0;
    deq.push_front(p);

    while(!deq.empty())
    {
        p = deq.front(); deq.pop_front();

        int x = p.first;
        int y = p.second;

        if(x==n-1 && y==m-1)
            return ;
        for(int i=0;i<4;i++)
        {
            int xx = x+fx[i];
            int yy = y+fy[i];

            if(valid(xx,yy))
            {
                if(g[x][y]==g[xx][yy])
                {
                    if(cost[x][y]<cost[xx][yy])
                    {
                        cost[xx][yy]=cost[x][y];
                        p = make_pair(xx,yy);
                        deq.push_front(p);
                    }
                }
                else
                {
                    if(cost[x][y]+1<cost[xx][yy])
                    {
                        cost[xx][yy]=cost[x][y]+1;
                        p = make_pair(xx,yy);
                        deq.push_back(p);
                    }

                }
            }
        }
    }
}

int main()
{
    //freopen("inn.txt","r",stdin);
    int test;
    char ch;
    cin>>test;

    for(int Case=1; Case<=test; Case++)
    {
        scanf("%d %d",&n,&m);
        ch = getchar();
        for(int i=0;i<n;i++)
        {
           // cin>>g[i];
           scanf("%s",&g[i]);
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cost[i][j]=INFINITY;
            }
        }
      //  cout<<cost[n-1][m-1]<<endl;
        bfs();
        printf("%d\n",cost[n-1][m-1]);
    }


    return 0;
}
