def pal (i, j) :
	if (i >= j) :
		return True

	if (S[i] == S[j]) :
		return pal (i + 1, j - 1)
	else :
		return False

S = input()

if (pal(0, len(S) - 1)) :
	print ("YA")
else :
	print ("BUKAN")