#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long diff,posisi,a,b,pangkat[72],i;
	pangkat[0]=1;	pangkat[1]=2;
	for (i=2;i<=70;i++)
		pangkat[i]=pangkat[i-1]*2;
	cin>>a>>b;
	diff=b-a;
	
	for (i=1;i<=63;i++)
	{
		if (diff<pangkat[i])
		{
			posisi=i-1;
			break;
		}
	}
	//cout<<posisi<<"\n";
	vector<long long>vec;
	while (diff>0)
	{
		if (diff>=pangkat[posisi])
		{
			while (diff>=pangkat[posisi])
			{
				diff-=pangkat[posisi];
				vec.push_back(pangkat[posisi]);
				posisi--;
				if (diff==0)
					break;
			}
		}
		else
			posisi--;	
		if (diff==0)
			break;
	}	
	sort(vec.rbegin(),vec.rend());
	for (i=0;i<vec.size();i++)
		cout<<vec[i]<<"\n";
return 0;
}