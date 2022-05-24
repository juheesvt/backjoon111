T = int(input())

button = [[0,300], [0,60], [0,10]]

time = 0

for i, b in enumerate(button):
  t = b[1]
  if T > 0:
    if T >= t:
      time += t*(T//t)
      button[i][0] += (T//t)
      T-= t*(T//t)

if T != 0:
  print(-1)
else:
  for i in range(3):
    print(button[i][0], end=" ")
