n, a, b, w, h = map(int, input().split())

def good(d):
    a1 = a + 2 * d
    b1 = b + 2 * d
    cnt1 = (w // a1) * (h // b1)
    cnt2 = (w // b1) * (h // a1)
    return (cnt1 >= n) or (cnt2 >= n)

l = 0
r = max(w, h) + 1
while r - l > 1:
    m = (l + r) // 2
    if good(m):
        l = m
    else:
        r = m
print(l)