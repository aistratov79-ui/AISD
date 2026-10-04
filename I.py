n = int(input())
arr1 = list(map(int, input().split()))
m = int(input())
arr2 = list(map(int, input().split()))
arr1.sort()


def first_(arr, x):
    l = -1
    r = len(arr)
    while r - l > 1:
        mid = (r + l) // 2
        if arr[mid] < x:
            l = mid
        else:
            r = mid
    if r == n or arr[r] != x:
        return -1
    return r


def last_(arr, x):
    l = -1
    r = len(arr)
    while r - l > 1:
        mid = (r + l) // 2
        if arr[mid] <= x:
            l = mid
        else:
            r = mid
    if l == -1 or arr[l] != x:
        return -1
    return l


ans = []
for i in arr2:
    first = first_(arr1, i)
    if first == -1:
        ans.append(0)
    else:
        last = last_(arr1, i)
        ans.append(last - first + 1)
print(*ans)
