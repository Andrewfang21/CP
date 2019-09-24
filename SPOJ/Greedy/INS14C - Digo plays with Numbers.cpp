#include<bits/stdc++.h>
using namespace std;

const int n = 1005;

int M, N, K;
bool can[n];
char A[n];

deque<int> q[2];

void read ()
{
	cin >> N >> K;
	
	M = N;
	for (int i = 1; i <= N; i ++)
		{
			cin >> A[i];

			q[A[i] - '0'].push_back(i);
			can[i] = true;
		}
}

void work ()
{
	int idx, turn = 0;

	while (N > K)
	{
		if (turn == 0)
		{
			if (!q[1].empty())
			{
				idx = q[1].front();			q[1].pop_front();
				can[idx] = false;
			}
			else
			{
				idx = q[0].back();			q[0].pop_back();
				can[idx] = false;
			}
			N --;				turn = 1;
		}
		else
		{
			if (!q[0].empty())
			{
				idx = q[0].front();			q[0].pop_front();
				can[idx] = false;
			}
			else
			{
				idx = q[1].back();			q[1].pop_back();
				can[idx] = false;
			}
			N --;				turn = 0;
		}
	}

	for (int i = 1; i <= M; i ++)
		if (can[i])
			cout << A[i];
	cout << "\n";
}

void reset ()
{
	while (!q[0].empty())		q[0].pop_front();
	while (!q[1].empty())		q[1].pop_front();		
}

int main ()
{
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC --)
	{
		read ();
		work ();
		reset ();	
	}

return 0;
}