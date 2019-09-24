#include<bits/stdc++.h>
using namespace std;

int main()
{
	string sub;
	cin>>sub;
	int N;
	
	cin>>N;
	while(N>0)
	{
		cout<<"Anak ayam turunlah "<<N<<"\n";
		N--;
		if (N>0)
			cout<<"Mati satu tinggallah "<<N<<"\n";
	}
	cout<<"Mati satu tinggallah induknya\n";
return 0;
}
