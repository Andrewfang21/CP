#include<bits/stdc++.h>
using namespace std;
short dp[105][505][105][2],N,P,Q,INF=30000;

struct lol
{
	short berat,daya,warna;
}data[105];

bool cmp(lol lhs, lol rhs)
{
	return lhs.warna<rhs.warna;
}

short solve(short i, short j, short k, short used)
{
	if (j<0)
		return -INF;
	else
	if (j>=0)
	{
		if ((i==0)&&(k<Q))
			return -INF;
		if ((i==0)&&(k>=Q))
			return 0;
	}
	if (dp[i][j][k][used]!=-1)
		return dp[i][j][k][used];
	

	short ans;
	if (data[i].warna!=data[i-1].warna)
		ans=max(short(solve(i-1,j,k,0)),short(solve(i-1,j-data[i].berat,k+(1-used),0)+data[i].daya));	
	else
	{
		if (used==0)
			ans=max(short(solve(i-1,j,k,0)),short(solve(i-1,j-data[i].berat,k+1,1)+data[i].daya));
		else
			ans=max(short(solve(i-1,j,k,1)),short(solve(i-1,j-data[i].berat,k,1)+data[i].daya));
	}
	//printf("%d %d %d %d %d\n",i,j,k,used,ans);
return dp[i][j][k][used]=ans;	
}

int main()
{
	char a[20],b[20];
	scanf("%s %s",a,b);
	scanf("%hu %hu %hu",&N,&P,&Q);
	
	for (short i=1;i<=N;i++)
		scanf("%hu %hu %hu",&data[i].berat,&data[i].daya,&data[i].warna);
	
	sort(data+1,data+N+1,cmp);
	memset(dp,-1,sizeof(dp));
	
	/*printf("\n");
	for (short i=1;i<=N;i++)
		printf("%d %d %d\n",data[i].berat,data[i].daya,data[i].warna);
	printf("\n");*/
	short ans=solve(N,P,0,0);
	
	if (ans>0)
		printf("%hu\n",ans);
	else
		printf("-1\n");
return 0;
}