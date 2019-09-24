#include<bits/stdc++.h>
using namespace std;
int INF=2*pow(10,8),N,toll[55][55],waktu[55][55];
pair<int,int>dp[55][1005];

pair<int,int> solve(int city, int time_left)
{
	if (time_left<0)
		return make_pair(INF,INF);
	if (city==(N-1))
		return make_pair(0,0);	
	if (dp[city][time_left].first!=-1)
		return dp[city][time_left];
	
	pair<int,int> next,ans=make_pair(INF,INF);
	
	for (int temp=0;temp<N;temp++)
	{
		if (temp!=city)
		{
			next=solve(temp,time_left-waktu[city][temp]);
			
			if (next.first+toll[city][temp]<ans.first)
			{
				ans.first=next.first+toll[city][temp];
				ans.second=next.second+waktu[city][temp];
			}
		}
	}
	//printf("%d %d %d %d\n",city,time_left,ans.first,ans.second);
	
return dp[city][time_left]=ans;
}

int main()
{
	int T,i,j;
	while (cin>>N>>T)
	{
		if ((N==0)&&(T==0))
			return 0;
		
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
				cin>>waktu[i][j];
				
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
				cin>>toll[i][j];
				
		memset(dp,-1,sizeof(dp));
		
		pair<int,int> res=solve(0,T);
		cout<<res.first<<" "<<res.second<<"\n";
	}
return 0;
}
