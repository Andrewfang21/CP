#include<bits/stdc++.h>
using namespace std;
long long M,N,i,up,low,kiri,kanan,tengah,sum;

int main()
{
	cin>>M>>N;
	long long telur[M+5];
	for (i=1;i<=M;i++)
		cin>>telur[i];
		
	up=low=INT_MIN;
	kiri=1;	kanan=LONG_MAX;
	while (kiri<=kanan)
	{
		tengah=(kiri+kanan)/2;
		sum=0;
		for (i=1;i<=M;i++)
			sum+=(tengah/telur[i]);
		if (sum<=N)
		{
			up=tengah;
			kiri=tengah+1;
		}
		else
			kanan=tengah-1; 		
	}
	kiri=1;	kanan=LONG_MAX;
	while (kiri<=kanan)
	{
		tengah=(kiri+kanan)/2;
		sum=0;
		for (i=1;i<=M;i++)
			sum+=(tengah/telur[i]);
	
		if (sum>=N)
		{
			low=tengah;
			kanan=tengah-1;
		}
		else
			kiri=tengah+1;	
	}
	if ((up>0)&&(low>0)) cout<<up-low+1<<"\n"; else cout<<0<<"\n";
return 0;			
}
