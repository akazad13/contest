// a number is divisible by k ( sum %k ==0 )

int k;
 
lld dp[10][100][100][2];
 
lld solve(char str[],int n, int sum, int rem, int var)
{
   // cout<<rem<<" "<<n<<endl;
    if(n>=strlen(str))
    {
        if(rem==0 && sum==0)
            return 1;
        else
            return 0;
    }
    lld &ret = dp[n][sum][rem][var];
 
    if(ret!=-1) return ret;
 
    ret=0;
 
    int en;
 
    if(var==0)
        en=9;
    else
        en=str[n]-'0';
 
    int j=0;
 
    for(j=0;j<en;j++)
    {
        ret += solve(str,n+1,(sum+j)%k,(10*rem+j)%k,0);
    }
    ret += solve(str,n+1,(sum+j)%k,(10*rem+j)%k,var);
    return ret;
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
 
    int test,i,j,Case;
    char low[15];
    char high[15];
    scanf("%d",&test);
    rep(Case,1,test+1)
    {
        scanf(" %s %s %d",low,high,&k);
        if(k>100)
        {
            printf("Case %d: 0\n",Case);
            continue ;
        }
        Clear(dp,-1);
 
        int ret1 = solve(low,0,0,0,1);
        Clear(dp,-1);
        int ret2 = solve(high,0,0,0,1);
 
        int res = ret2-ret1;
       // cout<<ret2<<" "<<ret1<<endl;
 
        int rem=0;
        int sum=0;
        for(int i=0;i<strlen(low);i++)
        {
            rem = (10*rem+low[i]-'0')%k;
            sum = (sum+low[i]-'0')%k;
        }
        if(rem==0 && sum==0)
            res++;
 
        printf("Case %d: %d\n",Case,res);
    }
 
    return 0;
}
