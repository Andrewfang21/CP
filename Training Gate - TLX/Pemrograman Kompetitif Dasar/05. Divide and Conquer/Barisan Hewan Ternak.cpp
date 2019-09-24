#include<bits/stdc++.h>
using namespace std;
bool found;

int main()
{
	int N,i,Q,dummy,kiri,kanan,tengah,up;
	cin>>N;
	int bebek[100005];
	
	for (i=1;i<=N;i++)
	{
		cin>>dummy;
		bebek[i]=bebek[i-1]+dummy;
	}
	int cari;
	cin>>Q;
	for (i=1;i<=Q;i++)
	{
		cin>>cari;
		kiri=1;	kanan=N;
		found=false;
		while(kiri<=kanan)
		{
			tengah=(kiri+kanan)/2;
			if (bebek[tengah]==cari)
			{
				found=true;
				break;
			}
			else
			if (bebek[tengah]<cari) kiri=tengah+1; else kanan=tengah-1; 
		}
		if (found) cout<<tengah<<"\n"; else cout<<kiri<<"\n";
	}
return 0;	
}
