<?php

function bubble_sort($arr) {
    $size = count($arr);
    for ($i=0; $i<$size; $i++) {
        for ($j=0; $j<$size-1-$i; $j++) {
            if ($arr[$j+1] < $arr[$j]) {
                swap($arr, $j, $j+1);
            }
        }
    }
    return $arr;
}

function swap(&$arr, $a, $b) {
    $tmp = $arr[$a];
    $arr[$a] = $arr[$b];
    $arr[$b] = $tmp;
}

/* test bubble sort */

$arr = array(1,3,2,8,5,7,4,0);

print("Before sorting");
print_r($arr);

$arr = bubble_sort($arr);
print("After sorting by using bubble sort");
print_r($arr);

?>
