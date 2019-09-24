#include<bits/stdc++.h>
using namespace std;
bool bisa,flag[1200],included[1200],contained[1200];
int main()
{
	string a,ans;
	char b;
	long long kiri,kanan,N,K,Q,i,j,tengah,upper;
	vector<long long>vec;
	cin>>a>>b;	
	cin>>N>>K>>Q;
	memset(flag,false,sizeof(flag));
	memset(contained,false,sizeof(contained));
	memset(included,false,sizeof(included));
	if (b=='5')
	{
		kiri=1;	kanan=N;
		while(kiri<=kanan)
		{
			tengah=(kiri+kanan)/2;
			cout<<1<<" "<<tengah<<"\n";
			cin>>ans;
			
			if (ans=="bisajadi")
			{
				upper=tengah;
				kiri=tengah+1;
			} else
			if (ans=="tidak")
			{
				kanan=tengah-1;
			}
		}
		cout<<upper;
		for (i=1;i<=upper;i++)
			cout<<" "<<i;
		cout<<"\n";
		fflush(stdout);
		return 0;
	}
	else
	if ((b=='4')||(b=='3'))
	{
		for (i=1;i<=N;i++)
		{
			cout<<"1 "<<i<<"\n";
			fflush(stdout);
			
			cin>>ans;
			if (ans=="bisajadi")
				vec.push_back(i);
			else
			if (ans=="ya")	return 0;
		}
		cout<<vec.size();
		for (i=0;i<vec.size();i++)
			cout<<" "<<vec[i];
		cout<<"\n";
		fflush(stdout);
		return 0;
	}
	else
	{
		for (i=1;i<=N-1;i++)
		{
			bisa=true;
				for (j=i+1;j<=N;j++)
				{
					if ((!flag[i])||(!flag[j]))		//flag menandakan bilangan yang pasti bukan merupakan subhimpunan S
					{
						cout<<"2 "<<i<<" "<<j<<"\n";
						fflush(stdout);
						cin>>ans;
						
						if ((ans=="bisajadi")&&(!flag[j])&&(!included[j]))
						{
							vec.push_back(j);
							included[j]=true;	
						}
						else 
						if (ans=="tidak")
						{
							flag[i]=true;	flag[j]=true;
							bisa=false;
						}		
						else
						if (ans=="ya")	return 0;
					}
				}
				if ((bisa)&&(!included[i])&&(!flag[i]))	vec.push_back(i);
		}
		sort(vec.begin(),vec.end());
		vector<long long>::iterator it;
	
		for (it=vec.begin();it!=vec.end();it++)
		{
			if ((contained[*it])||(flag[*it]))	
			{	
				contained[*it]=true;	//contained menyatakan bilangan yang terulang lebih dri 1x
				vec.erase(it);
				it--;
			}
			if (vec.empty()||it==vec.end()) break;
		}
		sort(vec.begin(),vec.end());
		cout<<vec.size();
		for (i=0;i<vec.size();i++)
			cout<<" "<<vec[i];
		cout<<"\n";
		fflush(stdout);
		cin>>ans;
		
		if (ans=="ya") return 0;
		else
		if (ans=="bisajadi")
		{
			for(i=0;i<vec.size();i++)
			{
				cout<<vec.size()-1;
				for (j=0;j<vec.size();j++)
					if (j!=i)
						cout<<" "<<vec[j];
				
				cout<<"\n";
				fflush(stdout);
				cin>>ans;
				
				if (ans=="ya") 
					return 0;
			}
		}
	}
return 0;
}
