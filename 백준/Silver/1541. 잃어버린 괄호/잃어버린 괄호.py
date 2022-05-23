origin = input()

equation = ""
stack = ""
for i in origin:
  if 48 <= ord(i) and ord(i) <= 57:
    stack += i
  else:
    equation += str(int(stack))
    equation +=i
    stack = ""
else:
  equation += str(int(stack))


equation = equation.split("-")

answer = eval(equation[0])*2
for i in equation:
  answer -= eval(i)

print(answer)

    