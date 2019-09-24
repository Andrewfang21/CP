#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,Q,i,kanan,kiri,num;
	ios_base::sync_with_stdio(false);
	string dummy;
	cin>>dummy;
	cin>>N>>Q;
	kiri=1;		kanan=N;
	for (i=1;i<=Q;i++)
	{
		cin>>num;
		if ((num-kiri)>=(kanan-num))
		{
			cout<<"TERLALU BESAR\n";
			fflush(stdout);
			kanan=num-1;
		} else
		if ((num-kiri)<(kanan-num))
		{
			cout<<"TERLALU KECIL\n";
			fflush(stdout);
			kiri=num+1;
		}
	}
return 0;
}
