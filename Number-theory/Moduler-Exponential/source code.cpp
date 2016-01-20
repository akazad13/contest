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

using namespace std;
long long int temp;

long int solve(long int a,long int p,long int m)
{
    if(p==0)
        return 1;
    if(p%2==1)
        return ((a%m)*(solve(a,p-1,m))%m);
    else
         temp=solve(a,p/2,m)%m;
    return (temp*temp)%m;
}


int main()
{
    long int a,p,m;

    while(cin>>a>>p>>m)
    {
        cout<<solve(a,p,m)<<endl;
    }
    return 0;
}

