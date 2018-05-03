num = input("Enter Number of Dictionary: ")
dict = {}

for i in range(int(num)):
    res = str(i)
    res1 = str(i*i)
    dict[res] = res1

print(dict)