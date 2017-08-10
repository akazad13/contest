#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define ll long long int
char text[1000010];
char Longtext[2000010];
ll Z[2000010];
ll len;

void getZarr()
{

    int L, R, k;
    Z[0]=0;

    L = R = 0;
    for (int i = 1; i < len; ++i)
    {
        if (i > R)
        {
            L = R = i;

            // R-L = 0 in starting, so it will start
            // checking from 0'th index. For example,
            // for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string
            // "aaaaaa" and i = 1, Z[i] and R become 5
            while (R<len && Longtext[R-L] == Longtext[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;

            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R-i+1)
                 Z[i] = Z[k];

            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else
            {
                //  else start from R  and check manually
                L = i;
                while (R<len && Longtext[R-L] == Longtext[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}


ll patternSearch(ll len2)
{
    getZarr();

    ll cnt=0;

    //cout<<Longtext<<endl;
    for (int i = 0; i < len; ++i)
    {
        // if Z[i] (matched region) is equal to pattern
        // length  we got the pattern

      //  cout<<Z[i]<<" ";
        if (Z[i] == len2)
            cnt++;
    }

    //cout<<endl;

    return cnt;
}


int main()
{
    int test,cnt,len1,len2;

    scanf("%d", &test);
    char ch= getchar();

    for(int Case = 1; Case <=test; Case++)
    {
        gets(text);
        gets(Longtext);

        len1 = strlen(Longtext);
        len2 = strlen(text);

        Longtext[len1]='$';

        for(int i=0;i<len2;i++)
        {
            Longtext[i+len1+1] = text[i];
        }

        len = len1+len2+1;


        printf("Case %d: %d\n", Case,patternSearch(len1));
    }
    return 0;
}
