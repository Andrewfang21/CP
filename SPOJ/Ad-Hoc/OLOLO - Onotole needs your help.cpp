#include<bits/stdc++.h>
using namespace std;
bool included[1000000005];
int cnt[1000000005];
int N,i,a;
vector<int>vec;

int main()
{
	cin>>N;
	int temp1=1,temp2=0;
	for (i=1;i<=N;i++)
	{
		cin>>a;
		if ((cnt[a]==temp1)||(cnt[a]==temp2))
			cnt[a]++;
			
		if (included[a])
		{
			vec.push_back(a);
			included[a]=true;
		}
	}
	for (i=0;i<vec.size();i++)
		if (cnt[vec[i]]==1)
			cout<<vec[i]<<"\n";
return 0;
}
