#include<bits/stdc++.h>
using namespace std;
int TC,N,K,points[105][305],arr[105],i,j,now[105],temp,start;

int proses(int &player, int start)
{
	//cout<<"\n";
	int temp1=0;
	for (int temp=start;temp<start+3;temp++)
	{
		if (temp>K)
			break;
		temp1+=points[player][temp];
		arr[player]+=points[player][temp];
		
		//cout<<player<<" "<<arr[player]<<" "<<points[player][temp]<<"\n";
		now[player]++;	
		
		if (arr[player]>301)
		{
			arr[player]-=temp1;			now[player]=temp+1;
			return arr[player];
		}
		else
		if (arr[player]==301)
			return 301;
	}
return arr[player];
}

int main()
{
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>K;
		memset(arr,0,sizeof(arr));
		
		for (i=1;i<=N;i++)
			for (j=1;j<=K;j++)
				cin>>points[i][j],now[i]=1;
		
		bool finish=false,lol=false;
		
		while (!finish)
		{
			for (i=1;i<=N;i++)
				if (now[i]<=K)
				{
					arr[i]=proses(i,now[i]);
					
					//cout<<i<<" "<<arr[i]<<"\n";
			
					if (arr[i]==301)
					{
						finish=true;
						cout<<i<<"\n";
						break;
					}
				}
			lol=false;
			for (i=1;i<=N;i++)
				if (now[i]<=K)
					lol=true;
			
			if (!lol)
				break;
		}
		
		if (!finish)
			cout<<"TIE\n";
	}
return 0;
}
