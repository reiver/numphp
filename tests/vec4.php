<?php

echo "\n\n";
echo 'BEGIN';
echo "\n";

$vec4 = num_vec4( 1
                , 2
                , 3
                , 4
                );

echo 'vec4: ', var_export($vec4,true), "\n";

echo 'get_resource_type() = ', get_resource_type($vec4), "\n";

echo "\n";
echo 'END';
echo "\n\n";
