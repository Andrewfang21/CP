#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
	long long TC,N,i,ans;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		int arr[N+5];
		for (i=0;i<N;i++)
			cin>>arr[i];
		sort(arr,arr+N);
		ans=1;
		
		for (i=0;i<N;i++)
			ans=((ans%mod)*((arr[i]-i)%mod))%mod;
		cout<<ans<<"\n";
	}
	cout<<"KILL BATMAN";
return 0;
}
