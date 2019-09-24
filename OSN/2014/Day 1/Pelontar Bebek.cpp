#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int N;
int dp[5][1805];
string subs;
priority_queue<int, vector<int>, greater<int> > q[1805];

struct lol
{
	int sudut, kecepatan;
};

vector<lol> v, temp;

bool cmp (lol lhs, lol rhs)
{
	if (lhs.sudut == rhs.sudut)
		return lhs.kecepatan > rhs.kecepatan;

return lhs.sudut < rhs.sudut;
}

double toRadian(double a)
{
return (a * acos(-1)) / 180;
}

void debug ()
{
	for (int i=1;i<v.size();i++)
		for (int j=1;j<=1800;j++)
			if (dp[i][j] != -1)
				cout<<i<<" "<<j<<"   "<<dp[i][j]<<"\n";
}

void read ()
{
	cin >> subs;	
	cin >> N;
	
	for (int i=1;i<=N;i++)
	{
		int a, b;
		
		cin >> a >> b;		//kecepatan, sudut
		q[b].push(a);
		
		int max_freq = (1800 - 1) / b + 1;
		
		if (q[b].size() > max_freq)
			q[b].pop();
	}
	
	for (int i=1;i<=1800;i++)
	{
		if (!q[i].empty())
		{
			while (!q[i].empty())
			{
				int u = q[i].top();
				v.pb({i, u});
				q[i].pop();
			}
		}
	}
	v.pb({-1, -1});
	
	sort(v.begin(), v.end(), cmp);
}

void solve ()
{	
	memset(dp, -1, sizeof(dp));
	
//	debug ();
	
	dp[0][0] = dp[1][0] = 0;
		
	for (int pos=1;pos<v.size();pos++)
		for (int deg=1;deg<=1800;deg++)
		{
			dp[pos & 1][deg] = dp[(pos + 1) & 1][deg];
			
			if (deg - v[pos].sudut >= 0)
			{
				if (dp[(pos + 1 ) & 1][deg - v[pos].sudut] != -1)
					dp[pos & 1][deg] = max(dp[pos & 1][deg],
								       max(dp[(pos + 1) & 1][deg - v[pos].sudut], v[pos].kecepatan));
			}
		}
//	debug();	
}

void print ()
{
	int curr_speed;
	double curr_ans, res;
	
	res = -1;
	
	for (int i=1;i<=1800;i++)
	{
		curr_speed = dp[(v.size() + 1) & 1 ][i];
		
		if (curr_speed == -1)
			continue;
		
		curr_ans = 	abs(2 * curr_speed * curr_speed * sin(toRadian(i/10.0)) * cos(toRadian(i/10.0)) * 9.80);
		
//		cout << i << "   " << curr_speed << "    " << curr_ans << "\n";
		
		if (curr_ans > res)
			res = curr_ans;
	}	
	cout << setprecision(8) << fixed << res << "\n";	
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read();
	solve();
	print();
	
return 0;
}
