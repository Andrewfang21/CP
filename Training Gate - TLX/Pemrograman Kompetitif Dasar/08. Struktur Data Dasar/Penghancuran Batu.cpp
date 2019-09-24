#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N,i;
	long long sum=0;
	vector<int>vec;		vector<int>::iterator it;
	scanf("%d",&N);
	for (i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		vec.push_back(a);
	}
	it=vec.begin();
	while(vec.size()!=1)
	{
		if (it==vec.begin())
		{
			if (*it<=*(it+1))
			{
				sum+=*(it+1);
				vec.erase(it);
				if (vec.size()==1) break;
			}
			else it++;
		} else
		if (it==vec.end()-1)
		{
			if (*(it-1)>=*it)
			{
				sum+=*(it-1);
				vec.erase(it);
				if (vec.size()==1) break; else
				it--;
			}
			else it--;
		} else
		if (*it<=*(it-1)&&*it<=*(it+1))
		{
			sum+=min(*(it-1),*(it+1));
			vec.erase(it);
			it--;
			if (vec.size()==1) break;
		}
		else
		if ((*it)<=*(it-1)&&(*it)>=*(it+1))
			it++;	
	}
	printf("%lld\n",sum);
return 0;	
}
