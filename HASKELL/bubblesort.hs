bubbleSort:: (Ord a) =>  [a] -> Int -> [a]
bubbleSort x 0 = x
bubbleSort x n = bubbleSort (bubbleSortIteration x) (n-1)

bubbleSortIteration :: (Ord a) =>  [a] -> [a]
bubbleSortIteration []  = []
bubbleSortIteration [x] = [x]
bubbleSortIteration (b:c:t)  = if b>c 
        then c : bubbleSortIteration (b:t)
        else b : bubbleSortIteration (c:t) 
