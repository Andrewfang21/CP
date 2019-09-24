#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define sec second	
using namespace std;
int N,i,a,b;
vector<pair<int, int> >vec;
pair<int, int>prevs;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N;
	
	for (i=1;i<=N;i++)
	{
		cin>>a>>b;
		vec.pb(mp(a,b));
	}
	
	if (N==1)
	{
		cout<<"1\n";
		return 0;
	}
	
	sort(vec.begin(), vec.end());
	
	int cnt=1,res=-1;
	
	prevs=mp(vec[0].fi, vec[0].sec);
	for (i=1;i<vec.size();i++)
	{
		if (vec[i].fi==prevs.fi && vec[i].sec==prevs.sec)
			cnt++;
		else
			cnt=1;
			
		res=max(cnt,res);
		
		prevs=mp(vec[i].fi, vec[i].sec);
	}
	if (res%2==0)
		cout<<res/2<<"\n";
	else
		cout<<(res/2)+1<<"\n";
		
return 0;
}
