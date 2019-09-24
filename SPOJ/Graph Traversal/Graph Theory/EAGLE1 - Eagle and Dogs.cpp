#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,int> >adj[100005];
pair<long long,int>temp1;
long long ans,temp2;
bool visited[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,N,a,b,c,i;
	vector<long long>vec;
			
	scanf("%d",&TC);
	
	while (TC--)
	{
		scanf("%d",&N);
		for (i=1;i<N;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			adj[a].push_back(make_pair(b,c));	
			adj[b].push_back(make_pair(a,c));
		}
		typedef pair<long long,int> ii;
		priority_queue<ii, vector<ii>, greater<ii> >q;
				
		for (i=1;i<=N;i++)
		{
			memset(visited,false,sizeof(visited));
		
			ans=0;	
			q.push({0,i});
			ii u;
			
			while (!q.empty())
			{
				u=q.top();		q.pop();
				
				if (!visited[u.second])
				{
					visited[u.second]=true;
					ans=max(ans,u.first);
					
					//cout<<u.second<<" "<<u.first<<"\n";
									
					for (int j=0;j<adj[u.second].size();j++)
					{
						temp1=adj[u.second][j];
						
						if (!visited[temp1.first])
							q.push({u.first+temp1.second,temp1.first});
					}
				}
			}
			//cout<<"\n";
			vec.push_back(ans);
		}
		for (i=0;i<vec.size();i++)
			if (i==vec.size()-1)
				printf("%d\n",vec[i]);
			else
				printf("%d ",vec[i]);
		
		vec.clear();
		for (i=1;i<=N;i++)
			adj[i].clear();
	}
return 0;
}
