#include<bits/stdc++.h>
using namespace std;
vector<int>vec;

int search(int left,int num)
{
	int kiri,kanan,tengah,up,low;
	up=low=-1;
	kiri=left;		kanan=vec.size()-1;
	
	while (kiri<=kanan)	//upper
	{	
		tengah=(kiri+kanan)/2;
		if (vec[tengah]<=num)
		{
			up=tengah;
			kiri=tengah+1;	
		}	
		else
			kanan=tengah-1;
	}
	
	kiri=left;		kanan=vec.size()-1;
	
	while (kiri<=kanan)
	{
		tengah=(kiri+kanan)/2;
		if (vec[tengah]>=num)
		{
			low=tengah;
			kanan=tengah-1;
		}
		else
			kiri=tengah+1;
	}
	if ((up>0)&&(low>0)&&(up-low+1)>0)
		return (up-low+1);	
return 0;
}

int main()
{
	int N,K,i,a,x,ans=0;
	cin>>N>>K;
	for (i=0;i<N;i++)
	{
		cin>>a;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end());
	
	for (i=0;i<vec.size();i++)
	{
		x=search(i,vec[i]+K);
		ans+=x;
	}
	cout<<ans<<"\n";
return 0;
}
