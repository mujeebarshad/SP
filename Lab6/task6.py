get_line = input("Enter Comma Separated Sequence: ")
arr = list(get_line.split(" "))
arr.sort()
res = ""
lst = []
for ele in arr:
    if ele not in lst:
        lst.append(ele)
for i in lst:
    res += str(i)
    res += " "
print(res)
