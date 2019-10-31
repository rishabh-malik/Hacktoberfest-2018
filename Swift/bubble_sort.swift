// Bubble sort algorithm 

// Input elements: array that implement the comparable protocol

public func bubbleSort<T> (_ elements: [T]) -> [T] where T: Comparable {
  return bubbleSort(elements, <)
}

public func bubbleSort<T> (_ elements: [T], _ comparison: (T,T) -> Bool) -> [T]  {
  var array = elements
  
  for i in 0..<array.count {
    for k in 1..<array.count-i {
      if comparison(array[k], array[k-1]) {
        let temp = array[k-1]
        array[k-1] = array[k]
        array[k] = temp
      }
    }
  }
  
  return array
}
