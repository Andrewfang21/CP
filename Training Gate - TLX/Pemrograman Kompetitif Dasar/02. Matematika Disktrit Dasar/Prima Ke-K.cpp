#include<bits/stdc++.h>
using namespace std;
bool isprime[1000025];
int bil[1000025];
int main()
{
	int N,i,a,p,temp=1,Q;
	N=1000000;
	p=2;
	isprime[1]=true;
	while((p*p)<=N)
	{
		i=2;
		while((p*i)<=N)
		{
			isprime[i*p]=true;
			i++;
		}
		p++;
		while (isprime[p]) p++;
	}
	for (i=1;i<=N;i++)
	{
		if (!isprime[i])
		{
			bil[temp]=i;
			temp++;
		}
	}
	cin>>Q;
	for (i=1;i<=Q;i++)
	{
		cin>>a;
		cout<<bil[a]<<"\n";
	}
return 0;	
}
