#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int dp[N][N];

void solve(string A, string B) {
     int n = A.length(), m = B.length();

     memset(dp, 0, sizeof(dp));
     for (int i = 0; i <= n; i ++)
          for (int j = 0; j <= m; j ++) {
               if (i == 0)    
                    dp[i][j] = j;
               else if (j == 0)    
                    dp[i][j] = i;
               else if (A[i - 1] == B[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
               else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
          }

     stack<char> st;
     
     int i = n, j = m;
     while (i > 0 && j > 0) {
          if (A[i - 1] == B[j - 1]) {
               st.push(A[i - 1]);
               
               i --;
               j --;
          }
          else if (dp[i - 1][j] < dp[i][j - 1]) {
               st.push(A[i - 1]);
               i --;
          } else {
               st.push(B[j - 1]);
               j --;
          }
     }

     while (i > 0) {
          st.push(A[i - 1]);
          i --;
     }
     while (j > 0) {
          st.push(B[j - 1]);
          j --;
     }

     while (!st.empty()) {
          printf("%c", st.top());
          st.pop();
     }
     puts("");
}

int main() {
     ios_base::sync_with_stdio(false);

     string A, B;
     while (cin >> A >> B) {
          solve(A, B);
     }

return 0;
}