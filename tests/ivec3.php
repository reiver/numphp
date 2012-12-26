<?php

echo "\n\n";
echo 'BEGIN';
echo "\n";

$ivec3 = num_ivec3( 1
                  , 2
                  , 3
                  );

echo 'ivec3: ', var_export($ivec3,true), "\n";

echo 'get_resource_type() = ', get_resource_type($ivec3), "\n";

echo "\n";
echo 'END';
echo "\n\n";
