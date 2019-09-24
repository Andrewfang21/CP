#include<bits/stdc++.h>
using namespace std;
int i,N,a,b;
int memo[20005][20005];
struct lol
{
	int x,y;
}now;

int main()
{
	now.x=0;	now.y=0;
	memset(memo,0,sizeof(memo));
	
	for (i=1;i<=25000;i++)
	{
		memo[now.x+1][now.y+1]=memo[now.x][now.y]+1;
		now.x+=1;	now.y+=1;	i++;
		
		memo[now.x-1][now.y+1]=memo[now.x][now.y]+1;
		now.x-=1;	now.y+=1;	i++;
		
		memo[now.x+1][now.y+1]=memo[now.x][now.y]+1;
		now.x+=1;	now.y+=1;	i++;
		
		memo[now.x+1][now.y-1]=memo[now.x][now.y]+1;
		now.x+=1;	now.y-=1;
	}
	/*for (i=6;i>=0;i--)
	{
		for (int j=0;j<=6;j++)
			cout<<memo[i][j]<<" ";
		cout<<"\n";
	}*/
	cin>>N;
	while (N--)
	{
		cin>>a>>b;
		if ((a==0)&&(b==0))
			cout<<"0\n";
		else
		if (memo[b][a]==0)
			cout<<"No Number\n";
		else
			cout<<memo[b][a]<<"\n";
	}
return 0;
}
