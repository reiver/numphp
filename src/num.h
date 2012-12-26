/*
	Author: Charles Iliya Krempeaux  <charles@reptile.ca>
*/


#ifndef PHP_NUM_H
#define PHP_NUM_H 1

#define PHP_NUM_VERSION "1.0"
#define PHP_NUM_EXTNAME "num"

#include "php.h"





PHP_FUNCTION(num_test);

PHP_FUNCTION(num_mathml_out);
PHP_FUNCTION(num_mathml_in);

PHP_FUNCTION(num_vec2);
PHP_FUNCTION(num_ivec2);

PHP_FUNCTION(num_vec3);
PHP_FUNCTION(num_ivec3);

PHP_FUNCTION(num_vec4);
PHP_FUNCTION(num_ivec4);





extern zend_module_entry num_module_entry;
#define phpext_num_ptr &num_module_entry

#endif /* PHP_NUM_H */
