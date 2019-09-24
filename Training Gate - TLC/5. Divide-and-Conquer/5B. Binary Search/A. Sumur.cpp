#include<bits/stdc++.h>
using namespace std;

int petak[1005][1005], R, C;

double cek (double ketinggian)
{
	double jawaban_sementara = 0;
	
	for (int i=1;i<=R;i++)
		for (int j=1;j<=C;j++)
		{
			if (ketinggian > petak[i][j])
				jawaban_sementara += (ketinggian - petak[i][j]);			
		}
return jawaban_sementara; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	double V, kiri, kanan, MAXX = pow(10,9);
	cin >> R >> C >> V;
	
	for (int i=1;i<=R;i++)
		for (int j=1;j<=C;j++)
			cin >> petak[i][j];
			
	kiri = 0;			kanan = MAXX;
	
	double mid;
	for (int iterasi = 1;iterasi <= 50; iterasi ++)
	{
		mid = (kiri + kanan) / 2;  // Tes ketinggian air
		
		double temp = cek(mid);		// Fungsi cek itu untuk mengembalikan Volume Air
		
		if (temp > V)
			kanan = mid;
		else
		if (temp < V)
			kiri = mid;
		else
			break;
	}	
	cout << setprecision(3) << fixed << mid << "\n";
return 0;	
}