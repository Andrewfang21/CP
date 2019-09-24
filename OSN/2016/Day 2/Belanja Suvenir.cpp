#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >daftar;
pair<int,int>kwik,kwak;
int cnt[2000005],arr[2000005],N;

pair<pair<int,int>, pair<int,int> >check2()
{
	if (daftar.size()<=1)
		return make_pair(make_pair(-1,-1),make_pair(-1,-1));
		
	int now=daftar[0].second;
	for (int i=1;i<daftar.size();i++)
		if (now<daftar[i].first)
		{
			return make_pair(make_pair(daftar[0].first,daftar[0].second),make_pair(daftar[i].first,daftar[i].second));
		}
return make_pair(make_pair(-1,-1),make_pair(-1,-1));
}

bool check(int len)
{
	int same,i,kiri,kanan;
	same=0;
	memset(cnt,0,sizeof(cnt));
	daftar.clear();
	for (i=1;i<=len;i++)
	{
		cnt[arr[i]]++;
		if (cnt[arr[i]]>1)
			same++;
	}
	kiri=1;		kanan=len;

	while (kanan<=N)
	{
		if (same==0)
			daftar.push_back(make_pair(kiri,kanan));

		if (cnt[arr[kiri]]>1)
			same--;
		cnt[arr[kiri]]--;
		//cout<<kiri<<" "<<kanan<<" "<<same<<"\n";
		kiri++;		kanan++;
		
		if (kanan>N)
			break;
		cnt[arr[kanan]]++;
		if (cnt[arr[kanan]]>1)
			same++;
			
	}
	
	pair<pair<int,int>, pair<int,int> >temp;
	temp=check2();
	
	if (temp.first.first==-1)
		return false;
	else
	{
		kwik=make_pair(temp.first.first,temp.first.second);
		kwak=make_pair(temp.second.first,temp.second.second);
		return true;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int i,kiri,kanan,mid,up=-1;
	string dummy;
	cin>>dummy;
	cin>>N;
	memset(arr,0,sizeof(arr));
	for (i=1;i<=N;i++)
		cin>>arr[i];
		
	kiri=1;		kanan=N/2;
	
	while (kiri<=kanan)
	{
		mid=(kiri+kanan)/2;
		if (check(mid))
		{
			//cout<<mid<<"\n";
			//cout<<kwik.first<<" "<<kwik.second<<" "<<kwak.first<<" "<<kwak.second<<"\n";
			
			up=mid;
			kiri=mid+1;
		}
		else
			kanan=mid-1;
	}
	
	cout<<kwik.first<<" "<<kwik.second<<" "<<kwak.first<<" "<<kwak.second<<"\n";
return 0;
}
