def SelectionSort(A):
    n = len(A)
    for i in range(n - 1):
        key = A[i]
        ind = i
        for j in range(i + 1, n):
            if A[j] > key:
                key = A[j]
                ind = j
        if i != ind:
            A[i], A[ind] = A[ind], A[i]


numbers = list(map(int, input().split()))
SelectionSort(numbers)
print(*numbers)
