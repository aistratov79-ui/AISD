<h1 align="center">Лабораторная работа: Базовые алгоритмы сортировки и поиска</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Python-3.10+-blue?style=flat-square&logo=python" alt="Python Version" />
  <img src="https://img.shields.io/badge/Status-Completed-success?style=flat-square" alt="Status" />
  <img src="https://img.shields.io/badge/Algorithms-Sorting-orange?style=flat-square" alt="Topic" />
</p>

## Оглавление и навигация

| № | Название задачи | Алгоритм / Метод | Временная сложность | Код решения |
|---|-----------------|------------------|:-------------------:|:-----------:|
| 111156 | [Сортировка выбором](#задача-111156-сортировка-выбором) | Selection Sort | $O(n^2)$ | [`task_111156.py`](./src/task_111156.py) |
| 111157 | [Сортировка вставкой](#задача-111157-сортировка-вставкой) | Insertion Sort | $O(n^2)$ | [`task_111157.py`](./src/task_111157.py) |
| 111158 | [Сортировка пузырьком](#задача-111158-сортировка-пузырьком) | Bubble Sort | $O(n^2)$ | [`task_111158.py`](./src/task_111158.py) |
| 1411 | [Количество обменов пузырька](#задача-1411-сортировка-пузырьком) | Swap Counting | $O(n^2)$ | [`task_1411.py`](./src/task_1411.py) |
| 766 | [Сортировка слиянием](#задача-766-сортировка-слиянием) | Merge Sort | $O(n \log n)$ | [`task_766.py`](./src/task_766.py) |
| 733 | [Быстрая сортировка](#задача-733-быстрая-сортировка) | Quick Sort | $O(n \log n)$ | [`task_733.py`](./src/task_733.py) |
| 111166 | [Сортировка подсчетом](#задача-111166-сортировка-подсчетом) | Counting Sort | $O(n + k)$ | [`task_111166.py`](./src/task_111166.py) |
| 325 | [Сортировка точек](#задача-325-сортировка-точек) | Custom Struct / Sort | $O(n \log n)$ | [`task_325.py`](./src/task_325.py) |
| 1406 | [Анаграммы](#задача-1406-анаграммы) | Frequency Dict | $O(n)$ | [`task_1406.py`](./src/task_1406.py) |
| 411 | [Число](#задача-411-число) | Custom String Sort | $O(n^2)$ | [`task_411.py`](./src/task_411.py) |
| 665 | [Анти-QuickSort](#задача-665-анти-quicksort) | Adversarial Permutation | $O(n)$ | [`task_665.py`](./src/task_665.py) |
| 111162 | [Такси](#задача-111162-такси) | Greedy Matching | $O(n \log n)$ | [`task_111162.py`](./src/task_111162.py) |

---

## Задачи и решения

<details>
<summary><b>Задача №111156. Сортировка выбором</b></summary>

### Условие
Дан список целых чисел. Выведите все элементы этого списка в порядке невозрастания значений. Выведите новый список на экран. Решение оформите в виде функции `SelectionSort(A)`.

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `1 4 2 3 4` | `4 4 3 2 1` |

### Решение
```python
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
```
</details>

<details>
<summary><b>Задача №111157. Сортировка вставкой</b></summary>

### Условие
Дан список целых чисел. Отсортируйте его в порядке неубывания значений. Решение оформите в виде функции `InsertionSort(A)`. Дополнительным списком пользоваться запрещено.

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `1 4 2 3 4` | `1 2 3 4 4` |

### Решение
```python
def InsertionSort(A):
    n = len(A)
    for i in range(1, n):
        key = A[i]
        j = i
        while j >= 1 and A[j - 1] > key:
            A[j] = A[j - 1]
            j -= 1
        A[j] = key

numbers = list(map(int, input().split()))
InsertionSort(numbers)
print(*numbers)
```
</details>

<details>
<summary><b>Задача №111158. Сортировка пузырьком</b></summary>

### Условие
Дан список целых чисел. Отсортируйте его в порядке невозрастания значений. Решите задачу при помощи алгоритма пузырьковой сортировки в виде функции `BubbleSort(A)`.

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `1 4 2 3 4` | `4 4 3 2 1` |

### Решение
```python
def BubbleSort(A):
    n = len(A)
    for iter in range(n - 1):
        swapped = False
        for i in range(n - iter - 1):
            if A[i] < A[i + 1]:
                A[i], A[i + 1] = A[i + 1], A[i]
                swapped = True
        if not swapped:
            break

num = list(map(int, input().split()))
BubbleSort(num)
print(*num)
```
</details>

<details>
<summary><b>Задача №1411. Сортировка пузырьком</b></summary>

### Условие
Определите, сколько обменов сделает алгоритм пузырьковой сортировки по возрастанию для данного массива.

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `5`<br>`1 2 3 4 5` | `0` |
| `5`<br>`5 4 3 2 1` | `10` |

### Решение
```python
def BubbleSortCount(A):
    n = len(A)
    cnt = 0
    for iter in range(n - 1):
        swapped = False
        for i in range(n - iter - 1):
            if A[i] > A[i + 1]:
                A[i], A[i + 1] = A[i + 1], A[i]
                swapped = True
                cnt += 1
        if not swapped:
            break
    return cnt

N = int(input())
arr = list(map(int, input().split()))
print(BubbleSortCount(arr))
```
</details>

<details>
<summary><b>Задача №766. Сортировка слиянием</b></summary>

### Условие
Отсортируйте данный массив по неубыванию с использованием сортировки слиянием ($N \le 10^5$).

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `2`<br>`3 1` | `1 3` |

### Решение
```python
import sys
sys.setrecursionlimit(200000)

def mergesort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = mergesort(arr[:mid])
    right = mergesort(arr[mid:])
    return merge(left, right)

def merge(left, right):
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

N = int(input())
arr = list(map(int, input().split()))
print(*mergesort(arr))
```
</details>

<details>
<summary><b>Задача №733. Быстрая сортировка</b></summary>

### Условие
Отсортируйте массив по неубыванию с использованием алгоритма быстрой сортировки ($N \le 10^5$).

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `2`<br>`3 1` | `1 3` |

### Решение
```python
import sys
from random import randint
sys.setrecursionlimit(200000)

def quick_sort(arr, left, right):
    if left < right:
        pivot = arr[randint(left, right)]
        l, r = left, right
        while l <= r:
            while arr[l] < pivot:
                l += 1
            while arr[r] > pivot:
                r -= 1
            if l <= r:
                arr[l], arr[r] = arr[r], arr[l]
                l += 1
                r -= 1
        if left < r:
            quick_sort(arr, left, r)
        if right > l:
            quick_sort(arr, l, right)

N = int(input())
arr = list(map(int, input().split()))
quick_sort(arr, 0, N - 1)
print(*arr)
```
</details>

<details>
<summary><b>Задача №111166. Сортировка подсчетом</b></summary>

### Условие
Дан список из $N$ ($N \le 2 \cdot 10^5$) элементов со значениями от $0$ до $100$. Отсортируйте его за $O(n)$ без использования встроенных сортировок. Функция `CountSort(A)` должна модифицировать переданный список.

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `7 3 4 2 5` | `2 3 4 5 7` |

### Решение
```python
def CountSort(A):
    if not A:
        return A
    max_val = max(A)
    counter = [0] * (max_val + 1)
    for x in A:
        counter[x] += 1
    
    idx = 0
    for num in range(max_val + 1):
        while counter[num] > 0:
            A[idx] = num
            idx += 1
            counter[num] -= 1
    return A

arr = list(map(int, input().split()))
CountSort(arr)
print(*arr)
```
</details>

<details>
<summary><b>Задача №325. Сортировка точек</b></summary>

### Условие
Выведите исходные точки в порядке возрастания их расстояний от начала координат. Создайте структуру `Point` и сохраните точки в массиве структур.

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `2`<br>`1 2`<br>`2 3` | `1 2`<br>`2 3` |

### Решение
```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

n = int(input())
points = []
for _ in range(n):
    x, y = map(int, input().split())
    points.append(Point(x, y))

points.sort(key=lambda p: p.x**2 + p.y**2)

for p in points:
    print(p.x, p.y)
```
</details>

<details>
<summary><b>Задача №1406. Анаграммы</b></summary>

### Условие
Определите, являются ли две строки анаграммами друг друга. Ограничение по времени: строго $O(n)$. Встроенные сортировки запрещены.

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `sharm`<br>`marsh` | `YES` |
| `ananas`<br>`nnaass` | `NO` |

### Решение
```python
s1 = input().strip()
s2 = input().strip()

if len(s1) != len(s2):
    print("NO")
else:
    freq = {}
    for ch in s1:
        freq[ch] = freq.get(ch, 0) + 1
    
    is_anagram = True
    for ch in s2:
        if ch not in freq or freq[ch] == 0:
            is_anagram = False
            break
        freq[ch] -= 1
    
    print("YES" if is_anagram else "NO")
```
</details>

<details>
<summary><b>Задача №411. Число</b></summary>

### Условие
Составьте из набора строк с цифрами максимально возможное число, склеивая их в оптимальном порядке.

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `2`<br>`20`<br>`004`<br>`66` | `66220004` |
| `3` | `3` |

### Решение
```python
arr = []
while True:
    try:
        line = input().strip()
    except EOFError:
        break
    if not line:
        break
    arr.append(line)

for i in range(len(arr)):
    for j in range(len(arr) - i - 1):
        if arr[j] + arr[j + 1] < arr[j + 1] + arr[j]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]

print("".join(arr))
```
</details>

<details>
<summary><b>Задача №665. Анти-QuickSort</b></summary>

### Условие
Сгенерируйте перестановку чисел от $1$ до $N$, на которой алгоритм быстрой сортировки (с выбором среднего опорного элемента) совершает максимальное количество сравнений ($N \le 70\,000$).

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `1` | `1` |
| `3` | `1 3 2` |

### Решение
```python
n = int(input())
a = list(range(1, n + 1))
for i in range(2, n):
    mid = i // 2
    a[i], a[mid] = a[mid], a[i]

print(*a)
```
</details>

<details>
<summary><b>Задача №111162. Такси</b></summary>

### Условие
Сопоставьте расстояния до домов сотрудников и тарифы водителей такси таким образом, чтобы итоговая сумма оплаты была минимальной.

### Примеры
| Входные данные | Выходные данные |
|:---|:---|
| `10 20 30`<br>`50 20 30` | `1700` |

### Решение
```python
km = sorted(list(map(int, input().split())))
price = sorted(list(map(int, input().split())), reverse=True)

summa = sum(k * p for k, p in zip(km, price))
print(summa)
```
</details>
