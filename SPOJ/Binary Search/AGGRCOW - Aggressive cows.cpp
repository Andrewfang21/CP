#include<bits/stdc++.h>
using namespace std;
vector<long long>vec;
long long N,C,res;

bool check(int num)
{
	long long now,temp,cnt=1;	
	now=vec[0];
	for (temp=1;temp<vec.size();temp++)
	{
		if (vec[temp]-now>=num)
		{
			cnt++;
			now=vec[temp];
			
			if (cnt==C)
				return true;
		}
	}
return false;
}

int search()
{
	long long kiri,kanan,tengah,choose;
	kiri=0;		kanan=vec[vec.size()-1];

	while (kiri<=kanan)
	{
		tengah=(kiri+kanan)/2;
		//cout<<kiri<<" "<<kanan<<" "<<tengah<<"\n";
		if (check(tengah))
		{
			choose=tengah;
			kiri=tengah+1;
		}
		else
			kanan=tengah-1;
	}
return choose;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,i,a;
	cin>>TC;
	
	while (TC--)
	{
		res=0;
		cin>>N>>C;
		for (i=0;i<N;i++)
		{
			cin>>a;
			vec.push_back(a);
		}
		sort(vec.begin(),vec.end());
		
		res=search();
		cout<<res<<"\n";
		vec.clear();
	}
return 0;
}
