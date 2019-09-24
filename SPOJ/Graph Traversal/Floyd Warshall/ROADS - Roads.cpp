#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define sec second
#pragma GCC Optimize ("O3")
using namespace std;
int N,M;
double D,dist[105][105],INF=pow(10,19),EPS=10e-15;
pair<double, pair<int, int> >edge[10005];

void reset()
{
	int i,j,k;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			dist[i][j]=INF;
}

double Floyd_Warshall()
{
	int i,j,k;

	for (k=0;k<N;k++)
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
			{
				if (i==j)
					dist[i][j]=0.000;
				else
					dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}

return dist[0][N-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);			cout.tie(0);
	
	while(cin>>N>>M>>D)
	{
        if(N+M+D==0)
            return 0;
        int i;
        for (i=1;i<=M;i++)
        {
            int a,b;
            double c;

            cin>>a>>b>>c;
            edge[i]=mp(c,mp(a,b));
        }

        double res,left,right,pivot;
        left=0.00;				right=INF;

        for (int it=1;it<=150;it++)
        {
            pivot=(left+right)/2.0;

            reset();
            for (i=1;i<=M;i++)
            {
                double koef,jarak;
                int from,to;
                koef=edge[i].fi;
                from=edge[i].sec.fi;		to=edge[i].sec.sec;

                jarak=(double) pivot/ (double) koef;

                dist[from][to]=dist[to][from]=min(dist[to][from],jarak);

            //	cout<<from<<" "<<to<<"   "<<dist[from][to]<<"\n";
            }

            double temp=Floyd_Warshall();

        //	cout<<pivot<<"  "<<temp<<" "<<D<<"\n";

            if (temp-D>=EPS)
                right=pivot;
            else
            if (temp-D<=EPS)
                left=pivot;
        }
        res=pivot;
        cout<<setprecision(2)<<fixed<<res<<"\n";
	}
return 0;
}
