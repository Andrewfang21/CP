#include<bits/stdc++.h>
using namespace std;
int N;
double cnt,volume;

struct lol
{
	double base,tinggi,panjang,lebar;
}arr[50005];

double check(double num)
{
	int temp;
	double res=0;
	for (temp=1;temp<=N;temp++)
	{
		if (num>arr[temp].base)
		{
			if (num<arr[temp].base+arr[temp].tinggi)
				res+=((num-arr[temp].base)*arr[temp].lebar*arr[temp].panjang);
			else
				res+=(arr[temp].tinggi*arr[temp].lebar*arr[temp].panjang);	
		}
		//cout<<temp<<" "<<res<<" "<<num<<"\n";
	}
return res;
}

double binser(double maks)
{
	double kiri,kanan,tengah;
	kiri=0;		kanan=maks;
	
	for (int j=1;j<=50;j++)
	{
		tengah=(kiri+kanan)/2;
		
		if (check(tengah)<volume)
		{
			kiri=tengah;
			//cout<<setprecision(2)<<fixed<<check(tengah)<<" "<<tengah<<"\n";
		}
		else
		{
			kanan=tengah;	
			//cout<<setprecision(2)<<fixed<<check(tengah)<<" "<<tengah<<"\n";
		}
	}
return tengah;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,i;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		double maks=-1,ans,cnt=0;
	
		for (i=1;i<=N;i++)
		{
			cin>>arr[i].base>>arr[i].tinggi>>arr[i].panjang>>arr[i].lebar;
			cnt+=(arr[i].panjang*arr[i].tinggi*arr[i].lebar);
	
			if (maks<arr[i].base+arr[i].tinggi)
				maks=arr[i].base+arr[i].tinggi;
		}
		cin>>volume;
		
		if (volume>cnt)
			cout<<"OVERFLOW\n";
		else
		{
			ans=binser(maks);
			cout<<setprecision(2)<<fixed<<ans<<"\n";
		}
	}
return 0;
}
