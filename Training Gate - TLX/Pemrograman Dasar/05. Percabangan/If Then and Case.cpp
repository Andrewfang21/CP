#include<bits/stdc++.h>
using namespace std;
string num;

int main()
{
	cin>>num;
	if (num.length()==1) cout<<"satuan\n"; else
	if (num.length()==2) cout<<"puluhan\n"; else
	if (num.length()==3) cout<<"ratusan\n"; else
	if (num.length()==4) cout<<"ribuan\n"; else
	if (num.length()==5) cout<<"puluhribuan\n";
return 0;	
}

