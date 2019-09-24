#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long TC,total,N,i,sum;
	ios_base::sync_with_stdio(false);
	cin>>TC;
	typedef pair< int, pair<int,int> > ii;
	priority_queue<ii, vector<ii>, greater<ii> >q;
	
	while (TC--)
	{
		cin>>total;
		cin>>N;
		int cook[N+5];
		
		while (!q.empty())
			q.pop();
			
		for (i=1;i<=N;i++)
		{
			cin>>cook[i];
			q.push({cook[i],make_pair(cook[i],1)});				
		}
		ii u;
		sum=0;
		while (!q.empty())
		{
			u=q.top();		q.pop();
			
			sum++;
			//cout<<u.second.first<<" "<<u.second.first<<" "<<sum<<"\n";
			if (sum==total)
			{
				cout<<u.first<<"\n";
				break;
			}
			q.push({u.first+u.second.first*(u.second.second+1),make_pair(u.second.first,u.second.second+1)});
		}
	}
return 0;
}
