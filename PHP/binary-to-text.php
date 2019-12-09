<? 
function bin2text($bin_str) 
{ 
    $text_str = ''; 
    $chars = explode("\n", chunk_split(str_replace("\n", '', $bin_str), 8)); 
    $_I = count($chars); 
    for($i = 0; $i < $_I; $text_str .= chr(bindec($chars[$i])), $i  ); 
    return $text_str; 
} 

function text2bin($txt_str) 
{ 
    $len = strlen($txt_str); 
    $bin = ''; 
    for($i = 0; $i < $len; $i  ) 
    { 
        $bin .= strlen(decbin(ord($txt_str[$i]))) < 8 ? str_pad(decbin(ord($txt_str[$i])), 8, 0, STR_PAD_LEFT) : decbin(ord($txt_str[$i])); 
    } 
    return $bin; 
} 
print text2bin('Hello, world!'); 
?>
