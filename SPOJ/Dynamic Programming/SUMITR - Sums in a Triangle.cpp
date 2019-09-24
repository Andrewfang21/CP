#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int N,TC,i,j,maks;
	cin>>TC;
	
	while (TC--)
	{
		maks=-1;
		cin>>N;
		int arr[N+2][N+2];
		memset(arr,0,sizeof(arr));
		for (i=1;i<=N;i++)
			for (j=1;j<=i;j++)
			{
				cin>>arr[i][j];
				arr[i][j]+=max(arr[i-1][j],arr[i-1][j-1]);
				
				if (maks<arr[i][j])
					maks=arr[i][j];
			}
		cout<<maks<<"\n";
	}
}
