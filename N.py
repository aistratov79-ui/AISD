A, K, B, M, X = map(int, input().split())
def good(days):
    cut = (days - days // K) * A + (days - days // M) * B
    return cut >= X

l = 0
r = 2 * 10**18
while r - l > 1:
    mid = (l + r) // 2
    if good(mid):
        r = mid
    else:
        l = mid
print(r)