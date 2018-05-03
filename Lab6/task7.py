letters = 0
digits = 0

lst = input("Enter Sequence: ")
index = 0
while(index < lst.__len__()):
    if (lst[index].isalpha()):
        letters += 1
    elif (lst[index].isdigit()):
        digits += 1
    index += 1
print("Letters : " , letters)
print("Digits: " , digits)