#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 1000
#define rep(i,p,n) for( i = p; i<n;i++)

bool board[Max][Max];
int res[Max];

void printsol(int n)
{
    int i,j;
    rep(j,0,n)
    {
        rep(i,0,n)
        {
            if(board[i][j])
                cout<<"Q";
            else
                cout<<".";
        }
        cout<<endl;
    }
}

bool safe(int col, int row,int n)
{
    int i,j;
    rep(i,0,col)
    {
        if(board[row][i])
            return false;
    }

    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }
    for(int i=row,j=col;i<n&&j>=0;i++,j--)
    {
        if(board[i][j])
            return false;
    }

    return true;
}

bool solve(int col, int n)
{

    if(col>=n)
        return true;
    int i;
    rep(i,0,n)
    {
        if(safe(col,i,n))
        {
            board[i][col]=true;
            res[col]=i;
            if(solve(col+1,n))
                return true;
            board[i][col]=false;
            res[col]=0;
        }
    }
    return false;
}

int main()
{
    memset(board,false,sizeof(board));
    memset(res,0,sizeof(res));
    int n,i;
    cout<<"number of queen: ";
    cin>>n;

    bool ret = solve(0,n);

    if(ret==false)
        cout<<"Not possible"<<endl;
    else
    {
        rep(i,0,n)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;

        printsol(n);
    }

    return 0;
}
