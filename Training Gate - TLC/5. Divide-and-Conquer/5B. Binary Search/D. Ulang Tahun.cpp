#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N,Q,i,kiri,kanan,tengah;
	cin>>N>>Q;
	pair<string,string>data[N+5];
	string ques;
	for (i=1;i<=N;i++)
		cin>>data[i].first>>data[i].second;
	for (i=1;i<=Q;i++)
	{
		cin>>ques;
		
		kiri=1;		kanan=N;
		while(kiri<=kanan)
		{
			tengah=(kiri+kanan)/2;
			if (data[tengah].first==ques)
			{
				cout<<data[tengah].second<<"\n";
				break;
			}
			else
			if (data[tengah].first>ques)
				kanan=tengah-1;
			else
			if (data[tengah].first<ques)
				kiri=tengah+1;
		}
	}
return 0;
}