#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXX = 100005;

ll N, frek[MAXX], pref[MAXX], res;

void read ()
{
	string subs;
	cin >> subs;
	
	cin >> N;
	for (int i = 1; i <= N; i ++)
	{
		int a;
		
		cin >> a;
		frek[a] ++;
	}
}

void solve ()
{
	res = 0;
	
	for (int i = 1; i <= MAXX - 5; i ++)
		pref[i] = pref[i - 1] + frek[i];
		
	for (int i = 2; i < MAXX - 5; i ++)
		res += pref[i - 1] * frek[i] * (pref[MAXX - 5] - pref[i]);

	cout << res << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read ();
	solve ();
	
return 0;
}
