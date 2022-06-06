START = 0
END = 1

n = int(input())

flower = list()
for i in range(n):
  tmp = list(map(int, input().split()))
  flower.append([tmp[0]*100 + tmp[1], tmp[2]*100 + tmp[3]])
  # flower.append([int(str(tmp[0])+ str(tmp[1])), int(str(tmp[2]) + str(tmp[3]))])

flower.sort()

# 현재 피어있는 꽃이 지는 날 보다 먼저 피는 꽃 중 가장 지는날이 늦은 날을 고르기

tmp_end = 0
idx = 0
cnt = 0
result_flag = True

end = 301
while end < 1131 and idx <= n:
  flag = False
  

  for i in range(idx, n):
    if flower[i][START] > end:
      break

    if tmp_end < flower[i][END]:
      flag = True
      tmp_end = flower[i][END]
      idx = i

  if flag:
    end = tmp_end
    cnt +=1
  else:
    result_flag = False
    break

  idx += 1

if not result_flag:
  print(0)
else:
  print(cnt)
        
  





  
      


