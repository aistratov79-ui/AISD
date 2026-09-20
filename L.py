km = sorted(map(int, input().split()))
price = sorted(map(int, input().split()), reverse=True)

summa = 0
for i in range(len(km)):
    summa += km[i] * price[i]

print(summa)
