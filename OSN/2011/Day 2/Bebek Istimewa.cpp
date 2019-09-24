#include<bits/stdc++.h>
using namespace std;
int daftar[1005],i,j,N,M;
int lol[1005];
bool found,visited[2005][1005];

bool inside(int num)
{
	if ((num>=1)&&(num<=N))
		return true;
return false;
}

void DFS(int kandang, int time)
{
	if ((!visited[kandang][time])&&(lol[time]!=kandang)&&(inside(kandang))&&(!found))
	{
		visited[kandang][time]=true;
		daftar[time]=kandang;
		
		if ((time==M)&&(lol[time]!=kandang))
		{
			found=true;
			for (int i=1;i<=M;i++)
				cout<<daftar[i]<<"\n";
		}
			
		DFS(kandang+1,time+1);
		DFS(kandang-1,time+1);
	}
}

void dfs (int posisi, int waktu)
{
	if ((posisi!=lol[waktu])&&(posisi>=1)&&(posisi<=N)&&(!found))
	{
		daftar[waktu]=posisi;
		if (waktu==M)
		{
			for (int temp=1;temp<=waktu;temp++)
				cout<<daftar[temp]<<"\n";
			found=true;
		}
		else
		{
		dfs(posisi+1,waktu+1);
		dfs(posisi-1,waktu+1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>M;
	for (i=1;i<=M;i++)
		cin>>lol[i];
	
	found=false;
	if (N>2000)
	{
		for (i=(N/2);i<=N;i++)
			if (!found)
			{
				dfs(i,0);
				if (found) break;
			}
	}
	else
	{
		memset(visited,false,sizeof(visited));
		for (i=1;i<=N;i++)
		{
			if ((!visited[i][1])&&(lol[1]!=i))
				DFS(i,1);
		}
	}
	if (!found) cout<<"menyerah\n";
return 0;
}
