def fakt (num) :
	if (num == 1) :
		return 1
	if (num & 1 == 0) :
		return (num // 2) * fakt(num - 1)
	return num * fakt(num - 1)

N = int(input())

print(fakt(N))