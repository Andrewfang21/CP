#include<bits/stdc++.h>
using namespace std;

const int N = 210, INF = 2e9;

int n;
int cap[N][N], par[N];
bool vis[N];

void reset () {
    memset(cap, 0, sizeof(cap));
}

bool BFS (int s, int t) {
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));

    queue<int> Q;
    Q.push(s);

    vis[s] = true;
    par[s] = -1;

    while (!Q.empty()) {
        int pos = Q.front();
        Q.pop();

        if (pos == t)
            break;

        for (int next = 1; next <= n; next ++) {
            if (vis[next] == false && cap[pos][next] > 0) {
                Q.push(next);
                par[next] = pos;
                vis[next] = true;
            }
        }
    }

    for (int node = t; node > -1; node = par[node]) {
        int prev = par[node];
        cap[prev][node] --;
        cap[node][prev] ++;
    }

return (vis[t] == true);
}

void read () {
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j ++) {
            int next;
            scanf("%d", &next);

            cap[i][next] = ((i == 1 || next == n) ? 1 : INF);
        }
    }
}
void solve () {
    int res = 0;
    while (BFS(1, n)) {
        res ++;
    }

    cout << res << "\n";
}

int main() {
    int tc;
    cin >> tc;
 
    while (tc --) {
        reset ();
        read ();
        solve ();
    }

return 0;
}
