#include<bits/stdc++.h>
using namespace std;
int x,A,B,K,i,sum;

int main()
{
	cin>>A>>B>>K>>x;
	sum=abs(A*x+B);
	for (i=2;i<=K;i++)
	{
		sum=abs(A*sum+B);
	}
	cout<<sum<<"\n";
return 0;	
}
