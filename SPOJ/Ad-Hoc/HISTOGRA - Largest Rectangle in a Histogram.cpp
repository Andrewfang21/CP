#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	while (cin>>N)
	{
		if (N==0)
			return 0;
		
		long long i,hist[N+5],ans=-1,area;
		stack<long long>st;
		
		for (i=0;i<N;i++)
			cin>>hist[i];
			
		i=0;
		while (i<N)
		{
			if ((st.empty())||(hist[i]>=hist[st.top()]))
				st.push(i++);
			else
			{
				int tp=st.top();
				st.pop();
				
				if (!st.empty())
					area=hist[tp]*(i-st.top()-1);
				else
					area=hist[tp]*i;
					
				ans=max(area,ans);
			}
		}
		while (!st.empty())
		{
			int tp=st.top();
			st.pop();
			
			if (!st.empty())
				area=hist[tp]*(i-st.top()-1);
			else
				area=hist[tp]*i;
				
			ans=max(area,ans);
		}
		cout<<ans<<"\n";
	}
}
