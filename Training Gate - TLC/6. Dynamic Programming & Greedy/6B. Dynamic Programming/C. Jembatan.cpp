#include<bits/stdc++.h>
using namespace std;

int N, dp[105][105], atas[105], bawah[105];

int solve (int i, int j)
{
	if (i > N || j > N)
		return 0;
	if (dp[i][j] != -1)	
		return dp[i][j];
	
	int ans;
	
//	Kalau mau dihubungin ?
//	Bisa dihubungin jika apa?  ID kotanya sama
//	
	if (atas[i] == bawah[j])		// ID kota sama
	{
		ans = max(solve(i + 1, j + 1) + 1,			// Hubungin
				  solve(i + 1, j + 1));
	}
	else			// ID kota beda -> gak bisa dipasangkan
	{
		ans = max(solve(i + 1, j), solve(i, j + 1));
	}
return dp[i][j] = ans;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin >> N;
	
	for (int i = 1; i <= N; i ++)
		cin >> atas[i];
		
	for (int i = 1; i <= N; i ++)
		cin >> bawah[i];
		
	memset(dp, -1, sizeof(dp));
	
	int ans = solve(1, 1);		// Coba masangin dari kiri kota atas dan bawah
	cout << ans << "\n";
return 0;
}
