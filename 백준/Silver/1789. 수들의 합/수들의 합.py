s = int(input())

n = 0
sum = 0

for i in range(1, s+1):
  n = i
  sum += n
    
  if sum > s:
    n -= 1
    break

print(n)