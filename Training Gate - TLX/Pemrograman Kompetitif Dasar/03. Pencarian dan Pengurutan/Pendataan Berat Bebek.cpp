#include<bits/stdc++.h>
using namespace std;

map<int, int>BIT;

void update(int i)
{
	while (i<1000000005)
	{
		BIT[i]++;
		i+=(i & -i);
	}
}

int sum(int i)
{
	int res=0;
	
	while (i>0)
	{
		res+=BIT[i];
		i-=(i & -i);
	}
return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int N,Q,a,b;
	cin>>N;
	
	for (int i=1;i<=N;i++)
	{
		cin>>a;
		update(a);
	}
	
	cin>>Q;
	for (int i=1;i<=Q;i++)
	{
		cin>>a>>b;
	
		cout<<sum(b)-sum(a)<<"\n";
	}
return 0;
}
