n = int(input())

city = list()
distance = list()

distance = list(map(int, input().split()))
city = list(map(int, input().split()))

min = city[0]
amount = min*distance[0]
for i in range(1, n-1):
  if min > city[i]:
    min = city[i]
  amount += min*distance[i]

print(amount)