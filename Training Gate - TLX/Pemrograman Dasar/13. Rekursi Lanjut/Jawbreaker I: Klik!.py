global N, M, X, Y, res

A = []
visited = []
movex = [1, -1, 0, 0]
movey = [0, 0, 1, -1]

res = 0

def inside (i, j) :
	return (i >= 0 and i < N and j >= 0 and j < M)

def dfs (depth, i, j) :
	if (inside(i, j)) :
		if (A[i][j] == A[X][Y] and not visited[i][j]) :
			visited[i][j] = True
			global res
			res += 1

			for it in range (0, 4) :
				nexts_X = i + movex[it]
				nexts_Y = j + movey[it]

				if (inside(nexts_X, nexts_Y)) :
#					print("testing ", depth, " ", nexts_X, nexts_Y)
					dfs (depth + 1, nexts_X, nexts_Y)

N, M = map(int, input().split())

for i in range (0, N) :
	A.append(input().split())
	visited.append([False] * (M + 1))

X, Y = map(int, input().split())

dfs (1, X, Y)
res *= (res - 1)

print(res)