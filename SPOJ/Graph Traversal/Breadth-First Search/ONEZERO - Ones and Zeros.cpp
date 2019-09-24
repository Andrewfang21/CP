#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL Val;

typedef pair<string, LL> ii;

int main ()
{
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC --)
	{
		cin >> Val;

		queue <ii> q;
		q.push(make_pair("1", 1));

		while (!q.empty())
		{
			ii u = q.front();			q.pop();

			if (u.second % Val == 0)
			{
				cout << u.first << "\n";
				break;
			}

			LL nexts = u.second % Val;

			q.push(make_pair(u.first + "0", nexts * 10));
			q.push(make_pair(u.first + "1", nexts * 10 + 1));			
		}
	}
return 0;
}