#include<bits/stdc++.h>
using namespace std;

int main()
{
	string dummy;
	int N,i,j,temp,a,b,c;
	
	getline(cin,dummy);
	cin>>N;
	pair<int, pair<int,int> >arr[N+5];
	int vec[N+5];
	vector<int>ans;
	
	for (i=0;i<N;i++)
	{
		cin>>a>>b>>c;
		arr[i]=make_pair(a,make_pair(b,c));
		vec[i]=a;
	}
	sort(arr,arr+N);
	
	for (i=0;i<N;i++)
	{
		temp=i;
		if ((i>=arr[i].second.first)&&(i<=arr[i].second.second))
			continue;
		else
		{
			//cout<<arr[i].first<<"\n";
			int lol=i-arr[i].second.first;
			for (j=0;j<lol;j++)
			{
				//cout<<temp<<"\n";
				swap(arr[temp],arr[temp-1]);
				temp--;
			}
		}
	}
	/*for (i=0;i<N;i++)
		cout<<arr[i].first<<' ';
	cout<<"\n";*/
	
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (arr[i].first==vec[j])
			{
				ans.push_back(j+1);
				break;
			}
		}
	}
	
	
	for (i=0;i<ans.size();i++)
	{
		if (i==ans.size()-1)
			cout<<ans[i]<<"\n";
		else
			cout<<ans[i]<<" ";
	}
return 0;
}
