#include<bits/stdc++.h>
using namespace std;

int petak[105][105], dist[105][105];

struct lol
{
	int x, y, jarak;
};

int main ()
{
	int N, M, A, B;
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= M; j ++)
			cin >> petak[i][j];
	
	cin >> A >> B;
	queue<lol> q;
	
	memset(dist, -1, sizeof(dist));
	q.push({A, B, 1});
	
	int ans;
	while (!q.empty() )
	{
		lol now = q.front();		q.pop();
		
		if (dist[now.x][now.y] != -1)		continue;
		if (petak[now.x][now.y] == -1)		continue;
		
		dist[now.x][now.y] = now.jarak;
		
		if (now.x == 1 || now.y == 1 || now.x == N || now.y == M)
		{
			ans = now.jarak;
			break;
		}
		
		q.push({now.x + 1, now.y, now.jarak + 1});
		q.push({now.x - 1, now.y, now.jarak + 1});
		q.push({now.x, now.y + 1, now.jarak + 1});
		q.push({now.x, now.y - 1, now.jarak + 1});
	}
	cout << ans << "\n";
}