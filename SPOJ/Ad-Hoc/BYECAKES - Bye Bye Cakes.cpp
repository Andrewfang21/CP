#include<bits/stdc++.h>
using namespace std;
double a[5],b[5];
int i,temp,now;
vector<int>vec;

int main()
{
	while (cin>>a[1]>>a[2]>>a[3]>>a[4]>>b[1]>>b[2]>>b[3]>>b[4])
	{
		now=-1;
		if (a[1]==-1)
			return 0;
		
		for (i=1;i<=4;i++)
		{
			temp=ceil(a[i]/b[i]);
			now=max(now,temp);
		}
		for (i=1;i<=4;i++)
		{
			temp=(now*b[i])-a[i];
			vec.push_back(temp);
		}
		for (i=0;i<vec.size();i++)
			if (i==vec.size()-1)
				cout<<vec[i]<<"\n";
			else
				cout<<vec[i]<<" ";
		vec.clear();
	}
return 0;
}
