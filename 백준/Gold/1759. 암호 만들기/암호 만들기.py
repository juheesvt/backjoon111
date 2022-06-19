L, C = map(int, input().split())
alpha = list(map(str, input().split()))
out = []
all_out = []
alpha.sort()

def solve(depth, idx, L, C):
    if depth == L:
        all_out.append(''.join(map(str, out)))
        return
    for i in range(idx, C):
        out.append(alpha[i])
        solve(depth+1, i+1, L, C)
        out.pop()

def password(list_check):
    for i in list_check:
        cons = 0
        vow = 0
        for j in i:
            if j in 'aeiou':
                cons += 1
            else:
                vow += 1
        if cons >= 1 and vow >= 2:
            print(i)
    return

solve(0, 0, L, C)
password(all_out)