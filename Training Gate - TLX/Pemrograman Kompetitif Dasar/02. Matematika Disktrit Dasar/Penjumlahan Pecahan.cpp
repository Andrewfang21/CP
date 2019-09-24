#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull FPB(ull a,ull b)
{
	ull c;
	if (a==b) return a; else
	if (a%b==0) return b; else
	if (b%a==0) return a; else
	{
	while (a%b!=0)
	{
		c=a%b;
		a=b;
		b=c;
		if (a%b==0)
		{
			return b;
			break;
		}
	}
	}
}
int main()
{
	ull temp1,temp2,a,b,c,d,KPK,pembilang,penyebut,temp;
	cin>>a>>b;
	cin>>c>>d;
	
	if ((a==0)&&(c==0)) cout<<0<<"\n"; else
	{
	KPK=(b/FPB(b,d)); KPK*=d;
	temp1=a;
	a=(KPK/b); a*=temp1;
	temp1=c;
	c=(KPK/d); c*=temp1;
	b=d=KPK;
	pembilang=a+c; 
	penyebut=KPK;
	
	temp=FPB(pembilang,penyebut);
	pembilang/=temp;	penyebut/=temp;
	
	cout<<pembilang<<" "<<penyebut<<"\n";
	}
}
