#include<bits/stdc++.h>
#define fi first
#define sec second
#define pb push_back
using namespace std;

long long N,energy,B,C;
vector<long long>v;
pair<long long, long long>res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>energy>>B>>C;
	
	for (int i=0;i<N;i++)
	{
		int mons;
		cin>>mons;
		v.pb(mons);
	}
	sort(v.begin(), v.end());
	
	for (int i=0;i<v.size();i++)
	{
		if (energy>=v[i])
		{
			res.fi++;
			energy+=C;
		}
		else
		if (energy+B>=v[i])
		{
			res.fi++;		res.sec++;
			energy+=C;
		}
		else
			break;
	}
	cout<<res.fi<<" "<<res.sec<<"\n";
	
return 0;
}
