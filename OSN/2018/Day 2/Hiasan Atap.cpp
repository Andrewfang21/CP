#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXX = 100005;

ll pref[MAXX][5];
ll N, K;
string s;

void read ()
{
	string subs;
	cin >> subs;
	
	cin >> s;
}

void solve ()
{
	for (int i = 0; i < s.length(); i ++)
	{
		if (i > 0)
		{
			pref[i][0] = pref[i - 1][0];
			pref[i][1] = pref[i - 1][1];
		}
		pref[i][s[i] - 'A'] ++;
	}

//	for (int i = 0; i < s.length(); i ++)
//		cout << pref[i][0] << " " << pref[i][1] << "\n";
	
	ll A, B, Q;
	A = pref[s.length() - 1][0];					B = pref[s.length() - 1][1];

	cin >> K >> Q;
	
	N = K * s.length() + 1;
	
	while (Q --)
	{		
		ll Li, Ri;
		cin >> Li >> Ri;
		
		// Cek Cycle ke berapa
		ll kiri, kanan, curr_cycle, cycle = 0, curr_left, curr_right, height = 0;
		
		kiri = 0;			kanan = K;
		
		while (kiri <= kanan)
		{
			curr_cycle = (kiri + kanan) / 2;
			
			curr_left = curr_cycle * B + 1;			curr_right = N - curr_cycle * A;
			
	//		cout << curr_cycle << "   " << curr_left << " " << curr_right << "\n";
			
			if (Li <= curr_right && Ri >= curr_left)
			{
				cycle = curr_cycle;
				kiri = curr_cycle + 1;
			}
			else
				kanan = curr_cycle - 1;
		}
		
		if (cycle != K)
		{	
			// Cek Ketinggian
			ll temp_A, temp_B, pos;
			kiri = 0;			kanan = s.length() - 1;
			
			while (kiri <= kanan)
			{
				pos = (kiri + kanan) / 2;
				
				if (pos != 0)
				{
					temp_A = pref[pos - 1][0];
					temp_B = pref[pos - 1][1];
				}
				else
					temp_A = temp_B = 0;
				
				curr_left = cycle * B + temp_B + 1;				curr_right = N - (cycle * A + temp_A);
				
				if (Li <= curr_right && Ri >= curr_left)	
				{
					height = pos;
					kiri = pos + 1;	
				}
				else
					kanan = pos - 1;
			}
		}
		
		ll res = cycle * s.length() + height + 1;
		cout << res << "\n";
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read ();
	solve ();
	
return 0;
}
