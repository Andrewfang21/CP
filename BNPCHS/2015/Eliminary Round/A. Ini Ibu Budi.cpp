#include <bits/stdc++.h>
using namespace std;

int main() {
	int TC;	
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i ++) {
		int A, B, res;
		scanf("%d %d", &A, &B);

		res = A * B;
		printf("Kasus #%d: %d\n", i, res);	
	}

return 0;    
}