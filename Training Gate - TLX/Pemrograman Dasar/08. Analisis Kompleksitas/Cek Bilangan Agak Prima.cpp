#include<bits/stdc++.h>
using namespace std;
int i,j,N,k,hitung,save;

int main()
{
	cin>>N;
	for (i=1;i<=N;i++)
	{
		cin>>j;
		hitung=0;
		save=sqrt(j);
		for (k=2;k<=save;k++)
		{
			if((k*k)==j)
			{
				hitung++;
			}
			else if ((j%k)==0) hitung+=2;
		}
		if (hitung>2) cout<<"BUKAN\n"; else cout<<"YA\n";
	}
}
