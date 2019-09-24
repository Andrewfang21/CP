S = str(input())

letter = ''
length = len(S)

ans = []
# Snake Case
if (S.find('_') != -1) :
	for i in range (0, length) :
		if (S[i] == '_') :
			if (S[i + 1] >= 'a') :
				letter = chr(ord(S[i + 1]) - 32)
			else :
				letter = S[i]
		else :
			letter = S[i]

		if (i > 0 and S[i - 1] == '_' and S[i] >='a') :
			continue

		if (letter != '_') :
			ans.append(letter)
else :
	for i in range (0, length) :
		if (S[i] >='A' and S[i] <= 'Z') :
			letter = chr(ord(S[i]) + 32)
			ans.append('_' + letter)
			continue
		else :
			ans.append(S[i])

for i in range (0, len(ans)) :
	if (i == len(ans) - 1) :
		print(ans[i])
	else :
		print(ans[i], end = "")	