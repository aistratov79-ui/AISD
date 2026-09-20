def InsertionSort(A):
    n = len(A)
    for i in range(1,n):
        key = A[i]
        j = i
        while j >= 1 and A[j-1] > key:
            A[j] = A[j-1]
            j -= 1
        A[j] = key
numbers = list(map(int,input().split()))
InsertionSort(numbers)
print(*numbers)
