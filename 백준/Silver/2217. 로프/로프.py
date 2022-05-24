num = int(input())

ropes = list()
for i in range(num):
  ropes.append(int(input()))

ropes.sort(reverse=True)

max = 0


for i in range(len(ropes)):
  if max < (i+1)*ropes[i]:
    max = (i+1)*ropes[i]


print(max)