#include<bits/stdc++.h>
using namespace std;
struct lol
{
	int start,end;
};

bool accompare(lol a,lol b) 
{
	return a.end<b.end;
}
int main()
{
	int N,i,a,b,hitung=0;
	scanf("%d",&N);
	lol activity[N+5];
	
	for (i=0;i<N;i++)
	{
		scanf("%d %d",&a,&b);
		activity[i].start=a;
		activity[i].end=a+b;
	}
	sort(activity,activity+N,accompare);
	
	int mulai=1;
	for (i=0;i<N;i++)
	{
		if (activity[i].start>=mulai)
		{
			hitung++;
			mulai=activity[i].end;
		}
	}
	printf("%d\n",hitung);
return 0;	
}
