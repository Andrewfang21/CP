#include<bits/stdc++.h>
using namespace std;

int N, M, INF = 1000005, petak[1005][1005], dist[1005][1005];

typedef pair< int, pair<int , int > > ii;

int main ()
{
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	
	for (int i = 1; i <= N; i ++)
		for (int j = 1;j <= M; j ++)
		{
			cin >> petak[i][j];
			dist[i][j] = INF;
		}
		
	int mulai_x, mulai_y, selesai_x, selesai_y;
	cin >> mulai_x >> mulai_y;
	cin >> selesai_x >> selesai_y;
	
	priority_queue<ii, vector<ii> , greater<ii> > q;
	q.push(make_pair(0, make_pair(mulai_x, mulai_y)));
	
	while (! q.empty())
	{
		ii now = q.top();			q.pop();
		
		if (now.second.first < 1 || now.second.first > N || now.second.second < 1 || now.second.second > M)
			continue;
		
		if (petak[now.second.first][now.second.second] == -1)		continue;
		
		if (dist[now.second.first][now.second.second] > now.first)
			dist[now.second.first][now.second.second] = now.first;
		else
			continue;
					
		q.push(make_pair(max(now.first, petak[now.second.first + 1][now.second.second]), make_pair(now.second.first + 1, now.second.second)));
		q.push(make_pair(max(now.first, petak[now.second.first - 1][now.second.second]), make_pair(now.second.first - 1, now.second.second)));
		q.push(make_pair(max(now.first, petak[now.second.first][now.second.second + 1]), make_pair(now.second.first, now.second.second + 1)));
		q.push(make_pair(max(now.first, petak[now.second.first][now.second.second - 1]), make_pair(now.second.first, now.second.second - 1)));

	}	
	cout << dist[selesai_x][selesai_y] << "\n";
return 0;
}