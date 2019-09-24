#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,TC,i,ans,temp;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		int men[N+5],women[N+5];
		for (i=0;i<N;i++)
			cin>>men[i];
		for (i=0;i<N;i++)
			cin>>women[i];
		ans=0;	
		sort(men,men+N);	sort(women,women+N);
		
		for (i=0;i<N;i++)
		{
			temp=men[i]*women[i];
			ans+=temp;
		}
		cout<<ans<<"\n";
	}
return 0;
}
