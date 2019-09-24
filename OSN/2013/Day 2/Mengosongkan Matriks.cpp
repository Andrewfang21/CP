#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll N, M, count_zero, MOD = 1e9 + 7;

ll arr[25][25];

struct lol
{
	ll a, b;
	ll c;
};

vector<lol> v;

void debug ()
{
	for (ll i=1;i<=N;i++)
	{
		for (ll j=1;j<=M;j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void read ()
{
	string sub;
	getline(cin, sub);
	
	cin>>N>>M;
	
	count_zero = 0;
	for (ll i=1;i<=N;i++)
		for (ll j=1;j<=M;j++)
		{
			cin >> arr[i][j];
			
			if (arr[i][j] == 0)		count_zero++;
		}
//	cout << "\n";
}

ll pangkat (ll base, ll pow)
{
	if (pow == 0)		return 1;
	if (pow == 1)		return base;
	
	ll curr = pangkat(base, pow / 2) % MOD;
	
	if (pow % 2 == 0)
		return (curr % MOD * curr % MOD) % MOD;
	else
		return ((base % MOD * curr % MOD) % MOD * curr % MOD) % MOD;
}

ll cek (ll num, ll piv)
{
	ll kiri, kanan, mid, up, curr_num;
	
	kiri = 0;				kanan = 30;
	
	up = 0;
	while (kiri <= kanan)
	{
		mid = (kiri + kanan) / 2;
		
		curr_num = num * pangkat(2,mid);
		
		if (curr_num < piv)
		{
			up = mid;
			kiri = mid + 1;
		}
		else
		if (curr_num > piv)
			kanan = mid - 1;
		else
			return mid;
	}
return up;
}

bool all_same (ll curr_pos)
{
	for (ll i=2;i<=N;i++)
		if (arr[i][curr_pos] != arr[i-1][curr_pos])
			return false;
return true;
}

void multiply (ll curr_pos, ll K)
{
	for (ll i=1;i<=M;i++)
		arr[curr_pos][i] = (arr[curr_pos][i] % MOD * pangkat(2,K) % MOD) % MOD;
}

ll search ()
{
	ll cnt = 0;
	
	for (ll i=1;i<=N;i++)
		for (ll j=1;j<=M;j++)
			if (arr[i][j] == 0)		cnt++;
return cnt;
}

void solve ()
{
	ll total, curr_pos;
	
	curr_pos = 1;				total = N * M;
	
	while (count_zero < total)
	{
		ll cnt = 0;
		for (ll i=1;i<=N;i++)
			if (arr[i][curr_pos] == 0)		cnt++;
		
		if (cnt == N)
		{
			curr_pos++;
			continue;	
		}
		
		if (cnt < N && cnt != 0)
		{
			v.pb({1, curr_pos, 1});
			
			for (ll i=1;i<=N;i++)
				arr[i][curr_pos] += 1;
		}
		
		ll maks = -1;
		for (ll i=1;i<=N;i++)
			if (arr[i][curr_pos] > maks)
				maks = arr[i][curr_pos];
		
		for (ll i=1;i<=N;i++)
		{
			if (arr[i][curr_pos] < maks)
			{
				ll K = cek(arr[i][curr_pos], maks);
				
				if (K == 0)			continue;
				v.pb({3, i, K});
				
				multiply(i,K);
				
			}
		}
//		debug() ;
		
		if (all_same(curr_pos))
		{
			v.pb({2, curr_pos, arr[1][curr_pos]});
			for (ll i=1;i<=N;i++)
				arr[i][curr_pos] = 0;
			
			curr_pos ++;
		}
		else
		{
			ll mins = INT_MAX;
			for (ll i=1;i<=N;i++)
				if (arr[i][curr_pos] < mins)
					mins = arr[i][curr_pos];
			
			mins --;
			v.pb({2, curr_pos, mins});
			
			for (ll i=1;i<=N;i++)
				arr[i][curr_pos] -= mins;
		}
		
		count_zero = search();
//		debug();
//		break;
	}	
}

void print ()
{
	cout << v.size() << "\n";
	
	for (ll i=0;i<v.size();i++)
		cout << v[i].a << " " << v[i].b << " " << v[i].c << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read();
	solve();
	print();
	
	
return 0;
}
