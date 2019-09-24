#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll segtree[400005], pref_energy[100005], pref_profit[100005], arr[100005], ans, INF=2*pow(10,15),N;
ll dist[100005], energy[100005], profit[100005];

void build_segtree(ll low, ll high, ll pos)
{
	if (low==high)
	{
		segtree[pos]=arr[low];
		return;
	}
	
	ll mid=(high+low)/2;
	build_segtree(low,mid,2*pos);
	build_segtree(mid+1,high,2*pos+1);
	
	segtree[pos]=min(segtree[2*pos], segtree[2*pos+1]);
}

ll RMQ(ll low, ll high, ll qlow, ll qhigh, ll pos)
{
	if (qlow<=low && qhigh>=high)	//total overlap
		return segtree[pos];
		
	if (qlow>high || qhigh<low)
		return INF;
		
	ll mid=(low+high)/2;

return min(RMQ(low,mid,qlow,qhigh,2*pos),
		   RMQ(mid+1,high,qlow,qhigh,2*pos+1));
}

void binser(ll id, ll val)
{
	ll left,right,mid;
	
	left=1;		right=id;
	
	for (int it=1;it<=100;it++)
	{
		mid=(left+right)/2;
		
//		cout<<id<<"  "<<left<<" "<<mid<<"   "<<val<<" "<<RMQ(1,N,left,mid,1)<<"\n";
		if (RMQ(1,N,left,mid,1)<=val)
			right=mid;
		else
			left=mid+1;
	}
		
	if (mid>0)
	{
		ll res=pref_profit[id]-pref_profit[mid-1];
		ans=max(ans,res);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N;
	
	memset(pref_energy,0,sizeof(pref_energy));
	memset(pref_profit,0,sizeof(pref_profit));
	
	for (ll i=1;i<=N;i++)
	{
		cin>>dist[i]>>profit[i]>>energy[i];
		pref_energy[i]=pref_energy[i-1]+energy[i];
		pref_profit[i]=pref_profit[i-1]+profit[i];
		
		ll temp=pref_energy[i-1]-dist[i];
		arr[i]=temp;
	}
	
//	for (ll i=1;i<=N;i++)
//		cout<<i<<" "<<arr[i]<<"\n";
//	cout<<"\n";
	
	build_segtree(1,N,1);
	
	ans=-1;
	for (ll i=1;i<=N;i++)
	{
		ll curr=pref_energy[i]-dist[i];
		binser(i, curr);
	}
	cout<<ans<<"\n";
return 0;
}
