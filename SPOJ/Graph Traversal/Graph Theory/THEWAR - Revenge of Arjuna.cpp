#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,N,K,i,j;
	double weight[55][55],dist[55],INF=2*pow(10,7);
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
				cin>>weight[i][j];
		cin>>K;
		
		typedef pair<double, pair<int,int> > ii;
		priority_queue<ii, vector<ii>, greater<ii> >q;
		q.push({0,make_pair(0,K)});
		ii u;
		
		for (i=0;i<N;i++)
			dist[i]=INF;
		
		while (!q.empty())
		{
			u=q.top();		q.pop();
		
			if (dist[u.second.first]>u.first)
			{
				dist[u.second.first]=u.first;
			
				//cout<<setprecision(1)<<fixed<<u.second.first<<" "<<dist[u.second.first]<<" "<<u.second.second<<"\n";
			
				for (i=0;i<N;i++)
				{
					double temp=weight[u.second.first][i];
					
					if ((dist[i]>dist[u.second.first]+temp)&&(temp!=u.second.first))
					{
						if (u.second.second>0)
							q.push({dist[u.second.first]+(temp/2),make_pair(i,u.second.second-1)});
						q.push({dist[u.second.first]+temp,make_pair(i,u.second.second)});
					}
				}
			}
		}
		cout<<setprecision(1)<<fixed<<dist[1]<<"\n";	
	}
return 0;
}
