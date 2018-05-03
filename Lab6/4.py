get_line = input("Enter Comma Separated Sequence: ")
arr = get_line.split(",")
arr.sort()
res = ""
for i in arr:
    res += str(i)
    res += ","
print(res)