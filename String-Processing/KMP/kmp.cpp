#include <iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

int pattern[1200100];
char text[1200100];
char sub[12000020];

void fun(int m)
{
    int i = 0, j = -1;

    pattern[i] = -1;
    while(i < m)
    {
        while(j >= 0 && sub[i] != sub[j])
            j = pattern[j];

        i++;
        j++;
        pattern[i] = j;
    }

    //for(int i=0;i<m;i++)
      //  cout<<pattern[i]<<" ";
}

int cal()
{
    int i=0, j=0, count = 0;
    int n = strlen(text);
    int m = strlen(sub);

    fun(m);
    while (i<n)
    {
        while (j>=0 && text[i]!=sub[j])
            j=pattern[j];

        i++;
        j++;

        if (j==m)
        {
            count++;
            j=pattern[j];
        }
    }
    return count;
}

int main()
{
    int test,cnt,len;

    scanf("%d", &test);
    char ch= getchar();

    for(int Case = 1; Case <=test; Case++)
    {
        gets(text);
        gets(sub);
        
        printf("Case %d: %d\n", Case,cal() );
    }

    return 0;
}
