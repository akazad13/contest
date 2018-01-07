#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 1000// node limit
#define Clear(a,b) memset(a,b,sizeof a)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ll long long int

int fx[]={+1,-1,+0,-0}; // x direction
int fy[]={+0,-0,+1,-1}; // y direction

char grid[Max][Max];
int row,col,n,sX,sY,dX,dY;
bool vis[Max][Max]; // visited info
int level[Max][Max];

// for  x = 0 to n-1 and y = 0 to m-1
#define valid(x,y) x>=0 && x<row && y>=0 && y<col
struct point
{
    int x;
    int y;
    point(int a,int b)
    {
        x=a;y=b;
    }
};

int bfs_gird()
{
    queue<point> Q;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            vis[i][j]=0;
        }
    }
    level[sX][sY] = 0;
    Q.push(point(sX,sY));

    while(!Q.empty())
    {
        point p = Q.front(); Q.pop();

        if(p.x==dX && p.y==dY)
            return level[dX][dY];
        for(int i=0;i<4;i++)
        {
            int xx = p.x+fx[i];
            int yy = p.y+fy[i];

            if(valid(xx,yy) && vis[xx][yy]==0 && grid[xx][yy]!='#')
            {
                vis[xx][yy]=1;
                Q.push(point(xx,yy));
            }
        }
    }

    return -1;

}

int main()
{
    int test, n,m,u,v;
    si(test);

    for(int Case=1;Case<=test;Case++)
    {
        si(n); si(m);
        for(int i=0;i<n;i++)
        {
           gets(grid[i]);
        }

        si(sX); si(sY); si(dX); si(dY);

        int ret = bfs_gird();
        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}
