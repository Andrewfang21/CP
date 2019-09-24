A = []
used = []

def permute (depth, last) :
	if (depth == K) :
		print(*A[0 : -1], sep = " ")
	else :
		for i in range (last, N + 1) :
			if (not used[i]) :
				used[i] = True
				A[depth] = i

				permute (depth + 1, i + 1)
				used[i] = False

N, K = map(int, input().split())
A = [0] * (K + 1)
used = [False] * (N + 1)

permute (0, 1)