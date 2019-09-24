S = str(input())
K = int(input())

up = ord('z')
low = ord('a')

temp = []
for i in range (0, len(S)) :
	curr = ord(S[i]) + K

	if (curr > up) :
		curr = curr + low - up - 1

	temp.append(chr(curr))

for i in range (0, len(S)) :
	print(temp[i], end = "")
print("")