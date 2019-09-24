#include<bits/stdc++.h>
#define fi first
#define sec second
using namespace std;
vector<long long>fak;
vector<pair<long long,long long> >temp;

long long pangkat(long long base, long long power)
{
	if (power==0)
		return 1;
	if (power==1)
		return base;
		
	long long res=pangkat(base,power/2);
	if (power%2==0)
		return res*res;
	else
		return res*res*base;
}

void pohon_faktor(long long num)
{
	long long i;
	for (i=2;i<=sqrt(num);i++)
	{
		if (num%i==0)
		{
			long long cnt=0;
			while (num%i==0)
			{
				num/=i;
				cnt++;
			}
			temp.push_back(make_pair(i,cnt));
		}
	}
	
	if (temp.empty())
		temp.push_back(make_pair(num,1));
}

void faktor_prima(long long num)
{
	long long temp=num;
	for (long long i=2;i<=sqrt(num);i++)
	{
		if (temp%i==0)
		{
			fak.push_back(i);
			while (temp%i==0)
				temp/=i;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	string subs;
	long long res=1,pivot,N,i,INF=1000000007;
	getline(cin,subs);
	cin>>N;
	
	faktor_prima(N); 
	for (i=0;i<fak.size();i++)
		res*=fak[i];		
//	for (i=0;i<fak.size();i++)
//		cout<<fak[i]<<" ";
//	cout<<"\n";	
	
	pivot=N/res;
	
	pohon_faktor(pivot);
	
	cout<<"2\n";
	
	long long ans=1;
	for (i=0;i<temp.size();i++)
		ans=ans*pangkat(temp[i].fi, temp[i].sec);
	cout<<INF<<"/"<<ans<<"\n";
	
	ans=1;
	for (i=0;i<temp.size();i++)
	{
		long long temp1=pangkat(temp[i].fi, temp[i].sec);
		ans=ans*pangkat(temp1,2);
	}
	cout<<ans<<"/"<<INF<<"\n";
return 0;
}
