#include<bits/stdc++.h>
using namespace std;
long long N,a,i;
double ans=0,temp;
vector<long long> vec;
map<long long, long long>frek;
 
 
int main()
{
	ios_base::sync_with_stdio(false);
 
	cin>>N;
 
	for (i=1;i<=N;i++)
	{
		cin>>a;
		frek[a]++;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end(),greater<unsigned long long>() );
 
	for (i=vec.size();i>=0;i--)
	{
		if (i==0)
		{
			if (frek[vec[i]]==1)
			{
				frek[vec[i]]=0;		frek[vec[i+1]]++;
				temp=abs(vec[i]-vec[i+1]);
				ans+=temp;
				vec[i]=vec[i+1];
			}
		}
		else
		if (i==vec.size()-1)
		{
			if (frek[vec[i]]==1)
			{
				frek[vec[i]]=0;		frek[vec[i-1]]++;
				temp=abs(vec[i]-vec[i-1]);
				ans+=temp;
				vec[i]=vec[i-1];
			}
		}
		else
		if (i>0)
		{
			if (frek[vec[i]]==1)
			{
				if (abs(vec[i-1]-vec[i])>abs(vec[i+1]-vec[i]))	//biaya ubah ke vec[i+1] lebih murah
				{
					frek[vec[i]]=0;		frek[vec[i+1]]++;
					temp=abs(vec[i+1]-vec[i]);
					ans+=temp;
					vec[i]=vec[i+1];
				}	
				else
				if (abs(vec[i-1]-vec[i])<abs(vec[i]-vec[i+1]))	//biaya ubah ke vec[i-1] lebih murah
				{
					frek[vec[i]]=0;		frek[vec[i-1]]++;
					temp=abs(vec[i-1]-vec[i]);
					ans+=temp;
					vec[i]=vec[i-1];
				}
				else
				{
					if (frek[vec[i-1]]>=frek[vec[i+1]])
					{
						frek[vec[i]]=0;		frek[vec[i+1]]++;
						temp=abs(vec[i+1]-vec[i]);
						ans+=temp;
						vec[i]=vec[i+1];
					}
					else
					{
						frek[vec[i]]=0;		frek[vec[i-1]]++;
						temp=abs(vec[i-1]-vec[i]);
						ans+=temp;
						vec[i]=vec[i-1];
					}
				}
			}
		}	
	}
	cout<<ans<<"\n";
	/*for (i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<"\n";*/
return 0;
}
