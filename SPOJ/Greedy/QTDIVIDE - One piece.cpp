#include<bits/stdc++.h>
#define mp make_pair
#define sec second
#define fi first
#define ll long long
using namespace std;

const ll MAXX = 500005;

ll N, sum, curr_res;
bool taken[MAXX];

vector<ll> ans_1, ans_2;

typedef pair<ll, ll> ii;

struct lol
{
	ll quality, price, id;
} v[MAXX];

bool cmp (lol lhs, lol rhs)
{
	return lhs.quality > rhs.quality;
}

void read ()
{
	cin >> N;
	for (ll i=1;i<=N;i++)
		cin >> v[i].quality;
	
	for (ll i=1;i<=N;i++)
	{
		cin >> v[i].price;
		v[i].id = i;
		
		sum += v[i].price;
	}	
}

void solve()
{
	memset(taken, false, sizeof(taken));
	sort(v+1, v+N+1, cmp);
	
	priority_queue <ii, vector<ii>, greater<ii> > q;
	
	curr_res = 0;
	for (ll i=1;i<=N;i++)
	{
		q.push(mp(v[i].price, v[i].id));
		
		if (i % 2 == 1)
		{
			ii u = q.top();			q.pop();
			
			curr_res += u.fi;
			taken[u.sec] = true;
			
			ans_1.push_back(u.sec);
		}
	}
	
//	for (ll i=1;i<=N;i++)
//		cout << v[i].id << "    " << v[i].quality << "  " << v[i].price << "\n";

	for (ll i=1;i<=N;i++)
		if (!taken[v[i].id])		ans_2.push_back(v[i].id);
	
	sum = sum - curr_res;
}

void print ()
{
	cout << sum << "\n";
	for (ll i=0;i<ans_1.size();i++)
		cout << ans_1[i] << " " << ans_2[i] << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);
	read();
	solve();
	print();
	
return 0;
}
