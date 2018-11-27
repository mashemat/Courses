BEGIN{printf"PID"; printf"     "; printf"PPID"; printf"  ";    printf"STATUS"; printf"    "; print"CMD"; } 
$0~pr {if ($4!="awk"){ printf$1; printf"    "; printf$2; printf"    ";    printf$3; printf"    "; print$4;  } }
