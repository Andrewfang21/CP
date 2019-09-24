#include<bits/stdc++.h>
using namespace std;
int N;
double P,dp[10005][2],cost,fine;
bool memo[10005][2];

double solve(int i, int condition)
{
	if (i==N)
		return 1;
	if (memo[i][condition])
		return dp[i][condition];
		
	double ans;
	if (condition==1)	//masih bagus
		ans=solve(i+1,0)*(1.0-P);
	else
	if (condition==0)	//pintu rusak
	{
		ans=min(solve(i+1,1)*cost,	//perbaiki
				solve(i+1,0)*fine);	//biarin
	}
	
	memo[i][condition]=true;
return dp[i][condition]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	while (cin>>N>>P>>cost>>fine)
	{
		if (N==0 && P==0 && cost==0 && fine==0)
			return 0;
			
		P/=100.0;
		
		double ans;
		memset(memo,false,sizeof(memo));
		ans=solve(1,1);
		cout<<setprecision(5)<<fixed<<ans<<"\n";
	}
return 0;
}
