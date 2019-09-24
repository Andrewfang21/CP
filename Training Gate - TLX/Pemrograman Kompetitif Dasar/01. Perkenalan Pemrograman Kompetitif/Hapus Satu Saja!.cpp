#include<bits/stdc++.h>
using namespace std;
int i,j,beda;
string a,b;
bool boo;

int main()
{
	cin>>a>>b;
	for (i=0;i<a.length();i++)
	{
		if(a[i]==b[j]) j++; else beda++;
	}
	if (beda>1) boo=true;
	if (beda==0) boo=true;
	if (j!=b.length()) boo=true;
	if (boo) cout<<"Wah, tidak bisa :(\n"; else cout<<"Tentu saja bisa!\n";
return 0;	
}
