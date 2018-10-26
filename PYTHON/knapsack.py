def KnapSack(val, wt, n, W): 
      
    # matrix to store final result  
    mat = [[0 for i in range(W + 1)]  
              for i in range(2)] 

    i = 0
    while i < n:
        j = 0

        if i % 2 == 0: 
            while j < W: # check for each value  
                j += 1
                if wt[i] <= j: # include element  
                    mat[1][j] = max(val[i] + mat[0][j - 
                                     wt[i]], mat[0][j]) 
                else: # exclude element 
                    mat[1][j] = mat[0][j] 

        else: 
            while j < W: 
                j += 1
                if wt[i] <= j: 
                    mat[0][j] = max(val[i] + mat[1][j - 
                                     wt[i]], mat[1][j]) 
                else: 
                    mat[0][j] = mat[1][j] 
        i += 1

    if n % 2 == 0: 
        return mat[0][W] 
    else: 
        return mat[1][W] 

val = [7, 8, 4] 
wt = [3, 8, 6]  
W = 10
n = 3
print(KnapSack(val, wt, n, W)) 
