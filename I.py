s1 = input()
s2 = input()

if len(s1) != len(s2):
    print("NO")
else:
    count = {}
    for ch in s1:
        count[ch] = count.get(ch, 0) + 1
    for ch in s2:
        count[ch] = count.get(ch, 0) - 1

    ok = all(v == 0 for v in count.values())
    print("YES" if ok else "NO")
