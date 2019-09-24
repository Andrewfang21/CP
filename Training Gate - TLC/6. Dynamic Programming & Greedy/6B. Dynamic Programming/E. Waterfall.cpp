#include<bits/stdc++.h>
using namespace std;
int V,H,N,i,temp,kiri[510000],kanan[510000],v1,h1,v2,h2;
long long pointer[5100][5100],ans,rec[5100][5100];
bool memo[5100][5100];

long long waterfall(int ver, int hor)
{
	if ((hor==0)||(ver>V)||(hor>H)) return 0; else
	if (memo[ver][hor]) return rec[ver][hor]; else
	if (pointer[ver][hor]!=0)
	{
		rec[ver][hor]=waterfall(ver,kiri[pointer[ver][hor]])+waterfall(ver,kanan[pointer[ver][hor]])+1;
		memo[ver][hor]=true;
		return rec[ver][hor];
	}
	else
		return waterfall(ver+1,hor);
}
int main()
{
	memset(memo,false,sizeof(memo));
	scanf("%d %d %d",&V,&H,&N);
	for (i=0;i<N;i++)
	{
		scanf("%d %d %d %d",&v1,&h1,&v2,&h2);
		for (temp=h1;temp<=h2;temp++)
			pointer[v1-1][temp]=i+1;
			
		kiri[i+1]=h1-1;
		kanan[i+1]=h2+1;	
	}
	for (i=0;i<=H;i++)
		ans=max(ans,waterfall(0,i));
	printf("%lld\n",ans);
	
return 0;		
}