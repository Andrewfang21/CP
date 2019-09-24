#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll N,sumx,sumy,curr_size,res;
vector<ll>x,y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N;
	
	for (int i=1;i<=N;i++)
	{
		int a,b;
		cin>>a>>b;
		x.pb(a);		y.pb(b);
		sumx+=a;		sumy+=b;
	}
	sort(x.begin(), x.end(), greater<int>() );
	sort(y.begin(), y.end(), greater<int>() );
	
	curr_size=N-1;
	
	res=0;
	for (int i=0;i<N;i++)
	{
		res=res+((x[i] * curr_size)-(sumx-x[i]));
		res=res+((y[i] * curr_size)-(sumy-y[i]));
		
		sumx-=x[i];		sumy-=y[i];
		curr_size--;
	}
	cout<<res<<"\n";
}
