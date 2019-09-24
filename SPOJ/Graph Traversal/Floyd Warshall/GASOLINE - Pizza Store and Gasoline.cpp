#include<bits/stdc++.h>
using namespace std;
int TC,dist[505][505],M,N,i,j,k,a,b,c,ans,INF=2*pow(10,8);
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M;
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
				if (i==j)
					dist[i][j]=0;
				else
					dist[i][j]=INF;
		
		for (i=1;i<=M;i++)
		{
			cin>>a>>b>>c;
			dist[a][b]=min(dist[a][b],c);
			dist[b][a]=min(dist[b][a],c);
		}
		
		for (k=0;k<N;k++)
			for (i=0;i<N;i++)
				for (j=0;j<N;j++)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		ans=-1;
		bool fail=false;
		
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
			{
				if (dist[i][j]==INF)
					fail=true;
				else
					ans=max(ans,dist[i][j]);
			}
		if (fail)
			cout<<"-1\n";
		else
			cout<<ans<<"\n";
	}
return 0;
}
