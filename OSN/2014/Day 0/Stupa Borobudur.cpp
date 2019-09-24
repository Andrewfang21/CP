#include<bits/stdc++.h>
using namespace std;
string dummy;
long long N,i,a,sum,hitung;
vector<long long>vec;

int main()
{
	cin>>dummy;
	cin>>N;
	for (i=1;i<=N;i++)
	{
		cin>>a;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end());
	a=vec[0];
	hitung=1;
	for (i=1;i<vec.size();i++)
	{
		if (vec[i]==a)
			hitung++;
		else
		if (vec[i]!=a)
		{
			sum+=a;
			hitung=1;
			a=vec[i];
		}
		if  (hitung>vec[i])
		{
			cout<<"-1\n";
			return 0;
		}
	}
	sum+=vec[vec.size()-1];
	cout<<sum<<"\n";
return 0;
}
