
def main():
    megaArray = [
        [1, 2, 3, 4, 5, 6, 7, 8],
        [9, 10, 11, 12, 13, 14, 15, 16],
        [17, 18, 19, 20, 21, 22, 23, 24],
        [25, 26, 27, 28, 29, 30, 31, 32],
        [33, 34, 35, 36, 37, 38, 39, 40],
        [41, 42, 43, 44, 45, 46, 47, 48],
        [49, 50, 51, 52, 53, 54, 55, 56],
        [57, 58, 59, 60, 61, 62, 63, 64]
    ]
    miniArray = [[0] * 2 for i in range(2)]
    print (megaArray[0][2])
    for i in range(2):
        for j in range(2):
            miniArray[i][j] = input("Enter at index " + str(i) + " " + str(j) + " : " )
    count = 0
    a = 0
    b = 0
    for i in range(8):
        for j in range(8):
            if int(megaArray[i][j]) == int(miniArray[0][0]):
                for k in range(i, i+2 if i+2 < len(megaArray) else i):
                    for l in range(j, j+2 if j+2 < len(megaArray) else j):
                        if int(megaArray[k][l]) == int(miniArray[a][b]):
                            count += 1
                            b += 1
                    a += 1
                    b = 0
                if count == 4:
                    print("Array Found At i = " + str(i) + " & j = " + str(j))
                    return
    print("Array Not Found!")

    # for i in range(2):
    #     for j in range(2):
    #         print(miniArray[i][j])

if __name__ == "__main__":
    main()