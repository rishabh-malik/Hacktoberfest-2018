-- Heapsort in Haskell

-- | This module provides heapsort for an 'MArray'
-- with indices of 'Integral' type.  See any good
-- algorithms text for a description of heapsort.
-- Heapsort is O(n lg n) comparisons and exchanges
-- in the worst case, and is reasonably efficient.
module Data.Array.MArray.Heapsort (sort)
where

import Control.Monad
import Data.Array.MArray

-- Internally, heap indices are transformed
-- to be zero-based.

left :: (Integral i, Ix i) 
        => i -> i -> i
left n i = 2 * i + 1  

right :: (Integral i, Ix i) 
         => i -> i -> i
right n i = 2 * i + 2

isLeaf :: (Integral i, Ix i) 
          => i -> i -> Bool
isLeaf n i = left n i >= n

-- XXX Returns True when isLeaf is, so
-- use with caution.
isEdge :: (Integral i, Ix i) 
          => i -> i -> Bool
isEdge n i = right n i >= n

atIndex :: (Integral i, Ix i, MArray a e m) 
           => a i e -> i -> m e
atIndex a i = do
  (i0, _) <- getBounds a
  readArray a (i + i0)

exch :: (Integral i, Ix i, MArray a e m) 
        => a i e -> i -> i -> m ()
exch a ix1 ix2 = do
  (i0, _) <- getBounds a
  v1 <- readArray a (ix1 + i0)
  v2 <- readArray a (ix2 + i0)
  writeArray a (ix1 + i0) v2
  writeArray a (ix2 + i0) v1

data Dirn = L | R | N

downHeap :: (Integral i, Ix i, Ord e, MArray a e m) 
            => a i e -> i -> i -> m ()
downHeap a n i = do
  let il = left n i
  let ir = right n i
  c <- atIndex a i
  let exchWith
        | isLeaf n i = return N
        | isEdge n i = do
            l <- atIndex a il
            if c >= l 
              then return N
              else return L
        | otherwise = do
            l <- atIndex a il
            r <- atIndex a ir
            if c >= l && c >= r  
              then return N
              else if l >= r 
                   then return L
                   else return R
  x <- exchWith
  case x of
    L -> do
      exch a i il
      downHeap a n il
    R -> do
      exch a i ir
      downHeap a n ir
    N -> return ()

getN :: (Ix i, Integral i, MArray a e m) 
        => a i e -> m i
getN a = do
  (i0, i1) <- getBounds a
  return (i1 - i0 + 1)

heapify :: (Integral i, Ix i, Ord e, MArray a e m) 
           => a i e -> m ()
heapify a = do
  n <- getN a
  let heapifyRoots i
        | isLeaf n i = 
          return ()
        | isEdge n i = do
            heapifyRoots (left n i)
            downHeap a n i
        | otherwise = do
            heapifyRoots (left n i)
            heapifyRoots (right n i)
            downHeap a n i
  heapifyRoots 0
    

extract :: (Integral i, Ix i, Ord e, MArray a e m) 
           => a i e -> m ()
extract a = do
  let extractRoot k = do
        exch a k 0
        downHeap a k 0
  n <- getN a
  mapM_ extractRoot [n - 1, n - 2 .. 1]

-- | Sort the elements of the given 'MArray' in increasing order.
sort :: (Integral i, Ix i, Ord e, MArray a e m) 
        => a i e -> m ()
sort a = do
  heapify a
  extract a
