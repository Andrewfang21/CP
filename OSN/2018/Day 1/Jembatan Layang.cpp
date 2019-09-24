#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXX = 100005, MOD = 1000000007;

int N, G;
ll fak[MAXX], K[MAXX], A_atas[MAXX], A_sama[MAXX], A_bawah[MAXX], B_atas[MAXX], B_sama[MAXX], B_bawah[MAXX];

void precompute ()
{
	fak[0] = 1;
	
	for (int i = 1; i <= MAXX - 3; i ++)
		fak[i] = (fak[i - 1] * i % MOD) % MOD;
}

void read ()
{
	string subs;
	cin >> subs;
	
	cin >> N >> G;
	for (int i = 1; i <= G; i ++)
		cin >> K[i];
		
	int A, B;
	for (int i = 1; i <= N; i ++)
	{
		cin >> A;
		
		if (K[A] > i)		// Lantai di bawah jembatan
			A_bawah[A] ++;
		if (K[A] == i)
			A_sama[A] ++;
		if (K[A] < i)
			A_atas[A] ++;
	}
	
	for (int i = 1; i <= N; i ++)
	{
		cin >> B;
		
		if (K[B] > i)
			B_bawah[B] ++;
		if (K[B] == i)
			B_sama[B] ++;
		if (K[B] < i)
			B_atas[B] ++;
	}
}

bool cek (int i)
{
	if (A_atas[i] + A_sama[i] + A_bawah[i] > B_atas[i] + B_sama[i] + B_bawah[i])	return true;
	
	if (A_sama[i] == 0 && B_sama[i] == 0)
	{
		if (A_atas[i] != B_bawah[i] || A_bawah[i] != B_atas[i])
			return true;
	}
	
	if (A_sama[i] == 1 && B_sama[i] == 1)
	{
		if (abs(A_atas[i] - B_bawah[i]) >= 2 || abs(A_bawah[i] - B_atas[i]) >=2)
			return true;
	}
return false;
}

void solve ()
{
	precompute ();
	
	ll res = 1, cnt;
	for (int i = 1; i <= G; i ++)
	{
		if (cek(i))
		{
			res = 0;
			break;
		}
		
		cnt = 0;
		if (A_sama[i] == 1)
		{
			if (B_sama[i] == 1)
			{
				// Pasangin A_sama[i] ke B_sama[i]
				if (A_bawah[i] == B_atas[i] && A_atas[i] == B_bawah[i])
					cnt += (fak[A_bawah[i]] * fak[A_atas[i]]) % MOD;				
			}
			
			// Pasangain A_sama[i] ke B_atas[i]
			if (B_atas[i] > 0)
			{
				if (A_sama[i] + A_bawah[i] == B_atas[i] + B_sama[i] && A_atas[i] == B_bawah[i] ||
					A_sama[i] + A_bawah[i] == B_atas[i] && A_atas[i] == B_sama[i] + B_bawah[i]) 
						cnt += ( (B_atas[i] * fak[A_bawah[i]]) % MOD * fak[A_atas[i]]) % MOD;	
			}
			
			// Pasangin A_sama[i] ke B_bawah[i]
			if (B_bawah[i] > 0)
			{
				if (A_sama[i] + A_atas[i] == B_bawah[i] + B_sama[i] && A_bawah[i] == B_atas[i] ||
					A_sama[i] + A_atas[i] == B_bawah[i] && A_bawah[i] == B_atas[i] + B_sama[i])
					cnt += ( (B_bawah[i] * fak[A_atas[i]]) % MOD * fak[A_bawah[i]]) % MOD; 	
			}	
		}
		else
		{
			if (B_sama[i] == 1)
			{
				if (A_atas[i] == B_bawah[i] + B_sama[i] && A_bawah[i] == B_atas[i])
					cnt += (fak[A_atas[i]] * fak[A_bawah[i]]) % MOD;
				
				if (A_bawah[i] == B_atas[i] + B_sama[i] && A_atas[i] == B_bawah[i])
					cnt += (fak[A_bawah[i]] * fak[A_atas[i]]) % MOD;
			}
			else
			{
				if (A_atas[i] == B_bawah[i] && A_bawah[i] == B_atas[i])
					cnt += (fak[A_atas[i]] * fak[A_bawah[i]]) % MOD;
			}
		}
//		cout << i << " " << cnt << "\n";
		res = (res * cnt) % MOD;
	}
	cout << res << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read ();
	solve ();
	
return 0;
}
