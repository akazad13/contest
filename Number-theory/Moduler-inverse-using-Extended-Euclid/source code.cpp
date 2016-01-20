            /************************************************/
            /************************************************/
            /**                                            **/
            /**                 *           *    *         **/
            /**                * *          *   *          **/
            /**               *   *         *  *           **/
            /**              *     *        * *            **/
            /**             *********       * *            **/
            /**            *         *      *  *           **/
            /**           *           *     *   *          **/
            /**          *             *    *    *         **/
            /**                                            **/
            /**             Md. Abul Kalam Azad            **/
            /**           CSE - 13 series , RUET,BD        **/
            /**        Email : akazad.cse13@gmail.com      **/
            /**                cell-01686871012            **/
            /**           Cool Ur head & Think :-)         **/
            /**        codeforce & uva id: akazad133032    **/
            /**         fb id: facebook.com/akazad.cse13   **/
            /**                                            **/
            /**                                            **/
            /**                                            **/
            /************************************************/
            /************************************************/


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

#define lld long long int

lld x, y;
void extendedEulid(lld a, lld b)
{
    if(b==0)
    {
        x=a; y=0;
        return ;
    }

    extendedEulid(b,a%b);
    lld x1 = y;
    lld y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}

int main()
{
    int a,a_Inverse;
    int MOD = 1000003;
    while(cin>>a)
    {
        extendedEulid(a,MOD); //here a*x+b*MOD = 1

        a_Inverse = x; //x is the mod inverse
        if(x<0)  // if x is negative, to make it positive
            a_Inverse+=MOD;
        printf("%d\n",a_Inverse%MOD);
    }

    return 0;

}



