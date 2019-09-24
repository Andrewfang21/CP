S1 = str(input())
S2 = str(input())
S3 = str(input())
S4 = str(input())


S1 = S1.replace(S2, '')

idx = S1.find(S3) + len(S3)

S1 = S1[:idx] + S4 + S1[idx:]

print(S1)