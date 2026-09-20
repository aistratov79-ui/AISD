n = int(input())
values = [0] * (n + 1)  # 1-индексация

stack = [(1, n)]
counter = n

while stack:
    l, r = stack.pop()
    if l > r:
        continue
    mid = (l + r) // 2
    values[mid] = counter
    counter -= 1
    stack.append((mid + 1, r))
    stack.append((l, mid - 1))

print(*values[1:])
