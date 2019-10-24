# Count sort with a small range
# You may increase "ranged" value to support sorting of larger numbers
ranged = 10

def count_sort(arr):
    count = [0]*ranged
    for i in arr:
        count[i]+=1
    for i in range(0, ranged):
        while (count[i]!=0):
            print(i, end= ', ')
            count[i]-=1

#Insert your array here
count_sort([8,3,7,0,1,3,4,6,5,5])