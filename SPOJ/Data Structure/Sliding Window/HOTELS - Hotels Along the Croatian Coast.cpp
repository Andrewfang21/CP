#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long i,M,N,left,right,sum,maks;
	cin>>N>>M;
	long long arr[N+5];
	for (i=1;i<=N;i++)
		cin>>arr[i];
		
	maks=INT_MIN;
	left=right=1;
	sum=arr[1];
	
	while (right<=N)
	{
		while (sum<M)
		{
			right++;
			if (right>N)
				break;
			sum+=arr[right];
			//cout<<right<<" "<<sum<<"\n";
			if ((maks<sum)&&(sum<=M))
				maks=sum;
		}
		while (sum>=M)
		{
			sum-=arr[left];
			left++;
			if (left>N)
				break;
			//cout<<left<<" "<<sum<<"\n";
			if ((maks<sum)&&(sum<=M))
				maks=sum;
		}
	}
	cout<<maks<<"\n";
return 0;
	
}
