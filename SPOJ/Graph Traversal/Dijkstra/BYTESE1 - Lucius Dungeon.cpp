#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int M,N,TC,waktu,arr[105][105],dist[105][105];
bool visited[105][105];
pair<int,int> finis,temp;

bool inside (int x, int y)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=M))
		return true;
return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,i,j,INF=2*pow(10,8);
	cin>>TC;
	vector<int> movex,movey;
	
	movex.pb(1);	movex.pb(0);	movex.pb(0);	movex.pb(-1);
	movey.pb(0);	movey.pb(1);	movey.pb(-1);	movey.pb(0);
	
	while (TC--)
	{
		cin>>N>>M;
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
			{
				cin>>arr[i][j];
				dist[i][j]=INF;
			}
		cin>>finis.first>>finis.second>>waktu;
		
		typedef pair <int, pair<int,int> > ii;
		priority_queue<ii, vector<ii>, greater<ii> >q;
		memset(visited,false,sizeof(visited));
		q.push({arr[1][1],make_pair(1,1)});
		ii u;
		
		while (!q.empty())
		{
			u=q.top();		q.pop();
			
			if ((inside(u.second.first,u.second.second))&&(!visited[u.second.first][u.second.second]))
			{
				visited[u.second.first][u.second.second]=true;
				dist[u.second.first][u.second.second]=min(dist[u.second.first][u.second.second],u.first);
		
				//cout<<u.second.first<<" "<<u.second.second<<" "<<dist[u.second.first][u.second.second]<<"\n";
				for (i=0;i<4;i++)
				{
					temp=make_pair(u.second.first+movex[i],u.second.second+movey[i]);
					if ((dist[temp.first][temp.second]>dist[u.second.first][u.second.second]+arr[temp.first][temp.second])&&(!visited[temp.first][temp.second]))
						q.push({dist[u.second.first][u.second.second]+arr[temp.first][temp.second],make_pair(temp.first,temp.second)});
				}
			}
		}
		if (dist[finis.first][finis.second]>waktu)
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			int ans=(waktu-dist[finis.first][finis.second]);
			cout<<ans<<"\n";
		}
	}
return 0;
}
