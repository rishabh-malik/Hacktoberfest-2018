def efficient_Pal():
    pal = input("Enter a string: ")
    length = len(pal)
    for i in range(length/2):
        if pal[i] != pal[length-i-1]:
            return False
    return True
