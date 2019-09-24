#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	stack<long long> st;
	long long N,i,a,b;
	
	cin>>N;
	for (i=1;i<=N;i++)
	{
		cin>>a;
		if (a==1)
		{
			cin>>b;
			st.push(b);
		}
		else
		if ((a==2)&&(!st.empty()))
			st.pop();
		else
		if (a==3)
			if (!st.empty())
				cout<<st.top()<<"\n";
			else
				cout<<"Empty!\n";
	}
return 0;
}
