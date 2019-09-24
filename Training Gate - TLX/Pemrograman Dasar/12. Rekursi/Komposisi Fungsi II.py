def komp(val, times) :
	if times == 1 :
		return val
	else :
		return komp(abs(A * val + B), times - 1)

A, B, K, x = map(int, input().split())

ans = abs(A * komp(x, K) + B)

print(ans)