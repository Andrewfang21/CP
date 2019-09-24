#include<bits/stdc++.h>
using namespace std;

int main()
{
	while (cin>>N>>broken>>V)
	{
		if ((N==0)&&(broken==0)&&(V==0))	return 0;
		for (i=1;i<=(broken+1);i++)
		{
			cin>>a;
			if (i=1)	source=a;
			else
				trash[i-1]=a;
		}
		for (i=1;i<=V;i++)
		{
			cin>>a>>command>>b;
			panjang=stoi(command.substr(2,command.length()-4));
			if ((command[0]=='<')&&(command[command.length()-1]=='>'))
			{
				adj[a].push_back(b);	adj[b].push_back(a);
				weight[a][b]=panjang;	weight[b][a]=panjang;
			}
			else
			if (command[0]=='<')
			{
				adj[a].push_back(b));
				weight[a][b]=panjang;
			}
			else
			if (command[command.length()-1]=='>')
			{
				adj[b].push_back(a);
				weight[b][a]=panjang;
			}
		}
		
	}
