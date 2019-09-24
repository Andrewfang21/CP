#include<bits/stdc++.h>
#define mod 1000000
#define ull unsigned long long
using namespace std;
ull A,B,temp,x,hasil,hitung;
bool boo;

ull pangkat (ull a, ull b)
{
	ull res;
	if (b==0) return 1; else
	if (b==1) 
	{
		return (a%mod)%mod;
	}
	else
	if (b%2==0)
	{
		res=pangkat(a,b/2)%mod;
		return ((res%mod)*(res%mod)%mod)%mod;
	} else
	if (b%2==1)
	{
		res=pangkat(a,b/2)%mod;
		return (a*((res%mod)*(res%mod)%mod)%mod)%mod;
	}
}
int main()
{
	scanf("%64lld %64lld",&A,&B);
	
	hasil=pangkat(A,B);
	temp=1;	hitung=0;
	
	
	while (hitung<B)
	{
		temp*=A;
		hitung++;
		if (temp>=1000000)
		{
			boo=true;
			break;
		}
	}	
	if (boo)
	{
		if (hasil<10) cout<<"00000"; else
		if (hasil<100) cout<<"0000"; else
		if (hasil<1000) cout<<"000"; else
		if (hasil<10000) cout<<"00"; else
		if (hasil<100000) cout<<"0";
	}
	cout<<hasil<<"\n";
return 0;	
}