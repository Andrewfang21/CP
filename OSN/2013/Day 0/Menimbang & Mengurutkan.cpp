#include<bits/stdc++.h>
using namespace std;
int weighted[105][105],ans,k,N,K;
vector<int>rounds[200],daftar;

void check(int a, int b)
{
	if (weighted[a][b]==0)	//belum pernah ditimbang
	{
		printf("timbang %d %d\n",a,b);
		fflush(stdout);
		
		scanf("%d",&ans);
		if (ans==1)
		{
			weighted[a][b]=1;	weighted[b][a]=-1;
			rounds[k+1].push_back(a);
		}
		else
		{
			weighted[a][b]=-1;	weighted[b][a]=1;
			rounds[k+1].push_back(b);
		}
	}
	else
	if (weighted[a][b]==1)
		rounds[k+1].push_back(a);
	else
		rounds[k+1].push_back(b);
}

int main()
{
	char a[10],b[10];
	scanf("%s %s",a,b);
	scanf("%d %d",&N,&K);
	
	k=1;
	int i;
	for (i=1;i<=N;i++)
		rounds[k].push_back(i);
	
	while (rounds[k].size()>1)
	{
		for (i=0;(i+1)<rounds[k].size();i+=2)
		{
			int tmp1=rounds[k][i],tmp2=rounds[k][i+1];
			check(tmp1,tmp2);
		}
		if ((rounds[k].size()%2==1))	//ganjil, ada sisa 1 orang
			rounds[k+1].push_back(rounds[k][rounds[k].size()-1]);
		k++;
	}
	int now=rounds[k][0];
	//printf("Juara 1 %d\n",now);
	daftar.push_back(now);
	int cnt=1;	//sisa orang yang mau dicari
	
	while (cnt<N)
	{
		for (i=1;i<=k;i++)
			rounds[i].clear();
		
		k=1;
		for (i=1;i<=N;i++)
			if (weighted[now][i]==1)
				rounds[k].push_back(i);
				
		while (rounds[k].size()>1)
		{
			for (i=0;(i+1)<rounds[k].size();i+=2)
			{
				int tmp1=rounds[k][i],tmp2=rounds[k][i+1];
				check(tmp1,tmp2);
			}
			if (rounds[k].size()%2==1)
				rounds[k+1].push_back(rounds[k][rounds[k].size()-1]);
			k++;
		}
		cnt++;
		now=rounds[k][0];
		//printf("Juara %d adalah %d\n",cnt,now);
		daftar.push_back(now);
	}
	printf("jawab");
	for (i=daftar.size()-1;i>=0;i--)
		printf(" %d",daftar[i]);
	printf("\n");
	fflush(stdout);
return 0;
}
