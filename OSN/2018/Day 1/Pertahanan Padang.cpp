// Not AC yet

#include<bits/stdc++.h>
using namespace std;

int A, B, Q;

void read ()
{
	string subs;
	cin >> subs;
	
	cin >> A >> B >> Q;
}

string rec (int ganjil, int genap, string s)
{
	if (ganjil > A || genap > B)
		return "/";
	if (ganjil == A && genap == B)
		return s;
				
	string curr_s = max(rec(ganjil + genap + 1, genap, s + "1"),
						rec(ganjil, genap + ganjil, s + "0"));
												
return curr_s;
}

void solve ()
{
	string s = rec(1, 0, "1");
	
	if (s[0] == '1')
	{
		cout << "MUNGKIN\n";
		cout << s << "\n";
	
		while (Q --)
		{
			int l, r;
			cin >> l >> r;
			
			if (r > s.length() - 1)
				cout << "DI LUAR BATAS\n";
			else
				cout << s.substr(l, r - l + 1) << "\n";
		}
	}
	else
		cout << "TIDAK MUNGKIN\n";
}

int main ()
{
	
	read ();
	solve ();
	
return 0;
}
