#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,K,val;
	vector<int>vec;
	
	cin>>N>>K;
	for (int i=1;i<=N;i++)
	{
		cin>>val;
		vec.push_back(val);
	}
	sort(vec.begin(), vec.end());
	
	cout<<vec[K-1]<<"\n";
	
return 0;
}
