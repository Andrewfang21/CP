#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x1,x2,y1,y2,r1,r2;
	double dist,EPS=1e-18;
	
	cin>>x1>>y1>>r1;
	cin>>x2>>y2>>r2;
	
	dist=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	
	if (dist-EPS>(r1 + r2) || dist<r1-EPS)
		cout<<"tidak bersentuhan\n";
	else
		cout<<"bersentuhan\n";
		
return 0;
}
