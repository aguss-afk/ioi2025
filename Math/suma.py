a = 11
z = 2
for i in range(40):
    print(a * a, end = " ")
    x = z // 9
    y = z % 9
    print((9 ** 2) * x + (y ** 2), end = " ")
    b = a * a
    c = 0
    for i in str(b):
        c += int(i)
    a *= 10
    a += 1
    b = a
    print(c)
    z += 1
