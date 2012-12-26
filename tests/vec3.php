<?php

echo "\n\n";
echo 'BEGIN';
echo "\n";

$vec3 = num_vec3( 1
                , 2
                , 3
                );

echo 'vec3: ', var_export($vec3,true), "\n";

echo 'get_resource_type() = ', get_resource_type($vec3), "\n";

echo "\n";
echo 'END';
echo "\n\n";
