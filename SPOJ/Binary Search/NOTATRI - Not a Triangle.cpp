#include<bits/stdc++.h>
using namespace std;
int arr[2005],N;

int search(int dummy, int num)
{
	int left,right,mid,low=-1;
	
	left=dummy;		right=N;
	
	while (left<=right)
	{
		mid=(left+right)/2;
		
		//cout<<left<<" "<<right<<" "<<mid<<" "<<arr[mid]<<"\n";
			
		if (arr[mid]>num)
		{
			low=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}
return low;
}

int main()
{
	while (cin>>N)
	{
		if (N==0)
			return 0;
		
		int i,j,temp,dummy,x,ans=0;
		
		for (i=1;i<=N;i++)
			cin>>arr[i];
			
		sort(arr+1,arr+N+1);
		
		for (i=1;i<N;i++)
			for (j=i+1;j<=N;j++)
			{
				temp=arr[i]+arr[j];
				dummy=j+1;
				
				x=search(dummy,temp);
				
				if ((x!=-1)&&((N-x)>=0))
					ans+=(N-x+1);
			}
		cout<<ans<<"\n";
	}
}
