#include<bits/stdc++.h>
using namespace std;

const int MAXX = 15;

int N, S, sum, X, Y;
int P[MAXX], A[MAXX], B[MAXX];
bool same[MAXX];

struct state
{
	int sama, id;
};

vector<state> player;

bool cmp (state lhs, state rhs)
{
return lhs.sama > rhs.sama;
}

void read ()
{
	string subs;
	
	cin >> subs;
	
	cin >> N >> S;
	
	for (int i = 1; i <= N; i ++)
		cin >> P[i];
		
	cin >> X;
	for (int i = 1; i <= X; i ++)
		cin >> A[i];
		
	cin >> Y;
	for (int i = 1; i <= Y; i ++)
	{
		cin >> B[i];
		same[B[i]] = true;
	}
	
	for (int i = 1; i <= X; i ++)
	{
		bool take = 0;
		if (same[A[i]])
			take = 1;
		
		player.push_back({take, A[i]});
	}
}

void solve ()
{
	int ans;
	sort(player.begin(), player.end(), cmp);		// sort berdasarkan genap/ganjil
	
//	for (int i = 0; i < player.size(); i ++)
//		cout << player[i].sama << " " << player[i].tipe << "  " << player[i].id << "\n";
	
	for (int i = 0; i < player.size(); i ++)
	{
		int idx = player[i].id;
		
		while (P[idx] != 0)
		{
			cout << idx << endl;
			P[idx] --;
			
			cin >> ans;
			
			if (ans != 0)
				P[ans] --;
		}
	}
	
	if (ans == 0)
		cout << 0 << endl;
	else
	{
		while (ans != 0)
		{
			cout << 0 << endl;
			
			cin >> ans;
		}
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read ();
	solve ();
	
return 0;
}
