n = list(input())
n.sort(reverse=True)

if n[-1] != '0':
  print(-1)

else:
  sum = 0

  for i in n[:-1]:
    sum += int(i)

  if sum % 3 == 0:
    print("".join(n))
  else:
    print(-1)