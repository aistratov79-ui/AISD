w, h, n = map(int, input().split())
l = 0
r = n*10**9
def good(x,w,h,n):
    return (x//w)*(x//h)>=n
while r - l > 1:
    m = (r + l) // 2
    if good(m,w,h,n):
        r = m
    else:
        l = m
print(r)