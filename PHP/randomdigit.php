<?php 
function randomdigit($digits)  {   
  static  $startseed  =  0;   
  if  (!$startseed)  { 
    $startseed  =  (double)microtime()*getrandmax();
    srand($startseed); 
  } 
  $range  =  8; 
  $start  =  1; 
  $i  =  1; 
  while  ($i<$digits)  { 
    $range  =  $range  .  9; 
    $start  =  $start  .  0; 
    $i++; 
  } 
  return  (rand()%$range+$start);   
} 

echo randomdigit(2);
?>
