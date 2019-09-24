#include<bits/stdc++.h>
using namespace std;

int N, M, mulai, akhir, dist[2555];
vector<pair<int, int> > adj[2555];

int main ()
{
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> mulai >> akhir;
	
	for (int i = 1; i <= M; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}
	
	queue<pair<int , int> > q;
	q.push(make_pair(mulai, 0));
	
	for (int i = 1; i <= N; i ++)
		dist[i] = 1000000;
	
	while (!q.empty())
	{
		pair<int , int> sekarang = q.front();			q.pop();
		
		if (dist[sekarang.first] > sekarang.second)
			dist[sekarang.first] = sekarang.second;
		else
			continue;
		
//		cout << sekarang.first << "\n";	
			
		for (int i = 0; i <adj[sekarang.first].size(); i ++)
		{
			int nexts = adj[sekarang.first][i].first;
			int bobot = adj[sekarang.first][i].second;
			
			q.push(make_pair(nexts, sekarang.second + bobot));
		}
	}
	cout << dist[akhir] << "\n";
return 0;
}