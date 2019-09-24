#include<bits/stdc++.h>
using namespace std;
vector<long long>vec;
long long num,i,Q,temp,a;

long long search(long long a)
{
	long long kiri,kanan,tengah;
	kiri=0;		kanan=vec.size()-1;
	
	while (kiri<=kanan)
	{
		tengah=(kiri+kanan)/2;
		if (vec[tengah]<a)
			kiri=tengah+1;
		else
		if (vec[tengah]>a)
			kanan=tengah-1;
		else
			return tengah;
	}
	return -1;
}

int main()
{
	num=0;
	while ((num*num)<=pow(10,12))
	{
		temp=num*num;
		vec.push_back(temp);
		//cout<<temp<<"\n";
		num++;
	}
	//cout<<vec.size()<<"\n";
	
	sort(vec.begin(),vec.end());
	cin>>Q;
	
	while (Q--)
	{
		cin>>a;
		bool found=false;
		for (i=0;i<vec.size();i++)
		{
			if (vec[i]>a)	break;
			else
			{
				temp=a-vec[i];
				if (search(temp)!=-1)
				{
					found=true;
					break;
				}
			}
		}
		if (found)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
return 0;
}
