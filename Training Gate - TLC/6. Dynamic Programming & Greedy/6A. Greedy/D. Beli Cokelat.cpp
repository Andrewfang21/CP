#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
struct lol
{
	ull harga,bebek;
};

bool accompare(lol lhs, lol rhs)
{
	if (lhs.harga==rhs.harga) return lhs.bebek>rhs.bebek; else
	return lhs.harga<rhs.harga;
}

int main()
{
	ull N,D,i,sum,u;
	scanf("%64lld %64lld",&N,&D);
	lol data[N+5];
	for (i=0;i<N;i++)
		scanf("%64lld %64lld",&data[i].harga,&data[i].bebek);
		
	sort(data,data+N,accompare);	
	sum=0;
	for (i=0;i<N;i++)
	{
		if ((D/data[i].harga)>=data[i].bebek)
		{
			D=D-(data[i].harga*data[i].bebek);
			sum+=data[i].bebek;
		} 
		else
		{
			u=(D/data[i].harga);
			D=D-u*data[i].harga;
			sum+=u;
		}
	
	}
	cout<<sum<<"\n";
return 0;	
}