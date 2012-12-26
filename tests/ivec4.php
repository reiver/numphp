<?php

echo "\n\n";
echo 'BEGIN';
echo "\n";

$ivec4 = num_ivec4( 1
                  , 2
                  , 3
                  , 4
                  );

echo 'ivec4: ', var_export($ivec4,true), "\n";

echo 'get_resource_type() = ', get_resource_type($ivec4), "\n";

echo "\n";
echo 'END';
echo "\n\n";
