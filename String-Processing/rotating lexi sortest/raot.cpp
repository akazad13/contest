#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX 50010

using namespace std;


char arr[MAX];

int BoothAlgo(){
    int len = strlen(arr);
    char lst[MAX];
    strncpy(lst, arr, len);
    strncpy(lst+len, arr, len);
	int ans, i, j;
	ans = 0;
	int f[2*len];
	for( i = 0; i < 2*len; ++i)
		f[i] = -1;
	for ( j = 1; j < 2*len; ++j) {
		i = f[j-ans-1];
		while( i != -1 && lst[j] != lst[ans+i+1]){
			if( lst[j] < lst[ans+i+1] )
				ans = j-i-1;
			i = f[i];
		}
		if( i == -1 && lst[j] != lst[ans+i+1] ){
			if( lst[j] < lst[ans+i+1] )
				ans = j;
			f[j-ans] = -1;
		}
		else
			f[j-ans] = i+1;
	}
    return ans;
}

int main(){
    int c;
    scanf("%d", &c);
    for(int ii=1;ii<=c;ii++)
    {
        scanf("%s",arr);
        int n = strlen(arr);
        int p = BoothAlgo();

        int cnt=0;

        printf("Case %d: ",ii);

        for(int i=p; ;i = (i+1)%n)
        {
            if(cnt==n)
                break;
            cnt++;

            printf("%c",arr[i]);
        }
        printf("\n");
    }
    return 0;
}
