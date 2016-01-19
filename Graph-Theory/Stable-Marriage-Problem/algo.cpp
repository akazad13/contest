#include<bits/stdc++.h>
using namespace std;

int prefer[250][105];
int status[210];

void solve(int n)
{

	memset(status,-1,sizeof(status));
	queue<int> Q;

	for(int i=1;i<=n;i++)
        Q.push(i); /* Push all single men */

 /* While there is a single men */
	while(!Q.empty())
    {
		int i = Q.front();
		Q.pop();
		/* iterate through his preference list */
		for(int j=1;j<=n;j++)
        {
			/* if girl is single marry her to this man*/
			if(status[prefer[i][j]] == -1)
			{
				status[i] = prefer[i][j];/* set this girl as wife of i */
				status[prefer[i][j]] = i; /*make i as husband of this girl*/
				break;		/*break the loop*/
            }
			else
			{
				int rank1, rank2;/* for holding priority of current husband and most preferable husband*/
				for(int k=1;k<=n;k++)
				{
					if(prefer[prefer[i][j]][k] == status[prefer[i][j]]) rank1 = k;
					if(prefer[prefer[i][j]][k] == i) rank2 = k;
				}
				/* if current husband is less attractive :D
				than divorce him and marry a new one making the old one
				single */
				if(rank2 < rank1)
				{	/* if this girl j prefers current man i
										more than her present husband */
					status[i] = prefer[i][j]; /* her wife of i */
					int old = status[prefer[i][j]];
					status[old] = -1;	/*divorce current husband*/
					Q.push(old);/*add him to list of singles */
					status[prefer[i][j]] = i;/* set new husband for this girl*/
					break;
				}
			}
		}
	}

    for(int i=1;i<=n;i++)
	{
		printf(" (%d %d)",i,status[i]);
	}
	printf("\n");
}

int main()
{
    int test,n;

    scanf("%d",&test);

    for(int Case = 1; Case<=test; Case++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%d",&prefer[i][j]);
        }
        for(int i=n+1;i<=2*n;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%d",&prefer[i][j]);
        }
        printf("Case %d:",Case);
        solve(n);
    }



    return 0;
}
