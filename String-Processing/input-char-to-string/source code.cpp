                        /* Md. Abul Kalam Azad */
                         /* CSE-13  , @RUET */
                         /* cell-01686871012*/
                       /* Cool Ur head & Think */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/* My note:-
    1. Can i solve the sub-problem of that problem
    2. Can i solve the whole problem
    3. Do i check the parameter
    4. Did i clear all the memory
    5. check whether DP is cleared
    6. Understand the prob?! check again!!!

End of my note */

string str;

void getInput()
{
    char ch;
    while(scanf("%c",&ch))
    {
        if(ch=='\n')
            break;
        str.push_back(ch);
    }
}

int main()
{

    getInput();
    cout<<str<<endl;
    str.clear();

    return 0;

}


