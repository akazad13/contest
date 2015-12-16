                        /* Md. Abul Kalam Azad */
                         /* CSE-13  , @RUET */
                         /* cell-01686871012*/
                       /* Cool Ur head & Think */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define lld long long int
#define ulld unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

//End Macros

bool cheak_palindrome(char *str)
{
    int len = strlen(str);

    for(int i=0;i<=len/2;i++)
    {
        if(str[i]!=str[len-i-1])
            return 0;
    }
    return 1;
}

/* My note:-
    1. Can i solve the sub-problem of that problem
    2. Can i solve the whole problem
    3. Do i check the parameter
    4. Did i clear all the memory
    5. check whether DP is cleared
    6. Understand the prob?! check again!!!

End of my note */



int main()
{
    char str[1000];

    cin>>str;

    if(cheak_palindrome(str))
        cout<<"palindrome"<<endl;
    else
        cout<<"not"<<endl;

    return 0;

}


