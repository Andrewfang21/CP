#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,N,i,j,k;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		int adj[N+5][N+5],dist[N+5][N+5];
		bool not_neighbour[N+5][N+5];
		memset(not_neighbour,false,sizeof(not_neighbour));
		
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
			{
				cin>>adj[i][j];
				dist[i][j]=adj[i][j];
			}
			
		for (k=1;k<=N;k++)
		{
			for (i=1;i<=N;i++)
			{
				for (j=1;j<=N;j++)
				{
					if ((dist[i][j]==(dist[i][k]+dist[k][j]))&&(i!=k)&&(j!=k))
					{
						/*cout<<i<<" "<<j<<"\n";
						printf("dist[%d][[%d]=%d	",i,j,dist[i][j]);
						printf("dist[[%d][[%d]=%d	",i,k,dist[i][k]);
						printf("dist[[%d][[%d]=%d\n",k,j,dist[k][j]);*/
						
						not_neighbour[i][j]=true;
					}
				}	
			}	
		}
		
		for (i=1;i<=N;i++)
		{
			for (j=i+1;j<=N;j++)
				if (!not_neighbour[i][j])
					cout<<i<<" "<<j<<"\n";	
		}				
	}
return 0;
}
