#include<bits/stdc++.h>
using namespace std;

struct lol
{
	long long jenis,cerah;
};

bool nilai(lol lhs, lol rhs)
{
	if (lhs.cerah==rhs.cerah)
		return lhs.jenis<rhs.jenis;
	else
		return lhs.cerah<rhs.cerah;
}

bool jenis(lol lhs, lol rhs)
{
	if (lhs.jenis==rhs.jenis)
		return lhs.cerah<rhs.cerah;
	else
		return lhs.jenis<rhs.jenis;
}

int main()
{
	ios_base::sync_with_stdio(false);
	string dummy;
	long long N,M,i,sum,total;
	cin>>dummy;
	cin>>N>>M;
	lol arr[N+5];
	long long cnt[M+5],val[M+5];
	sum=total=0;
	memset(cnt,0,sizeof(cnt));		memset(val,0,sizeof(val));
	
	for (i=0;i<N;i++)
	{
		cin>>arr[i].jenis>>arr[i].cerah;
		total+=arr[i].cerah;
		cnt[arr[i].jenis]++;
		val[arr[i].jenis]+=arr[i].cerah;
	}
	
	sort(arr,arr+N,nilai);
	for (i=0;i<N;i++)
	{
		total-=arr[i].cerah;
		sum=sum+(total-((N-i-1)*arr[i].cerah));
		//cout<<sum<<" "<<total<<" "<<arr[i].cerah<<" "<<arr[i].jenis<<"\n";
	}
	//cout<<sum<<"\n";
	sort(arr,arr+N,jenis);
	
	for (i=0;i<N;i++)
	{
		cnt[arr[i].jenis]--;		val[arr[i].jenis]-=arr[i].cerah;
		long long temp=cnt[arr[i].jenis]*arr[i].cerah;
		//cout<<cnt[arr[i].jenis]<<" "<<arr[i].cerah<<" "<<val[arr[i].jenis]<<"\n";
		
		sum-=(val[arr[i].jenis]-temp);
	}
	cout<<sum<<"\n";
return 0;
}
