A = []
used = []
count = 0

def printf () :
	valid = True
	for i in range (1, N - 1) :
		if (A[i] > A[i - 1] and A[i] > A[i + 1]) or (A[i] < A[i - 1] and A[i] < A[i + 1]) :
			continue
		else :
			valid = False
			break

	if (valid) :
		print(*A[0 : -1], sep = "")
"""		global count
		count += 1
"""
def permute (depth) :
	if (depth == N) :
		printf ()
		return
	else :
		for i in range (1, N + 1) :
			if (not used[i]) :
				if (depth > 1) :
					if (A[depth - 1] > A[depth - 2] and i > A[depth - 1]) or (A[depth - 1] < A[depth - 2] and i < A[depth - 1]) :
						continue
					else :
						used[i] = True
						A[depth] = i

						permute(depth + 1)
						used[i] = False
				else :
					used[i] = True
					A[depth] = i

					permute(depth + 1)
					used[i] = False

N = int(input())
used = [False] * (N + 1)
A = [0] * (N + 1)

permute (0)
#print(count)