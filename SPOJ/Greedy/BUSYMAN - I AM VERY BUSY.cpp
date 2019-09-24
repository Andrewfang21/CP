#include<bits/stdc++.h>
using namespace std;
struct lol
{
	int start,finish;
};

bool accompare(lol lhs, lol rhs)
{
	return lhs.finish<rhs.finish;
}
int main()
{
	int TC,i,N,res,now;
	cin>>TC;
	while (TC--)
	{
		cin>>N;
		lol act[N+5];
		for (i=0;i<N;i++)
			cin>>act[i].start>>act[i].finish;
		
		sort(act,act+N,accompare);
		now=act[0].finish;
		res=1;
		
		for (i=1;i<N;i++)
		{
			if (act[i].start>=now)
			{
				now=act[i].finish;
				res++;
			}
		}
		cout<<res<<"\n";
	}
return 0;
}
