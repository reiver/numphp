#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "num.h"

#include "num_types.h"





PHP_MINIT_FUNCTION(num);
PHP_MSHUTDOWN_FUNCTION(num);





static function_entry num_functions[] = {
    PHP_FE(num_test                , NULL)

    PHP_FE(num_mathml_serialize    , NULL)
    PHP_FE(num_mathml_unserialize  , NULL)

    PHP_FE(num_vec2                , NULL)
    PHP_FE(num_ivec2               , NULL)

    PHP_FE(num_vec3                , NULL)
    PHP_FE(num_ivec3               , NULL)

    PHP_FE(num_vec4                , NULL)
    PHP_FE(num_ivec4               , NULL)

    PHP_FE(num_add                 , NULL)
    PHP_FE(num_dimension           , NULL)

    {NULL, NULL, NULL}
};


zend_module_entry num_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_NUM_EXTNAME,
    num_functions,
    PHP_MINIT(num),
    PHP_MSHUTDOWN(num),
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_NUM_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_NUM
ZEND_GET_MODULE(num)
#endif

PHP_INI_BEGIN()
PHP_INI_ENTRY("num.testtext", "The NumPHP test worked!\n", PHP_INI_ALL, NULL)
PHP_INI_END()






PHP_FUNCTION(num_test)
{
    RETURN_STRING(INI_STR("num.testtext"), 1);
}





PHP_FUNCTION(num_vec2)
{
	double x;
	double y;

	php_num_vec2 *vec2;



	if (  FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y)  ) {
		RETURN_NULL();
	}

	vec2 = emalloc( sizeof(php_num_vec2) );

	vec2->x = x;
	vec2->y = y;

	//DEBUG
	//php_printf("x = %f \n", x);
	//php_printf("y = %f \n", y);


	ZEND_REGISTER_RESOURCE(return_value, vec2, le_num_vec2);
}

PHP_FUNCTION(num_ivec2)
{
	long x;
	long y;

	php_num_ivec2 *ivec2;



	if (  FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &x, &y)  ) {
		RETURN_NULL();
	}

	ivec2 = emalloc( sizeof(php_num_ivec2) );

	ivec2->x = x;
	ivec2->y = y;

	//DEBUG
	//php_printf("x = %ld \n", x);
	//php_printf("y = %ld \n", y);


	ZEND_REGISTER_RESOURCE(return_value, ivec2, le_num_ivec2);
}

PHP_FUNCTION(num_vec3)
{
	double x;
	double y;
	double z;

	php_num_vec3 *vec3;



	if (  FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd", &x, &y, &z)  ) {
		RETURN_NULL();
	}

	vec3 = emalloc( sizeof(php_num_vec3) );

	vec3->x = x;
	vec3->y = y;
	vec3->z = z;

	//DEBUG
	//php_printf("x = %f \n", x);
	//php_printf("y = %f \n", y);
	//php_printf("z = %f \n", z);

	ZEND_REGISTER_RESOURCE(return_value, vec3, le_num_vec3);
}

PHP_FUNCTION(num_ivec3)
{
	long x;
	long y;
	long z;

	php_num_ivec3 *ivec3;



	if (  FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lll", &x, &y, &z)  ) {
		RETURN_NULL();
	}

	ivec3 = emalloc( sizeof(php_num_ivec3) );

	ivec3->x = x;
	ivec3->y = y;
	ivec3->z = z;

	//DEBUG
	//php_printf("x = %ld \n", x);
	//php_printf("y = %ld \n", y);
	//php_printf("z = %ld \n", z);

	ZEND_REGISTER_RESOURCE(return_value, ivec3, le_num_ivec3);
}

PHP_FUNCTION(num_vec4)
{
	double x;
	double y;
	double z;
	double w;

	php_num_vec4 *vec4;



	if (  FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &x, &y, &z, &w)  ) {
		RETURN_NULL();
	}

	vec4 = emalloc( sizeof(php_num_vec4) );

	vec4->x = x;
	vec4->y = y;
	vec4->z = z;
	vec4->w = w;

	//DEBUG
	//php_printf("x = %f \n", x);
	//php_printf("y = %f \n", y);
	//php_printf("z = %f \n", y);
	//php_printf("w = %f \n", y);

	ZEND_REGISTER_RESOURCE(return_value, vec4, le_num_vec4);
}

PHP_FUNCTION(num_ivec4)
{
	long x;
	long y;
	long z;
	long w;

	php_num_ivec4 *ivec4;



	if (  FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &x, &y, &z, &w)  ) {
		RETURN_NULL();
	}

	ivec4 = emalloc( sizeof(php_num_ivec4) );

	ivec4->x = x;
	ivec4->y = y;
	ivec4->z = z;
	ivec4->w = w;

	//DEBUG
	//php_printf("x = %ld \n", x);
	//php_printf("y = %ld \n", y);
	//php_printf("z = %ld \n", y);
	//php_printf("w = %ld \n", y);

	ZEND_REGISTER_RESOURCE(return_value, ivec4, le_num_ivec4);
}










static void _php_free_num_ivec2(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    php_num_ivec2 *ivec2 = (php_num_ivec2 *)rsrc->ptr;

    efree(ivec2);
}

static void _php_free_num_ivec3(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    php_num_ivec3 *ivec3 = (php_num_ivec3 *)rsrc->ptr;

    efree(ivec3);
}

static void _php_free_num_ivec4(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    php_num_ivec4 *ivec4 = (php_num_ivec4 *)rsrc->ptr;

    efree(ivec4);
}



static void _php_free_num_vec2(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    php_num_vec2 *vec2 = (php_num_vec2 *)rsrc->ptr;

    efree(vec2);
}

static void _php_free_num_vec3(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    php_num_vec3 *vec3 = (php_num_vec3 *)rsrc->ptr;

    efree(vec3);
}

static void _php_free_num_vec4(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    php_num_vec4 *vec4 = (php_num_vec4 *)rsrc->ptr;

    efree(vec4);
}





PHP_MINIT_FUNCTION(num)
{
    REGISTER_INI_ENTRIES();

    le_num_ivec2 = zend_register_list_destructors_ex(_php_free_num_ivec2, NULL, "num_ivec2", module_number);
    le_num_ivec3 = zend_register_list_destructors_ex(_php_free_num_ivec3, NULL, "num_ivec3", module_number);
    le_num_ivec4 = zend_register_list_destructors_ex(_php_free_num_ivec4, NULL, "num_ivec4", module_number);

    le_num_vec2  = zend_register_list_destructors_ex(_php_free_num_vec2,  NULL, "num_vec2", module_number);
    le_num_vec3  = zend_register_list_destructors_ex(_php_free_num_vec3,  NULL, "num_vec3", module_number);
    le_num_vec4  = zend_register_list_destructors_ex(_php_free_num_vec4,  NULL, "num_vec4", module_number);

    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(num)
{
    UNREGISTER_INI_ENTRIES();

    return SUCCESS;
}
