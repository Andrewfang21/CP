#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int n = 300005, k =25;

int N, K;
LL A[n], sum[k];

void read ()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i ++)
	{
		string S;

		cin >> S;
		A[i] = S.length();
	}
}

void work ()
{
	LL L, R, res = 0;

	for (int i = 1; i <= K + 1; i ++)
		sum[A[i]] ++;

	L = 1;				R = min(N, K + 1);

	while (L <= N)
	{
		sum[A[L]] --;

		res += sum[A[L]];
//		cout << L << "   " << sum[A[L]] << "\n";

		L ++;					
		if (R + 1 <= N)	
		{
			R ++;
			sum[A[R]] ++;		
		}
	}
	cout << res << "\n";
}


int main ()
{
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}