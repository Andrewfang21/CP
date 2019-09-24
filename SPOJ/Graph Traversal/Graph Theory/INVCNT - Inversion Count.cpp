#include<bits/stdc++.h>
using namespace std;
long long N,arr[200005];

long long merge(int left, int mid, int mid2, int right)
{
	long long temp[N+5],i,j,k,l,m,cnt=0;
	
	i=m=left;	j=mid;	k=mid2;	l=right;
	
	while ((i<=j)&&(k<=right))
	{
		if (arr[i]<=arr[k])
			temp[m++]=arr[i++];
		else
		{
			temp[m++]=arr[k++];
			cnt+=(mid2-i);
		}
	}
	while (i<=j)
		temp[m++]=arr[i++];
	while (k<=l)
		temp[m++]=arr[k++];
	
	for (long long temp1=left;temp1<=right;temp1++)
		arr[temp1]=temp[temp1];
		
return cnt;
}

long long merge_sort(int left, int right)
{
	long long mid,cnt=0;
	if (right>left)	//base case
	{
		mid=(left+right)/2;
		
		cnt+=merge_sort(left,mid);
		cnt+=merge_sort(mid+1,right);
		
		cnt+=merge(left,mid,mid+1,right);
	}
return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	long long TC,i,left,right,mid,ans;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		for (i=1;i<=N;i++)
			cin>>arr[i];
			
		left=1;		right=N;
		mid=(left+right)/2;
		ans=0;
		
		ans+=merge_sort(left,mid);
		ans+=merge_sort(mid+1,right);
		
		ans+=merge(left,mid,mid+1,right);
		
		cout<<ans<<"\n";
		
		/*for (i=1;i<=N;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";*/
	}
}
