#include<bits/stdc++.h>
using namespace std;

int N, K, arr[15];
bool dist[90000000];

struct lol
{
	int angka, jarak;
};

void tukar(int posisi)
{
	int depan, belakang;
	depan = posisi;			belakang = posisi + K - 1;
	
	while (depan <= belakang)
	{
		swap(arr[depan], arr[belakang]);
		depan ++;				belakang --;
	}
}

int gabung ()
{
	int hasil = 0;
	for (int i = 1; i <= N; i ++)
		hasil = hasil * 10 + arr[i];
return hasil;
}

void pisah (int sekarang)		// 54321 -> 5 4 3 2 1
{
	for (int i = N; i>=1; i --)
	{
		arr[i] = sekarang % 10;
		sekarang /=10;
	}
}

bool terurut (int angka)
{
	string sekarang = to_string(angka);
	
	for (int i = 0; i < sekarang.length(); i++)
		if (sekarang[i] - '0' != i + 1)
			return false;
return true;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 1; i <= N ;i ++)
		cin >> arr[i];
	cin >> K;
	
	int sekarang = 0;
	for (int i = 1; i <= N; i ++)
		sekarang = (sekarang * 10) + arr[i];
//	cout << sekarang << "\n";

	queue<lol> q;
	q.push({sekarang, 0});
	
	memset(dist, false, sizeof(dist));
	while (!q.empty())
	{
		lol now = q.front();			q.pop();
		
		if (dist[now.angka] == true)		continue;
		
//		cout << now.angka << "\n";
		if (terurut(now.angka))
		{
			cout << now.jarak << "\n";
			return 0;
		}
		
		dist[now.angka] = true;
		pisah(now.angka);
		for (int i = 1; i <= N - K + 1; i ++)
		{
			tukar(i);		// Prosedur menukar i sampai i + K -1
			int selanjutnya = gabung();		// gabung array yang terpisah
			q.push({selanjutnya, now.jarak + 1});
			tukar(i);
		}
	}
	cout << "-1\n";
return 0;
}