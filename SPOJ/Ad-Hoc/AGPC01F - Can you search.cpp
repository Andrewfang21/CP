#include<bits/stdc++.h>
using namespace std;

int main()
{
	int TC,mins,N,Q,i,num;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>Q;
		mins=INT_MAX;
		int arr[N+5],batas[N+5];
		memset(batas,-1,sizeof(batas));
		
		for (i=1;i<=N;i++)
		{
			cin>>arr[i];
			batas[i]=min(mins,arr[i]);
			mins=min(mins,arr[i]);
		}
		
		for (i=1;i<=Q;i++)
		{
			cin>>num;
			cout<<batas[num]<<"\n";
		}
	}
return 0;
}
