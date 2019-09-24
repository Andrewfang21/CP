#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,N,awal,akhir,res,a;
	vector<int>magic;
	cin>>N;
	for (i=0;i<N;i++)
	{
		cin>>a;
		magic.push_back(a);
	}
	sort(magic.begin(),magic.end());
	res=awal=0;	akhir=N-1;
	
	if (N==1)
	{
		cout<<"1\n";
		return 0;
	}
	
	while(awal<=akhir)
	{
		res++;
		awal+=magic[akhir];
		akhir--;	
	}	
	cout<<res<<"\n";
}