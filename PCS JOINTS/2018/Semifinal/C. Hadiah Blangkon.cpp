#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N,K,TC,res,MOD=pow(10,9)+7,x,y;

ll pangkat(ll base, ll power)
{
	if (power==0)
		return 1;
	if (power==1)
		return base;
		
	ll temp=pangkat(base,power/2);
	if (power%2==0)
		return (temp%MOD * temp%MOD)%MOD;
	else
		return (base%MOD * (temp%MOD * temp%MOD)%MOD)%MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>K;
		x=(N%MOD * (pangkat(N,K)-1)%MOD)%MOD;
		y=(N-1)%MOD;
		
		res=(x%MOD * pangkat(y,MOD-2)%MOD)%MOD;
		cout<<res<<"\n";
	}
return 0;
}