#include<bits/stdc++.h>
using namespace std;
pair<pair<long long,long long>, pair<long long,long long> >vec[100005];
vector<int>daftar;
long long Sd,Td,Ls,Lt,N;

bool check()
{
	double temp1=ceil(double(vec[0].second.first)/double(Td));
	double temp2=ceil(double(Sd)/double(vec[0].second.second));
	
	if (temp1<=temp2)
		return true;
return false;
}

bool check1(int times,int a,int b)
{
	double temp1=ceil(double(a)/double(Td+times*Lt));
	double temp2=ceil(double(Sd+times*Ls)/double(b));
	
	if (temp1<=temp2)
		return true;
return false;
}

int binser(int a, int b)
{
	int kiri,kanan,mid,up=-1;
	kiri=0;		kanan=N;
	
	while (kiri<=kanan)
	{
		mid=(kiri+kanan)/2;
		if (check1(mid,a,b))
		{
			up=mid;
			kanan=mid-1;
		}
		else
			kiri=mid+1;
	}
return up;
}

int main()
{
	ios_base::sync_with_stdio(false);
	string dummy;
	cin>>dummy;
	int i,x,INF=2*pow(10,7);
	
	cin>>Sd>>Td>>Ls>>Lt>>N;
	for (i=0;i<N;i++)
	{
		cin>>vec[i].second.first>>vec[i].second.second;
		vec[i].first.second=i;		//indeks
	}
	if (check())
	{
		cout<<"0\n";
		return 0;
	}
	for (i=1;i<N;i++)
	{
		x=binser(vec[i].second.first,vec[i].second.second);
		if (x>=0)
			vec[i].first.first=x;		//jumlah pertambahan kemampuan yang dibutuhkan
		else
			vec[i].first.first=INF;
	}
	sort(vec+1,vec+N);
	
	for (i=1;i<N;i++)
	{
		if (vec[i].first.first<i)
		{
			Sd+=Ls;		Td+=Lt;
			daftar.push_back(vec[i].first.second+1);
			
			if (check())
			{
				cout<<daftar.size()<<"\n";
				for (int j=0;j<daftar.size();j++)
					cout<<daftar[j]<<"\n";
				return 0;
			}
		}
		else
			break;
	}
	if (!check())
	{
		cout<<"-1\n";
		return 0;
	}
return 0;
}
