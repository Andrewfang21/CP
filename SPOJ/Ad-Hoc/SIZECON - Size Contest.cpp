#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,i,a,sum=0;
	cin>>N;
	for (i=1;i<=N;i++)
	{
		cin>>a;
		if (a>0)	sum+=a;
	}
	cout<<sum<<"\n";
return 0;
}
