#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,i,jumlah,bagi,sisa;
	cin>>N;
	int bebek[N+5],grup[N+5],kel[N+5],sum[N+5];
	
	for (i=0;i<N;i++)
		cin>>bebek[i];
		
	cin>>jumlah;
	bagi=N/jumlah;
	sisa=N%jumlah;
	
	sort(bebek,bebek+N);
		
	for (i=0;i<jumlah;i++)
		grup[i]=bagi;
		
	for (i=0;i<sisa;i++)
		grup[i]++;
			
	bool bisa=false,temp;
	
	while(!bisa)
	{
		sum[0]=grup[0]-1;
		for (i=1;i<jumlah;i++)
			sum[i]=sum[i-1]+grup[i];
	
		for (i=0;i<jumlah;i++)
			kel[i]=bebek[sum[i]]+1;
	
		temp=false;
		for (i=0;i<jumlah-1;i++)
		{
			if (kel[i]>bebek[sum[i]+1]) temp=true; 
		}
		if (!temp) break; else
			next_permutation(grup,grup+jumlah);
	}
	for (i=0;i<jumlah-1;i++)
		if (i==jumlah-2) cout<<kel[i]<<"\n"; else cout<<kel[i]<<" ";
return 0;			
}
