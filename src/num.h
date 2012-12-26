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


//PHP_FUNCTION(num_mat2x2);
//PHP_FUNCTION(num_imat2x2);
//
//PHP_FUNCTION(num_mat2x3);
//PHP_FUNCTION(num_imat2x3);
//
//PHP_FUNCTION(num_mat2x4);
//PHP_FUNCTION(num_imat2x4);
//
//
//PHP_FUNCTION(num_mat3x2);
//PHP_FUNCTION(num_imat3x2);
//
//PHP_FUNCTION(num_mat3x3);
//PHP_FUNCTION(num_imat3x3);
//
//PHP_FUNCTION(num_mat3x4);
//PHP_FUNCTION(num_imat3x4);
//
//
//PHP_FUNCTION(num_mat4x2);
//PHP_FUNCTION(num_imat4x2);
//
//PHP_FUNCTION(num_mat4x3);
//PHP_FUNCTION(num_imat4x3);
//
//PHP_FUNCTION(num_mat4x4);
//PHP_FUNCTION(num_imat4x4);



extern zend_module_entry num_module_entry;
#define phpext_num_ptr &num_module_entry

#endif /* PHP_NUM_H */
