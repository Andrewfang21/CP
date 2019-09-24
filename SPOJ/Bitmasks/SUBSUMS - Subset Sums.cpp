#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 20;

ll N, A, B, bound_1, bound_2;
ll X[n], Y[n];

vector<ll> L, R;

void read ()
{
	cin >> N >> A >> B;
	
	bound_1 = N / 2;		bound_2 = N - bound_1;
	
	for (ll i = 0; i < bound_1; i ++)
		cin >> X[i];
		
	for (ll i = 0; i < bound_2; i ++)
		cin >> Y[i];
}

ll binser (ll x, ll y)
{
	ll up, low, kiri, kanan, mid;
	
	up = low = -1;
	
	kiri = 0;			kanan = R.size() - 1;
	while (kiri <= kanan)
	{
		mid = (kiri + kanan) / 2;
		
		if (R[mid] >= x)
		{
			low = mid;
			kanan = mid - 1;
		}
		else
			kiri = mid + 1;
	}
	
	kiri = 0;			kanan = R.size() - 1;	
	while (kiri <= kanan)
	{
		mid = (kiri + kanan) / 2;
		
		if (R[mid] <= y)
		{
			up = mid;
			kiri = mid + 1;
		}
		else
			kanan = mid - 1;
	}
	
	if (up >= 0 && low >= 0 && up - low + 1 > 0)
		return up - low + 1;
return 0;
}

void solve ()
{
	for (ll i = 0; i < (1 << bound_1); i ++)
	{
		ll sum = 0, mask;
		bool exist = false;
		
		for (ll j = 0; j < bound_1; j ++)
		{
			mask = i & (1 << j);
			
			if (mask != 0)
			{
				sum += X[j];		
				exist = true;
			}
		}
		if (exist)
			L.push_back(sum);
	}
	
	for (ll i = 0; i < (1 << bound_2); i ++)
	{
		ll sum = 0, mask;
		bool exist = false;
		
		for (ll j = 0; j < bound_2; j ++)
		{
			mask = i & (1 << j);
			
			if (mask != 0)
			{
				sum += Y[j];
				exist = true;
			}
		}
		if (exist)
			R.push_back(sum);
	}
	
	sort(L.begin(), L.end());			sort(R.begin(), R.end());
	
	ll res = 0;
	for (ll i = 0; i < L.size(); i ++)
	{
		ll x, y;
		
		x = A - L[i];			y = B - L[i];
		
		ll frek = binser(x, y);
		
		res += frek;
			
		if (L[i] >= A && L[i] <= B)
			res ++;
	}
	
	for (ll i = 0; i < R.size(); i ++)
		if (R[i] >= A && R[i] <= B)
			res ++;
	
	if (A <= 0 && B >= 0)
		res ++;
		
	cout << res << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read ();
	solve ();
	
return 0;
}
