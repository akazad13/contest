#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

#define Clear(a,b) memset(a,b,sizeof(a))
//istringstream is()

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

inline int Set(int N, int pos)
{
    return N= N|(1<<pos);
}

inline int Reset(int N, int pos)
{
    return N= N & ~(1<<pos);
}

inline bool check(int N, int pos)
{
    return (bool) (N&(1<<pos));
}
/*****************************************/

ll dis[20][20];
ll Mp[20][20];
ll dp[16][1<<16];
int n,m;
int cnt;
char str[21][21];

void solve(int mask)
{
    for(int i=1;i<=cnt;i++)
    {
        int k = i-1;

        if(check(mask,k)==0)
        {
            for(int j=1;j<=cnt;j++)
            {
                int l = j-1;

                if(check(mask,l))
                {
                    dp[i][mask] = min(dp[i][mask], dp[j][Reset(mask,l)]+dis[j][i]);
                }
            }
        }
    }
}

bool vis[21][21];
queue< pair<int,int> > Q;

pair<int,int> pi;

int fx[]={-1,-1,-1,0,0,0,1,1,1};
int fy[]={-1,0,1,-1,0,1,-1,0,1};

int d[21][21];

void bfs(int x, int y)
{
    vis[x][y] = 1;
    Clear(vis,0);
    Clear(d,63);

    d[x][y]=0;

    Q.push(make_pair(x,y));

    while(!Q.empty())
    {
        pi = Q.front(); Q.pop();

        for(int i=0;i<8;i++)
        {
            int xx = pi.first+fx[i];
            int yy = pi.second+fy[i];

            if(xx>=0 && xx<n && yy>=0 && yy<m && !vis[xx][yy])
            {
                vis[xx][yy] = 1;
                Q.push(make_pair(xx,yy));
                d[xx][yy] = d[pi.first][pi.second]+1;

                if(str[xx][yy]!='.')
                {
                    dis[Mp[x][y]][Mp[xx][yy]] =  d[xx][yy];
                    dis[Mp[xx][yy]][Mp[x][y]] =   d[xx][yy];
                }
            }
        }
    }

    return ;
}

int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,Case;
    read(test);
    rep(Case,1,test+1)
    {
        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++)
        {
            scanf(" %s",&str[i]);
        }

        int p,q;

        cnt=1;

        Clear(Mp,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='x')
                {
                    p = i;
                    q = j;
                    Mp[p][q]=0;
                    //break ;
                }
                else if(str[i][j]=='g')
                {
                    Mp[i][j]=cnt++;
                }
            }
        }

        cnt--;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[i][j]!='.')
                {
                    bfs(i,j);
                }
            }
        }

        for(int i=0;i<=cnt;i++)
        {
            for(int j=0;j< (1<<cnt);j++)
            {
                dp[i][j]=INT_MAX;
            }

            if(i>0)
                dp[i][0]=dis[0][i];
        }



        if(cnt==0)
        {
            printf("Case %d: 0\n",Case);
            continue ;
        }

        int mask = (1<<cnt) -1;

        for(int i=1;i<=mask ;i++)
            solve(i);


        ll ret=INT_MAX;

        for(int i=1;i<=cnt;i++)
        {
            ret = min(ret,dp[i][Reset(mask,i-1)]+dis[0][i]);
        }

        printf("Case %d: %lld\n",Case,ret);
    }

    return 0;
}

