#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,M,a,i;
	vector<int>vec1,vec2;
	while (cin>>N>>M)
	{
		if (N==0)
			return 0;
		for (i=0;i<N;i++)
		{
			scanf("%d",&a);
			vec1.push_back(a);
		}
		for (i=0;i<M;i++)
		{
			scanf("%d",&a);
			vec2.push_back(a);
		}
		sort(vec1.begin(),vec1.end());		sort(vec2.begin(),vec2.end());
		
		if ((vec1[0]>=vec2[0])&&(vec1[0]>=vec2[1]))
			printf("N\n");
		else
			printf("Y\n");
		vec1.clear();		vec2.clear();
	}
return 0;
}
