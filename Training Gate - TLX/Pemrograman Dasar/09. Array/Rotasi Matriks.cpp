#include<bits/stdc++.h>
using namespace std;
int M,N,i,j,arr[101][101];

int main()
{
	cin>>N>>M;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			cin>>arr[i][j];

	for(j=1;j<=M;j++)
	{
		for(i=N;i>=1;i--)	
		{
			if(i==1) cout<<arr[i][j]<<"\n"; else cout<<arr[i][j]<<" ";
		}
	}
return 0;
}
