#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll C[1005][1005],TC,orang,meja,seat,sisa,mod=pow(10,9)+7;

void precompute()
{
	for (int i=1;i<=1000;i++)
		for (int j=0;j<=i;j++)
		{
			if (j==0 || j==i)
				C[i][j]=1;
			else
				C[i][j]=(C[i-1][j-1]%mod + C[i-1][j]%mod)%mod;
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	precompute();
	
	cin>>TC;
	
	for (int tc=1;tc<=TC;tc++)
	{
		cin>>orang>>meja;
		seat=orang/meja;
		sisa=orang%meja;
		
		long long res=1;
		for (int i=1;i<=meja;i++)
		{
			if (sisa!=0)
			{
				res=(res%mod * C[orang][seat+1]%mod)%mod;
				orang=orang-(seat+1);
				sisa--;
			}
			else
			{
				res=(res%mod * C[orang][seat]%mod)%mod;
				orang-=seat;
			}
		}
		cout<<"Kasus #"<<tc<<": "<<res<<"\n";
	}
return 0;
}
