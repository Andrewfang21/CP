#include<bits/stdc++.h>
using namespace std;

int curr,N,K,v[500];

int print(int a, int b)
{
	string ans;
	cout<<"Q 1 "<<a<<" "<<b<<endl;

	cin>>ans;
	
	if (ans[0]=='S')
		return 1;
return -1;
}

void geser(int piv)
{
	curr++;
	
	for (int i=curr;i>piv;i--)
		swap(v[i],v[i-1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	string subs;
	cin>>subs;
	cin>>N>>K;
	
	cout<<"Q 1 2 3"<<endl;
	string ans;
	cin>>ans;
	
	if (ans[0]=='S')
	{
		v[++curr]=2;
		v[++curr]=3;
	}
	else
	{
		v[++curr]=3;
		v[++curr]=2;
	}
	
	for (int i=4;i<=N;i++)
	{
		int kiri,kanan,mid,res,up=-1;
		
		kiri=1;		kanan=curr;
		
		while (kiri<=kanan)
		{
			mid=(kiri+kanan)/2;
//			cout<<"LEFT : "<<kiri<<"   RIGHT : "<<kanan<<"\n";
			res=print(v[mid],i);
			
			if (res==1)		// SEARAH
			{
				up=mid;
				kiri=mid+1;
			}
			else
				kanan=mid-1;
		}	
//		cout<<up<<"\n";

		if (up!=-1)
		{
			geser(up+1);
			v[up+1]=i;	
		}
		else
		{
			geser(1);
			v[1]=i;
		}
			
/*		for (int j=1;j<=curr;j++)
			cout<<v[j]<<" ";
		cout<<"\n";*/
	}
	
	cout<<"A 1";
	for (int i=1;i<=curr;i++)
		cout<<" "<<v[i];
	cout<<endl;
	
return 0;
}
