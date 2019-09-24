#include<bits/stdc++.h>
using namespace std;

int main()
{
	int TC,tc,a,b,N,temp;
	cin>>TC;
	
	for (tc=1;tc<=TC;tc++)
	{
		cin>>a>>b>>N;
		temp=__gcd(a,b);
		
		printf("Case %d: ",tc);
		if (N%temp==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
return 0;
}
