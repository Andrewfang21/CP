S, K = list(map(str, input().split()))

while (S.find(K) != -1) :
	S = S.replace(K, '')

print(S)