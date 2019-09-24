#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define sec second
#define ll long long
using namespace std;

const ll MAXX = 305;

ll M, N, arr[MAXX][MAXX];
deque<ll> v;

void print();

void read()
{
	string subs;
	getline(cin, subs);
	
	cin >> N;
	
	M = N * (N + 1) / 2;
	for (ll i=1;i<=M;i++)
	{
		ll a;
		
		cin >> a;
		v.push_back(a);
	}
}

void solve()
{
	memset(arr, -1, sizeof(arr));
	sort(v.begin(), v.end());

	int curr_pos = N;
	
	while (curr_pos > 2)
	{
		arr[curr_pos][2] = v[0];
		arr[curr_pos][1] = v[1];
		
		v.pop_front();			v.pop_front();
		curr_pos --;
	}
	curr_pos = N;
	
	while (curr_pos >= 3)
	{
		int i = v.size() - 1;
		
		arr[curr_pos][3] = v[i];
		v.pop_back();
		curr_pos --;
	}
		
	if (N > 1)
	{	
		ll diff, curr;
		pair<int, int> choose;
		
		diff = LLONG_MAX;
		for (int i=1;i<v.size();i++)
		{
			curr = v[i] - v[i-1];
			
			if (curr < diff)
			{
				diff = curr;
				choose = mp(i, i-1);
			}
		}
			
		arr[2][1] = max(v[choose.fi], v[choose.sec]);
		arr[2][2] = min(v[choose.fi], v[choose.sec]);
		
		v[choose.fi] = v[choose.sec] = -1;
	}
	
	for (int i=1;i<=N;i++)
		for (int j=1;j<=i;j++)
		{
			if (arr[i][j] == -1 && !v.empty())
			{
				if (v[0] == -1)
				{
					while (true)
					{
						if (v[0] == -1)
							v.pop_front();
						else
							break;
					}
				}
				
				arr[i][j] = v[0];
				v.pop_front();
			}
		}
	
//	ll res_1, res_2;
//	
//	res_1 = res_2 = 0;
//	for (int i=1;i<=N;i++)
//		res_1 += arr[i][1];
//	for (int i=3;i<=N;i++)
//		res_2 += arr[i][3];
//	res_2 += (arr[1][1] + arr[2][2]);
//	
//	cout<<res_1<<" "<<res_2<<"\n";
}

void print()
{	
	for (ll i=1;i<=N;i++)
		for (ll j=1;j<=i;j++)
			if (j == i)
				cout<<arr[i][j]<<"\n";
			else
				cout<<arr[i][j]<<" ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	read();
	solve();
	print();

return 0;
}
