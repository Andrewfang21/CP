#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,Q,BIT[1000005],arr[1000005],MAXX=1000005;

void construct(int i, ll val)
{
	while (i<MAXX)
	{
		BIT[i]+=val;
		i+=(i & -i);
	}
}

void update(int index, ll val)
{
	while (index<MAXX)
	{
		BIT[index]+=val;
		index+=(index & -index);
	}
}

ll sum(int index)
{
	ll res=0;
	
	while (index>0)
	{
		res+=BIT[index];
		index-=(index & -index);
	}
return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N;
	
	int i,a,b;
	char type;
	
	for (i=1;i<=N;i++)
		cin>>arr[i];
		
	for (i=1;i<=N;i++)
		construct(i,arr[i]);
		
	cin>>Q;
	
	while (Q--)
	{
		cin>>type;
		
		if (type=='q')
		{
			cin>>a>>b;
			ll ans=sum(b)-sum(a-1);
			cout<<ans<<"\n";
		}
		else
		{
			ll val;
			cin>>i>>val;
			update(i,val);
		}
	}
return 0;
}
