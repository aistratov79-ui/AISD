N, K = map(int, input().split())
a = list(map(int, input().split()))


def can_place(a, k, dist):
    count = 1
    last_point = a[0]

    for point in a:
        if last_point + dist > point:
            continue
        else:
            count += 1
            last_point = point

    return count >= k


l = 0
r = a[-1] - a[0] + 1

while l + 1 < r:
    m = (l + r) // 2

    if can_place(a, K, m):
        l = m
    else:
        r = m

print(l)