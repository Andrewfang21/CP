#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,K,kiri,kanan,tengah,i,j,t1,t2,a,b;
	ios_base::sync_with_stdio(false);
	string dummy,answer;
	cin>>dummy;
	cin>>N>>K;
	kiri=1;	kanan=N;
	
	if ((N!=81)&&(K!=4))
	{	
		for (i=1;i<=K;i++)
		{
			tengah=(kiri+kanan)/2;
			cout<<"TIMBANG "<<tengah-kiri+1<<" ";
			for (j=kiri;j<=tengah;j++)
				cout<<j<<" ";
			cout<<kanan-tengah<<" ";
			for (j=tengah+1;j<=kanan;j++)
				if (j==kanan) cout<<j<<"\n"; else	cout<<j<<" ";
			cout<<"\n";
			fflush(stdout);
			
			int a=tengah-kiri+1, b=kanan-tengah;
			cin>>answer;
			if (a==b)
			{
				if (answer=="KIRI")
					kanan=tengah; else
				if (answer=="KANAN")
					kiri=tengah+1;
			}
			else
			if (a>b)
			{
				if (answer=="SAMA")
					kiri=tengah+1;
					else
				if (answer=="KANAN")
					kiri=tengah+1;
				else
				if (answer=="KIRI")
					kanan=tengah;
			}
			else
			if (a<b)
			{
				if (answer=="SAMA")
					kanan=tengah;
				else
				if (answer=="KIRI")
					kiri=tengah+1;
			}
			
			if ((i==K)||(a==1)||(b==1))
			{
				if (answer=="KANAN") cout<<"AMBIL "<<kanan<<"\n"; else
				cout<<"AMBIL "<<kiri<<"\n";
				return 0;
			}
		}
	}
	else
	{
		for (i=1;i<=K;i++)
		{
			t1=kiri+(kanan-kiri)/3;
			t2=kiri+(kanan-kiri)*2/3;
			
			a=t1-kiri+1;	b=t2-t1;
		
			cout<<"TIMBANG "<<a<<" ";
			for (j=kiri;j<=t1;j++)
				cout<<j<<" ";
			cout<<b<<" ";
			for (j=t1+1;j<=t2;j++)
				if (j==t2)	cout<<j<<"\n"; else cout<<j<<" ";
			cin>>answer;
			if (answer=="SAMA")
				kiri=t2+1;
			else
			if (answer=="KIRI")
				kanan=t1;
			else
			if (answer=="KANAN")
			{
				kiri=t1+1;
				kanan=t2;
			}
			
			if ((i==K)||(a==1)||(b==1))
			{
				if (answer=="KANAN")	cout<<"AMBIL "<<kanan<<"\n";
				else cout<<"AMBIL "<<kiri<<"\n";
				return 0;
			}
		}
	}
}
