#include<bits/stdc++.h>
#define ull long long
using namespace std;
ull a,b,c,N,result;

ull pangkat(ull a,ull b)
{
	ull res;
	if (b==0) return 1; else
	if (b==1) return a; else
	if (b%2==0)
	{
		res=pangkat(a,b/2);
		return ((res%N)*(res%N))%N; 
	} else
	if (b%2==1)
	{
		res=pangkat(a,b/2);
		return ((a%N)*(res%N)%N*(res%N)%N)%N;		
	}
}

int main()
{
	cin>>a>>b>>c>>N;
	result=pangkat(a,b)%N;
	if (c==0) result=1%N; else
	if (c==1) result=result%N; else
	{
		for (ull i=1;i<c;i++)
		{
			result=pangkat(result,b)%N;
		}
	}
	result+=1;
	cout<<result<<"\n";
return 0;	
}