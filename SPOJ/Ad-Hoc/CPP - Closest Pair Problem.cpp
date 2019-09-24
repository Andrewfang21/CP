#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,i,a,b;
	cin>>N;
	pair<double, double>koor[N+5];
	for (i=0;i<N;i++)
	{
		cin>>a>>b;
		koor[i]=make_pair(a,b);
	}
	sort(koor,koor+N);
	
	double ans=2*pow(10,10);
	for (i=1;i<N;i++)
		ans=min(ans,sqrt((koor[i].first-koor[i-1].first)*(koor[i].first-koor[i-1].first)+(koor[i].second-koor[i-1].second)*(koor[i].second-koor[i-1].second)));
	
	cout<<setprecision(6)<<fixed<<ans<<"\n";
return 0;	
}
