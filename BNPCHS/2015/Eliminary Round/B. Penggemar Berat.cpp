#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int TC;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i ++) {
		int N;
		scanf("%d", &N);

		if (N % 2 == 1)
			printf("Kasus #%d: CINTA\n", i);
		else
			printf("Kasus #%d: TIDAK CINTA\n", i);
	}

return 0;	
}