from functools import cmp_to_key

arr = []
while True:
    try:
        line = input()
    except EOFError:
        break
    if line == "":
        break
    arr.append(line)


def compare(a, b):
    if a + b > b + a:
        return -1
    elif a + b < b + a:
        return 1
    else:
        return 0


arr.sort(key=cmp_to_key(compare))
print("".join(arr))
