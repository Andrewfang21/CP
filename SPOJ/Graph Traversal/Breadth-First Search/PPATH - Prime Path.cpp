#include<bits/stdc++.h>
using namespace std;
int p,b,dist[10002],INF=2*pow(10,7),i,j,u,temp[6],temp1,save;
bool notprime[15025],visited[15025];
struct lol
{
	int num,jarak;
}a;

int convert_num()
{
	int ans=(temp[1]*1000)+(temp[2]*100)+(temp[3]*10)+(temp[4]);
return ans;
}

void Sieve_Erastothenes()
{
	int x;
	p=2;	notprime[1]=true;
	while ((p*p)<10000)
	{
		x=2;
		while ((p*x)<10000)
		{
			notprime[p*x]=true;
			x++;	
		}
		p++;
		while (notprime[p])	p++;	
	}	
}

int main()
{
	memset(notprime,false,sizeof(notprime));
	Sieve_Erastothenes();
	int TC;
	cin>>TC;
	
	while (TC--)
	{
		queue<lol>q;
		memset(visited,false,sizeof(visited));
		
		cin>>u>>b;
		
		dist[b]=INF;
		dist[u]=0;
		q.push({u,0});
		
		while (!q.empty())
		{
			a=q.front();
			
			if (!visited[a.num])
			{
				visited[a.num]=true;
				dist[a.num]=a.jarak;
								
				for (i=1;i<=4;i++)
				{
					temp[4-i+1]=a.num%10;
					a.num/=10;
				}
		
				for (i=1;i<=4;i++)
				{
					if (i==1)
					{
						temp1=temp[i];
						for (j=1;j<=9;j++)
						{
							temp[i]=j;
							save=convert_num();
							if (!notprime[save])
							{
								if (!visited[save])
									q.push({save,dist[q.front().num]+1});
							}
						}
						temp[i]=temp1;
					}
					else
					{
						temp1=temp[i];
						for (j=0;j<=9;j++)
						{
							temp[i]=j;
							save=convert_num();
							if (!notprime[save])
							{
								if (!visited[save])
									q.push({save,dist[q.front().num]+1});
							}
						}
						temp[i]=temp1;
					}
				}
			}
			q.pop();
		}
		cout<<dist[b]<<"\n";
	}
return 0;
}
