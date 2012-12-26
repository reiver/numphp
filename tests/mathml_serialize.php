<?php

echo "\n\n";
echo 'BEGIN';
echo "\n";

$tests = array();
$tests[] = 2;
$tests[] = 2.0;
$tests[] = 3;
$tests[] = 3.3;
$tests[] = 'x';
$tests[] = 'apple';
$tests[] = true;
$tests[] = false;
$tests[] = null;
$tests[] = array(1,2,3);
$tests[] = num_ivec2(1,2);
$tests[] = num_ivec2(3,4);
$tests[] = num_ivec3(1,2,3);
$tests[] = num_ivec4(1,2,3,4);
$tests[] = num_vec2(1.1, 2.2);
$tests[] = num_vec3(1.1, 2.2, 3.3);
$tests[] = num_vec4(1.1, 2.2, 3.3, 4.4);

foreach ($tests AS $x) {
	echo '====] ', var_export($x,true), "\n";
	echo 'MathML: ', var_export(num_mathml_serialize($x),true), "\n\n";
}

echo "\n";
echo 'END';
echo "\n\n";
