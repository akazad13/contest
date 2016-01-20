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

#define lld long long int

bool isDiv(string num, lld div)
{
    int len = num.length();
    int rem=0;

    for(int i=0;i<len;i++)
    {
        rem =(10*rem+(num[i]-'0'))%div;
    }
    if(rem==0)
        return true;
    else
        return false;
}

int main()
{

    string num;
    lld div;

    getline(cin,num);
    cin>>div;

    bool res  = isDiv(num,div);

    if(res)
        cout<<num<<" is divided by "<<div<<endl;
    else
        cout<<num<<" is not divided by "<<div<<endl;




    return 0;
}
