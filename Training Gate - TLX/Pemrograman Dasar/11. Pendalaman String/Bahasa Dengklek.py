S = str(input())

temp = []
for i in range(0, len(S)) :
	if (ord(S[i]) >= ord('a')) :
		temp.append(chr(ord(S[i]) - 32))
	else :
		temp.append(chr(ord(S[i]) + 32))

for i in range(0, len(temp)) :
	if (i == len(temp) - 1) :
		print(temp[i])
	else :
		print(temp[i], end = "")