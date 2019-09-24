#include<bits/stdc++.h>
using namespace std;
int M,hist[1005];

int check()
{
	stack<int>st;
	int temp=0,area,max_area;
	max_area=-1;
	
	while (temp<M)
	{
		if ((st.empty())||(hist[temp]>=hist[st.top()]))
			st.push(temp++);
		else
		{
			int lol=st.top();
			st.pop();
			
			if (!st.empty())
				area=hist[lol]*(temp-st.top()-1);
			else
				area=hist[lol]*temp;
				
			max_area=max(max_area,area);
		}
	}
	while (!st.empty())
	{
		int lol=st.top();
		st.pop();
		
		if (!st.empty())
			area=hist[lol]*(temp-st.top()-1);
		else
			area=hist[lol]*temp;
			
		max_area=max(max_area,area);
	}
return max_area;
}

int main()
{
	int TC,N,i,j,temp;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M;
		int ans=-1;
		char arr[N+5][M+5];
		for (i=0;i<N;i++)
			for (j=0;j<M;j++)
				cin>>arr[i][j];
		memset(hist,0,sizeof(hist));
		ans=-1;
		
		for (i=0;i<N;i++)
		{
			for (j=0;j<M;j++)
			{
				if (arr[i][j]=='R')
					hist[j]=0;
				else
					hist[j]++;
			}
			temp=check();
			
			ans=max(ans,temp);
		}
	int res=3*ans;
	cout<<res<<"\n";
	}
}
