#include<bits/stdc++.h>
#pragma GCC Optimize ("O3")
using namespace std;

const int n = 1005;

int N;
int dist[n][n], in[n], out[n];

pair<int, int> res;

void read ()
{
	memset(dist, 0, sizeof(dist));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	
	res = make_pair(0, 0);

	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= N; j ++)
		{
			cin >> dist[i][j];
			res.first += dist[i][j];
		}
}

void work (int tc)
{
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= N; j ++)
		{
			out[i] += dist[i][j];
			in[j] += dist[i][j];
		}

	for (int i = 1; i <= N; i ++)
		if (out[i] > in[i])
		{
			out[i] -= in[i];
			in[i] = 0;
		}
		else
		{
			in[i] -= out[i];
			out[i] = 0;
		}

	// for (int i = 1; i <= N; i ++)
	// 	cout << i << ":  " << in[i] << "  " << out[i] << "\n";


	for (int i = 1; i <= N; i ++)
		res.second += in[i];

	cout << tc << ". " << res.first << " " << res.second << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);

	int tc = 0;
	while (cin >> N)
	{
		if (N == 0)			return 0;

		tc ++;
		read ();
		work (tc);
	}

return 0;
}