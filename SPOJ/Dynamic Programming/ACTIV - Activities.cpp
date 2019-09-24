#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll MAXX=1000000005,N,dp[100005],MOD=100000000;
map<ll, ll>BIT;

struct lol
{
	ll start,finish;	
}arr[100005];

bool cmp(lol lhs, lol rhs)
{
	if (lhs.finish==rhs.finish)
		return lhs.start<rhs.start;
		
return lhs.finish<rhs.finish;
}

void update(ll i, ll val)
{
	while (i<MAXX)
	{
		BIT[i]+=val;
		i+=(i & -i);
	}
}

ll query(ll val)
{
	ll res=0;
	
	while (val>0)
	{
		res+=BIT[val];
		val-=(val & -val);
	}
return res;
}

void print(ll res)
{
	if (res<10)
		cout<<"0000000";
	else
	if (res<100)
		cout<<"000000";
	else
	if (res<1000)
		cout<<"00000";
	else
	if (res<10000)
		cout<<"0000";
	else
	if (res<100000)
		cout<<"000";
	else
	if (res<1000000)
		cout<<"00";
	else
	if (res<10000000)
		cout<<"0";
	cout<<res<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	while (cin>>N)
	{
		if (N==-1)
			return 0;
		
		memset(dp,0,sizeof(dp));
		BIT.clear();
		for (int i=1;i<=N;i++)
		{
			cin>>arr[i].start>>arr[i].finish;
			update(arr[i].finish,1);
		}
				
		sort(arr+1, arr+N+1,cmp);
					
		for (int i=1;i<=N;i++)
		{
			ll bound=arr[i].start;
			dp[i]+=query(bound);
			
			if (dp[i]>MOD)
				dp[i]%=MOD;
				
//			cout<<i<<" "<<bound<<"  "<<query(bound)<<"\n";
			update(arr[i].finish, dp[i]);
		}
		
		ll res=0;
		for (int i=1;i<=N;i++)
		{
			res+=dp[i];
			
			if (res>MOD)
				res%=MOD;
		}
			
		res=(res+N)%MOD;
//		cout<<"\n";
//		for (int i=1;i<=N;i++)
//			cout<<dp[i]<<"\n";
		print(res);
	}
}
