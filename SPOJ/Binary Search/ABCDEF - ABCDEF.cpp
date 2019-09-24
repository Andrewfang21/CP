#include<bits/stdc++.h>
using namespace std;
vector<int>vec1,vec2;

int search(int num)
{
	int tengah,kiri,kanan,up,low;
	up=low=-1;
	
	kiri=0;		kanan=vec2.size()-1;
	
	while (kiri<=kanan)	//upper
	{
		tengah=(kiri+kanan)/2;
		
		if (vec2[tengah]<=num)
		{
			up=tengah;
			kiri=tengah+1;
		}
		else
			kanan=tengah-1;
	}
	
	kiri=0;		kanan=vec2.size()-1;
	
	while (kiri<=kanan)	//lower
	{
		tengah=(kiri+kanan)/2;
		
		if (vec2[tengah]>=num)
		{
			low=tengah;
			kanan=tengah-1;
		}
		else
			kiri=tengah+1;
	}
	if ((up>=0)&&(low>=0)&&(up-low+1>=0))
		return (up-low+1);
return 0;
}

int main()
{
	int N,i,j,k;
	long long res=0;
	cin>>N;
	int arr[N+5];
	
	for (i=0;i<N;i++)
		cin>>arr[i];
	
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			for (k=0;k<N;k++)
				vec1.push_back(arr[i]*arr[j]+arr[k]);
				
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			for (k=0;k<N;k++)
				if (arr[i]!=0)
					vec2.push_back(arr[i]*(arr[j]+arr[k]));
					
	sort(vec1.begin(),vec1.end());		sort(vec2.begin(),vec2.end());
	
	for (i=0;i<vec1.size();i++)
	{
		int x=search(vec1[i]);
		res+=x;
	}
	cout<<res<<"\n";
return 0;
}
