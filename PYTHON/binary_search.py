# Returns index of target in array(sorted) if present, else -1 
def binary_search_recursive(array, l, r, target):
    if l == r: 
        if array[l] != target:
            return -1
        else:
            return l 
    else:
        mid = int((l+r)/2)
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            return binary_search_recursive(array, mid+1, r, target)
        else:
            return binary_search_recursive(array, l, mid-1, target)            

def binary_search_iterative(array, target):
    l, r = 0, len(array)-1
    while l<=r:
        mid = int((l+r)/2)
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            l = mid+1
        else:
            r = mid-1
    return -1        
            
def binary_search_iterative_right_most(array, target):
    l, r = 0, len(array)-1
    out = -1
    while l<=r:
        mid = int((l+r)/2)
        if array[mid] == target:
            out = mid
            l = mid + 1
        elif array[mid] < target:
            l = mid+1
        else:
            r = mid-1            
    return out
    
def binary_search_iterative_left_most(array, target):
    l, r = 0, len(array)-1
    out = -1
    while l<=r:
        mid = int((l+r)/2)
        if array[mid] == target:
            out = mid
            r = mid - 1
        elif array[mid] < target:
            l = mid+1
        else:
            r = mid-1            
    return out    
            
array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
array_with_dup = [1, 2, 2, 2, 3, 3, 3, 4, 4, 5]
print(binary_search_recursive(array, 0, len(array)-1, 7))
print(binary_search_iterative(array, 10))
print(binary_search_iterative_right_most(array_with_dup, 3))
print(binary_search_iterative_left_most(array_with_dup, 4))