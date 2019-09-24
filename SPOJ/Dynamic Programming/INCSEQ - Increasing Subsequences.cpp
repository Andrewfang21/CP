#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N,K,pref[10005][55],dp[10005][55],res=0,MOD=5000000,MAXX;

struct lol
{
	ll val,index;
}arr[10005];

void debug()
{
}

bool value(lol lhs, lol rhs)
{
	return lhs.val<rhs.val;
}

bool indeks(lol lhs, lol rhs)
{
	return lhs.index<rhs.index;
}

void compress()
{
	MAXX=-1;
	for (int i=2;i<=N;i++)
	{
		if (i==2)
		{
			if (arr[i].val==arr[i-1].val)
				arr[i].val=arr[i-1].val=1;
			arr[1].val=1;
		}
		if (arr[i].val==arr[i-1].val)
			arr[i].val=arr[i-1].val;
		else
			arr[i].val=arr[i-1].val+1;
			
		MAXX=max(MAXX,arr[i].val);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>K;
	
	for (int i=1;i<=N;i++)
	{
		ll x;
		cin>>x;
		arr[i].val=x;		arr[i].index=i;
	}
	sort(arr+1, arr+N+1, value);
	compress();
	sort(arr+1, arr+N+1, indeks);
	
	cout<<MAXX<<"\n";
return 0;
}
