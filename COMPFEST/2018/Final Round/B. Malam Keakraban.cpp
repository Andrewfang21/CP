#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

typedef pair<int, int> ii;
const int n = 1e5 + 5;

int N;
int cnt[n];

queue<int> idx[n];
vector<ii> V;

void read ()
{
	cin >> N;

	memset(cnt, 0, sizeof(cnt));

	for (int i = 1; i <= N; i ++)
	{
		int num;

		cin >> num;
		idx[num].push(i);

		cnt[num] ++;
	}
}

void work ()
{
	priority_queue<ii, vector<ii> > q;

	for (int i = 1; i <= 100000; i ++)
		if (cnt[i] > 0)
			q.push(make_pair(cnt[i], i));


	while (!q.empty())
	{
		ii u = q.top();			q.pop();

		if (V.empty())
		{
			int pos = idx[u.second].front();			idx[u.second].pop();

			V.push_back(make_pair(pos, u.second));
			cnt[u.second] --;

			if (cnt[u.second] > 0)
				q.push(make_pair(cnt[u.second], u.second));
		}
		else
		{
			int prevs, now;
			prevs = V[V.size() - 1].second;

			if (prevs != u.second || prevs == u.second && q.empty())
			{
				int pos = idx[u.second].front();		idx[u.second].pop();

				V.push_back(make_pair(pos, u.second));
				cnt[u.second] --;

				if (cnt[u.second] > 0)
					q.push(make_pair(cnt[u.second], u.second));
			}
			else
			{
				ii nexts = q.top();		q.pop();
				q.push(make_pair(cnt[u.second], u.second));

				int pos = idx[nexts.second].front();		idx[nexts.second].pop();

				V.push_back(make_pair(pos, nexts.second));
				cnt[nexts.second] --;

				if (cnt[nexts.second] > 0)
					q.push(make_pair(cnt[nexts.second], nexts.second));
			}
		}
	}

	if (V[0].second == V[V.size() - 1].second)
		swap(V[V.size() - 1], V[V.size() - 2]);

	int sum = 0;
	for (int i = 1; i < V.size(); i ++)
		if (V[i].second == V[i - 1].second)		sum ++;

	if (V[0].second == V[V.size() - 1].second)	sum ++;

//	cout << sum << "\n";
	for (int i = 0; i < V.size(); i ++)
	{
		if (i == V.size() - 1)
			cout << V[i].first << "\n";
		else
			cout << V[i].first << " ";
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}