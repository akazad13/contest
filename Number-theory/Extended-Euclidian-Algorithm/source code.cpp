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

int x, y, d;
int extendedEulid(int a, int b)
{
    if(b==0)
    {
        x=1; y=0; d=a; // some extensions
        return a;
    }
    int ret = extendedEulid(b, a%b);     // GCD function
    int x1 = y;
    int y1 = x - (a/b) *y;
    x = x1;
    y = y1;
    return ret;
}

int main()
{
    int a, b;
    while(cin>>a>>b)
    {
        extendedEulid(a, b);
        printf("x = %d, y = %d, gcd()=%d\n", x, y, d);
    }
    return 0;
}

