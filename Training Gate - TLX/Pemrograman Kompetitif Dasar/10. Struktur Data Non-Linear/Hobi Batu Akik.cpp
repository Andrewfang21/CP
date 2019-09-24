#include<bits/stdc++.h>
using namespace std;

int Q,type,val;
priority_queue<int, vector<int> >q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>Q;
	
	while (Q--)
	{
		cin>>type;
		
		if (type==1)
		{
			cin>>val;
			q.push(val);
		}
		else
		if (type==2)
			cout<<q.top()<<"\n";
		else
			q.pop();
	}
return 0;
}
