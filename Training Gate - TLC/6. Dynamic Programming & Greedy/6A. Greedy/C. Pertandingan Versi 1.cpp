#include<bits/stdc++.h>
using namespace std;

int main()
{
	int TC,N,i,a,temp,res,maks_lawan,maks_kita,lol;
	cin>>TC;
	
	while (TC--)
	{
		vector<int>lawan,own;
		lawan.clear();	own.clear();
		cin>>N;
		for (i=0;i<N;i++)
		{
			cin>>a;
			lawan.push_back(a);
		}
		for (i=0;i<N;i++)
		{
			cin>>a;
			own.push_back(a);
		}
		sort(lawan.begin(),lawan.end());	sort(own.begin(),own.end());
		
		maks_lawan=lawan[N-1];		maks_kita=own[N-1];
		temp=res=0;		lol=N-1;
		for (i=N-1;i>=0;i--)
		{
			if (lawan[i]>=maks_kita)
			{
				res-=3;
				temp++;	
				maks_lawan=lawan[i-1];
			}
			else
			if (lawan[i]<maks_kita)
			{
				res+=3;
				lol--;
				maks_kita=own[lol];
				maks_lawan=lawan[i-1];
			}
		}
		if (res>0)	cout<<"YA\n"; else cout<<"TIDAK\n";
	}
}