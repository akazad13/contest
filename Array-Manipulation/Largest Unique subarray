#include<iostream>
#include<bits/stdc++.h>


long long int arr[1000010];

using namespace std;

int main()
{
    int n;
    int test;
    cin>>test;

    while(test--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
      //  cout<<"end of input"<<endl;
        map<int , int >myMap;

        int large=0;
        int count=0;

        int j=1;

        for(int i=1;i<=n;i++)
        {
            if(i==n&&myMap[arr[i]]==0)
            {
                count= (i+1)-j;
            }
            else if(myMap[arr[i]]==0)
            {
                myMap[arr[i]]++;
               //count++;
            }

            else
            {
                count = (i-j);

                for(int k=j;k<=n;k++)
                {
                    if(arr[k]==arr[i])
                    {
                       // cout<<"left : "<<k<<"Right: "<<i<<"\n"<<endl;
                        j=k+1;
                        //cout<<"left : "<<j<<"Right: "<<i<<endl;
                        break;
                    }
                    else
                    {
                        myMap[arr[k]]=0;
                    }
                }

            }
            if(i==j&&count==0)
                large=1;
            else if(count>large)
                large=count;

        }

        cout<<large<<endl;
    }

    return 0;
}
