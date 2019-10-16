#include<bits/stdc++.h>
using namespace std;

int h[5],a[5],dp[1500][1500][5];

void compute()
{
	h[1]=3;		a[1]=2;
	h[2]=-5;	a[2]=-10;
	h[3]=-20;	a[3]=5;
}

int solve(int health, int armor, int place)
{
	if (health<=0 || armor<=0)
		return 0;
	if (dp[health][armor][place]!=-1)
		return dp[health][armor][place];
	
	int ans=-1;
	
	for (int nexts=1;nexts<=3;nexts++)
		if (nexts!=place)
			ans=max(ans,solve(health+h[nexts], armor+a[nexts], nexts)+1);

//	cout<<health<<" "<<armor<<" "<<place<<"  "<<ans<<"\n";			
return dp[health][armor][place]=ans;	
}


int main()
{
	ios_base::sync_with_stdio(false);
	
	int TC;
	cin>>TC;
	compute();
	
	while (TC--)
	{
		int health,armor;
		cin>>health>>armor;
		
		memset(dp,-1,sizeof(dp));
		int ans=0;
		
		for (int i=1;i<=3;i++)
			ans=max(ans,solve(health+h[i],armor+a[i],i));
				
		cout<<ans<<"\n";
	}
return 0;
}
