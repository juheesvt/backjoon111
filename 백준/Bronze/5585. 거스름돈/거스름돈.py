money = 1000 - int(input())

cnt =0
if money >= 500:
  cnt += money//500
  money -= money//500*500

if money >= 100:
  cnt += money//100
  money -= money//100*100
  
if money >= 50:
  cnt += money//50
  money -= money//50*50
  
if money >= 10:
  cnt += money//10
  money -= money//10*10
  
if money >= 5:
  cnt += money//5
  money -= money//5*5
  
if money >= 1:
  cnt += money//1
  money -= money//1*1

print(cnt)