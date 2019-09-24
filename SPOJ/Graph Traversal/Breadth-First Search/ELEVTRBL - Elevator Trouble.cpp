#include<bits/stdc++.h>
using namespace std;

struct lol
{
	long long st,walk;
};

int main()
{
	long long floor,start,goal,up,down;
	lol u;
	cin>>floor>>start>>goal>>up>>down;
	bool visited[floor+5];
	long long dist[floor+5];
	memset(visited,false,sizeof(visited));
	long long INF=INT_MAX;
	
	dist[goal]=INF;
	dist[start]=-1;
	
	queue<lol> q;
	q.push({start,dist[start]});
	
	while (!q.empty())
	{
		u=q.front();	q.pop();
		if (!visited[u.st])
		{
			visited[u.st]=true;
			dist[u.st]=u.walk+1;
			
			if ((u.st-down)>=1)
				q.push({u.st-down,dist[u.st]});
			if ((u.st+up)<=floor)
				q.push({u.st+up,dist[u.st]});
		}
	}
	if (dist[goal]==INF)
		cout<<"use the stairs\n";
	else
		cout<<dist[goal]<<"\n";
return 0;
}
