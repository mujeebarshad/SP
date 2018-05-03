num_list = []
for i in range(2000, 3200):
    if i % 7 ==0:
        if i % 5 != 0:
            num_list.append(i)

res = ""
for j in num_list:
    res += str(j)
    res += ","

print(res)