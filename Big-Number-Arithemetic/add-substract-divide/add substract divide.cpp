#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char line1[200];
char line2[200];
vector<int> After_deducting_xtra;
vector<int> first_one;
vector<int> second_one;
vector<int> num1;
vector<int> num2;

void print( vector<int> v);

void subtract(int len1, int len2)
{
    int carry=0,temp=0;
    for(int i=0;i<len2;i++)
    {
        temp = carry+num1[i]-num2[i];
        if(temp<0)
        {
            carry=-1;
            temp = 10+temp;
        }
        else
        {
            carry=0;
        }
        After_deducting_xtra.push_back(temp);
    }
    for(int i=len2;i<len1;i++)
    {
        if(carry<0)
        {
            if(num1[i]>0)
            {
                After_deducting_xtra.push_back(num1[i]+carry);
                carry=0;
            }
            else
            {
                After_deducting_xtra.push_back(10+carry);
               carry=-1;
            }

        }
        else
            After_deducting_xtra.push_back(num1[i]);
    }

    int len = After_deducting_xtra.size();

    int n = After_deducting_xtra[len-1];
    //cout<<n<<endl;
    while(n==0)
    {
        len--;
        After_deducting_xtra.pop_back();
        n = After_deducting_xtra[len-1];
    }
}

void divide()
{
    int len = After_deducting_xtra.size();


    int temp=0,a;

    for(int i=len-1;i>=0;i--)
    {
        temp=temp*10+After_deducting_xtra[i];
        a= temp/2;
        temp%=2;
        second_one.push_back(a);
    }
    if(temp!=0 && temp%2==0)
    {
        second_one.push_back(temp/2);
    }
    return ;
}

void add(int len2)
{
    reverse(second_one.begin(),second_one.end());
    int len1 = second_one.size();
    int len  = min(len1,len2);
    int carry=0;

    for(int i=0;i<len;i++)
    {
        carry += second_one[i]+num2[i];
        first_one.push_back(carry%10);
        carry/=10;
    }
    //print(first_one);
    if(len==len1)
    {
        for(int i=len;i<len2;i++)
        {
            carry+=num2[i];
            first_one.push_back(carry%10);
            carry/=10;
        }
    }
    else
    {
        for(int i=len;i<len1;i++)
        {
            carry+=second_one[i];
            first_one.push_back(carry%10);
            carry/=10;
        }
    }

    if(carry)
        first_one.push_back(carry);
    return ;

}

void print( vector<int> v)
{
    //reverse(fact[ind].begin(),fact[ind].end());

    int len = v.size();
    bool flag=0;
    for(int i=len-1;i>=0;i--)
    {
        if(v[i]!=0)
            flag=1;
        if(flag)
            printf("%d",v[i]);
    }
    printf("\n");
}


int main()
{
    while(gets(line1))
    {
        gets(line2);
        After_deducting_xtra.clear();
        first_one.clear();
        second_one.clear();
        num1.clear();
        num2.clear();

        int len1 = strlen(line1);
        int len2 = strlen(line2);

        for(int i=len1-1;i>=0;i--)
        {
            num1.push_back(line1[i]-'0');
        }

        for(int i=len2-1;i>=0;i--)
        {
            num2.push_back(line2[i]-'0');
        }

        subtract(len1,len2);
       // print(After_deducting_xtra);
       // print(num2);
        divide();
        add(len2);
        print(first_one);
        print(second_one);

    }

    return 0;
}
