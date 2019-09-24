#include<bits/stdc++.h>
#define ull unsigned long long
#define mod 1000000007
using namespace std;
ull N,M,K,ans,temp[5],C[1005][1005];
bool used[5];

ull pangkat(ull base, ull power)
{
	ull res;
	if (power==0)
		return 1;
	if (power==1)
		return base%mod;
		
	if (power%2==0)
	{
		res=pangkat(base,power/2);
		return ((res%mod)*(res%mod))%mod;
	}
	else
	{
		res=pangkat(base,power/2);
		return (((base%mod)*(res%mod))%mod*(res%mod)%mod);
	}
}

void Kombinasi()
{
	ull i,j;
	for (i=0;i<=M;i++)
		for (j=0;j<=i;j++)
		{
			if ((j==0)||(j==i))
				C[i][j]=1;
			else
				C[i][j]=((C[i-1][j-1]%mod)+(C[i-1][j]%mod))%mod;
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	string dummy,shop;
	cin>>dummy;
	cin>>N>>M>>K;
	cin>>shop;
	memset(used,false,sizeof(used));
	
	if ((dummy[8]!='8')&&(dummy[9]!='9'))
	{
		Kombinasi();
		//print();
		ans=(pangkat(pangkat(2,M),(N-1))%mod*((C[M][K])%mod))%mod;
		/*cout<<pangkat(pangkat(2,M),N-1)<<" ";
		cout<<C[M][K]<<"\n";*/
		cout<<ans<<"\n";
	}
	else 	 
	{
		ans=pangkat(pangkat(2,M),(N-1))%mod;
		ull temp2=1,a,b,i;
		
		a=1;
		for (i=M;i>(M-K);i--)
			a=((a%mod)*(i%mod))%mod;
		b=1;
		for (i=1;i<=K;i++)
			b=((b%mod)*(i%mod))%mod;
			
		temp2=((a%mod)*(pangkat(b,1000000005)%mod))%mod;
		ans=((ans%mod)*(temp2%mod))%mod;
		
		cout<<ans<<'\n';	
	}
return 0;
}
