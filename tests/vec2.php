<?php

echo "\n\n";
echo 'BEGIN';
echo "\n";

$vec2 = num_vec2( 1
                , 2
                );

echo 'vec2: ', var_export($vec2,true), "\n";

echo 'get_resource_type() = ', get_resource_type($vec2), "\n";

echo "\n";
echo 'END';
echo "\n\n";
