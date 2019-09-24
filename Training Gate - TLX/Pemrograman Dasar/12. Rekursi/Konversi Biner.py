import collections
S = collections.deque()

def konv (num) :
	if (num == 0) :
		return

	S.appendleft(num % 2)
	konv (num // 2)

N = int(input())

konv(N)

for i in range (0, len(S)) :
	print(S[i], end = "")
print("")
