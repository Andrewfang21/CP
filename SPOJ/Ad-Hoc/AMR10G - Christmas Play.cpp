#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long TC,N,K,i,ans,temp;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>K;
		long long arr[N+5];
		for (i=0;i<N;i++)
			cin>>arr[i];
		
		if (K==0)
			cout<<"0\n";
		else
		{
			sort(arr,arr+N);
			ans=LLONG_MAX;
			
			for (i=K-1;i<N;i++)
			{
				temp=arr[i]-arr[i-K+1];
				ans=min(ans,temp);
			}
			cout<<ans<<"\n";
		}
	}
return 0;
}
