#include<bits/stdc++.h>
#define dist first 
#define fuel second 
using namespace std;

int main()
{
	int TC,N,i,a,b,jarak,now,cnt,prev;
	bool fail;
	vector<pair<int,int> >vec;
	priority_queue<int,vector<int> >q;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		for (i=1;i<=N;i++)
		{
			cin>>a>>b;
			vec.push_back(make_pair(a,b));
		}
		cin>>jarak>>now;
		for (i=0;i<N;i++)
			vec[i].dist=jarak-vec[i].dist;
			
		sort(vec.begin(),vec.end());
		
		/*for (i=0;i<N;i++)
			cout<<vec[i].dist<<" "<<vec[i].fuel<<"\n";*/
		
		prev=cnt=0;
		fail=false;
		for (i=0;i<N;i++)
		{
			now-=(vec[i].dist-prev);
			while ((now<0)&&(!q.empty()))
			{
				now+=q.top();
				q.pop();
				cnt++;	
			}	
			if ((now<0)&&(q.empty()))
			{
				fail=true;
				break;
			}
			
			q.push(vec[i].fuel);
			prev=vec[i].dist;
			//cout<<now<<" "<<q.top()<<"\n";
		}
		now-=(jarak-prev);
		//cout<<now<<"\n";
		while ((now<0)&&(!q.empty()))
		{
			now+=q.top();
			q.pop();
			cnt++;
		}
		if ((now<0)&&(!q.empty()))
			fail=true;
			
		if (fail)
			cout<<"-1\n";
		else
			cout<<cnt<<"\n";
			
		while (!q.empty())
			q.pop();
		vec.clear();
	}
}
