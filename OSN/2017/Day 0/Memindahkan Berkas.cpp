#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

vector<ll>a[105];
bool used[50005],success;
ll curr_size,N,cap,K,v[50005],sum;

void rec(ll now)
{
	if (sum==cap)
	{
		success=true;
		return;
	}
	if (now>N || sum>cap)
		return;

	if (used[now])
		rec(now+1);
	else
	{
		used[now]=true;
		sum+=v[now];
		rec(now+1);
		sum-=v[now];
		used[now]=false;
		
		if (success)
		{
			used[now]=true;
			a[curr_size].pb(now);
		}
		else
			rec(now+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	freopen("osn-2017-memindahkan-berkas_4_1.in","r",stdin);
	freopen("osn-2017-memindahkan-berkas_4_1.out","w",stdout);
	
	string subs;
	cin>>subs;
	
	cin>>N>>cap>>K;
	for (ll i=1;i<=N;i++)
		cin>>v[i];
		
	curr_size=1;
	for (ll i=1;i<=N;i++)
	{
		if (!used[i])
		{
			sum=0;
			success=false;
			rec(i);
			curr_size++;
		}
	}
	
	cout<<curr_size-1<<"\n";
	for (ll i=1;i<curr_size;i++)
	{
		cout<<a[i].size();
		
		for (ll it=0;it<a[i].size();it++)
			cout<<" "<<a[i][it];
		cout<<"\n";
	}
return 0;
}
