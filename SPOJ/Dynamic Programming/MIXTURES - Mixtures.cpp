#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll INF=pow(10,18),N,dp[105][105],arr[105];

ll solve(ll left, ll right)
{
//	cout<<left<<" "<<right<<"   "<<arr[left]*arr[right]<<"\n";
	if (left==right)
		return 0;
	if (left>right)
		return 0;
	if (right-left==1)
		return arr[left]*arr[right];
	if (dp[left][right]!=-1)
		return dp[left][right];
		
	ll curr=INF, temp;
	for (int i=left;i<right;i++)
	{
		temp=solve(left,i)+solve(i+1,right)+((arr[i]%100)*(arr[i+1]%100));
		cout<<left<<" "<<i<<" "<<right<<"  "<<temp<<"\n";
		curr=min(curr,temp);
	}
return dp[left][right]=curr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	while (cin>>N)
	{
		for (int i=1;i<=N;i++)
			cin>>arr[i];
		
		memset(dp,-1,sizeof(dp));
		
		ll ans=solve(1,N);
		cout<<ans<<"\n";
	}
return 0;
}
