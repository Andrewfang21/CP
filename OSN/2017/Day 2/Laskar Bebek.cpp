#include<bits/stdc++.h>
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;

ll N,K,num;
vector<ll>vec;
vector<pair<ll,ll> >sorted,segmen;
map<ll,ll>pos;

int main()
{
	ios_base::sync_with_stdio(false);
	
	string subs;
	cin>>subs;
	
	cin>>N>>K;
	for (int i=0;i<N;i++)
	{
		cin>>num;
		sorted.pb(mp(num,i));
		
		vec.pb(num);
	}
	sort(sorted.begin(), sorted.end());
	
	for (int i=0;i<N;i++)
		pos[sorted[i].sec]=i;
		
/*	for (int i=0;i<N;i++)
		cout<<"pos["<<i<<"] = "<<pos[i]<<"\n";*/
		
	ll start,max_index;
	start=max_index=-1;
	
	for (int i=0;i<N;i++)
	{
		if (start!=-1)
			max_index=max(max_index,pos[i]);
		
		if (vec[i]!=sorted[i].fi)
		{
			if (start==-1)
			{
				start=i;
				max_index=pos[i];
			}
		}
		
		if (max_index==i)
		{
			segmen.pb(mp(start,i));
			start=max_index=-1;
		}
	}
	
//	for (int i=0;i<segmen.size();i++)
//		cout<<segmen[i].fi<<" "<<segmen[i].sec<<"\n";	

	ll res=0;
	if (segmen.size()<=K)
	{
		for (int i=0;i<segmen.size();i++)
			res+=(segmen[i].sec-segmen[i].fi+1);
		res+=(K-segmen.size());
		
		cout<<res<<"\n";
	}
	else
	{
		vector<ll> temp;
		for (int i=1;i<segmen.size();i++)
			temp.pb(segmen[i].fi-segmen[i-1].sec-1);
			
		for (int i=0;i<segmen.size();i++)
			res+=(segmen[i].sec-segmen[i].fi+1);
			
		sort(temp.begin(), temp.end());
		K=segmen.size()-K;
		
		for (int i=0;i<K;i++)
			res+=temp[i];
			
		cout<<res<<"\n";
	}
}
