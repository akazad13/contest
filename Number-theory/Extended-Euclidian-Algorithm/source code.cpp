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
#define ll long long int

ll x, y, d;
ll extendedEulid(ll a, ll b)
{
    if(b==0)
    {
        x=1; y=0; d=a; // some extensions
        return a;
    }
    ll ret = extendedEulid(b, a%b);     // GCD function
    ll x1 = y;
    ll y1 = x - (a/b) *y;
    x = x1;
    y = y1;
    return ret;
}

int main()
{
    ll a, b;
    while(cin>>a>>b)
    {
        extendedEulid(a, b);
        printf("x = %lld, y = %lld, gcd()=%lld\n", x, y, d);
    }
    return 0;
}

