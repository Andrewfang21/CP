#include<bits/stdc++.h>
using namespace std;
long long dist[55][55],TC,sum,N,i,j,k,Q,INF=2*pow(10,8),a,b,tc;

int main()
{
	cin>>TC;
	tc=0;
	
	while (TC--)
	{
		sum=0;
		cin>>N;
		
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
				cin>>dist[i][j];
				
		for (k=1;k<=N;k++)
			for (i=1;i<=N;i++)
				for (j=1;j<=N;j++)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		cin>>Q;
		for (i=1;i<=Q;i++)
		{
			cin>>a>>b;
			sum+=dist[a][b];
		}
		printf("Case #%d: %lld\n",++tc,sum);
	}
}
