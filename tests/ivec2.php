<?php

echo "\n\n";
echo 'BEGIN';
echo "\n";

$ivec2 = num_ivec2( 1
                  , 2
                  );

echo 'ivec2: ', var_export($ivec2,true), "\n";

echo 'get_resource_type() = ', get_resource_type($ivec2), "\n";

echo "\n";
echo 'END';
echo "\n\n";
