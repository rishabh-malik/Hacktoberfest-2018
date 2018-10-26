<?php #  Permutation Generator ?>

<? 
function permutations($letters,$num){ 
    $last = str_repeat($letters{0},$num); 
    $result = array(); 
    while($last != str_repeat(lastchar($letters),$num)){ 
        $result[] = $last; 
        $last = char_add($letters,$last,$num-1); 
    } 
    $result[] = $last; 
    return $result; 
} 
function char_add($digits,$string,$char){ 
    if($string{$char} <> lastchar($digits)){ 
        $string{$char} = $digits{strpos($digits,$string{$char})+1}; 
        return $string; 
    }else{ 
        $string = changeall($string,$digits{0},$char); 
        return char_add($digits,$string,$char-1); 
    } 
} 
function lastchar($string){ 
    return $string{strlen($string)-1}; 
} 
function changeall($string,$char,$start = 0,$end = 0){ 
    if($end == 0) $end = strlen($string)-1; 
    for($i=$start;$i<=$end;$i++){ 
        $string{$i} = $char; 
    } 
    return $string; 
} 
?> 

<?php #  Use of the generator: ?>

<? 
$Array=permutations("ABC",3); 
for($i=0 ; $i < count($Array) ; $i++) { 
        echo "$i." . $Array[$i] . "<BR>"; 
} 
?> 

<?php

# The output would look like this : 

# 0.AAA 
# 1.AAB 
# 2.AAC 
# 3.ABA 
# 4.ABB 
# 5.ABC 
# 6.ACA 
# 7.ACB 
# 8.ACC 
# 9.BAA 
# 10.BAB 
# 11.BAC 
# 12.BBA 
# 13.BBB 
# 14.BBC 
# 15.BCA 
# 16.BCB 
# 17.BCC 
# 18.CAA 
# 19.CAB 
# 20.CAC 
# 21.CBA 
# 22.CBB 
# 23.CBC 
# 24.CCA 
# 25.CCB 
# 26.CCC 

?>
