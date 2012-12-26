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





PHP_FUNCTION(num_mathml_serialize)
{
	zval *user_variable;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &user_variable) == FAILURE) {
		RETURN_NULL();
	}

	switch (Z_TYPE_P(user_variable)) {

		case IS_BOOL:
			RETURN_NULL();
		break;

		case IS_NULL:
			RETURN_NULL();
		break;

		case IS_LONG:
		case IS_DOUBLE:
		{
			char *prefix  = "<cn>";
			int   prefix_len;

			char *postfix = "</cn>";
			int   postfix_len;

			char *mem;
			int   mem_len;


			convert_to_string(user_variable);


			prefix_len  = strlen(prefix);
			postfix_len = strlen(postfix);


			mem_len = prefix_len + Z_STRLEN_P(user_variable) + postfix_len;

			mem = emalloc(mem_len);

			memcpy( mem                                          , prefix                    , prefix_len                );
			memcpy( mem + prefix_len                             , Z_STRVAL_P(user_variable) , Z_STRLEN_P(user_variable) );
			memcpy( mem + prefix_len + Z_STRLEN_P(user_variable) , postfix                   , postfix_len               );


/////////// RETURN
			RETURN_STRINGL(mem, mem_len, 0);
		}
		break;

		case IS_STRING:
		{
			char *prefix  = "<ci>";
			int   prefix_len;

			char *postfix = "</ci>";
			int   postfix_len;

			char *mem;
			int   mem_len;


			prefix_len  = strlen(prefix);
			postfix_len = strlen(postfix);


			mem_len = prefix_len + Z_STRLEN_P(user_variable) + postfix_len;

			mem = emalloc(mem_len);

			memcpy( mem                                          , prefix                    , prefix_len                );
			memcpy( mem + prefix_len                             , Z_STRVAL_P(user_variable) , Z_STRLEN_P(user_variable) );
			memcpy( mem + prefix_len + Z_STRLEN_P(user_variable) , postfix                   , postfix_len               );


/////////// RETURN
			RETURN_STRINGL(mem, mem_len, 0);
		}

		case IS_RESOURCE:
		{
			long resource_id = Z_LVAL_P(user_variable);
			//const char *resource_type_name = zend_rsrc_list_get_rsrc_type(resource_id TSRMLS_CC);
			int resource_type_id;

			if (!zend_list_find(resource_id, &resource_type_id)) {
/////////////// RETURN
				RETURN_NULL();
			}

			php_printf("RESOURCE ID: %ld \n", resource_id);
			//php_printf("RESOURCE TYPE NAME: %s \n", resource_type_name);
			php_printf("RESOURCE TYPE ID: %d \n", resource_type_id);

			if        (  resource_type_id == le_num_ivec2  ) {

				php_num_ivec2 *ivec2;

				ZEND_FETCH_RESOURCE(ivec2, php_num_ivec2 *, &user_variable, -1, "num_ivec2", le_num_ivec2);



				char *prefix  = "<vector><cn>";
				int   prefix_len;

				char *middle  = "</cn><cn>";
				int   middle_len;

				char *postfix = "</cn></vector>";
				int   postfix_len;

				char *x_mem;
				int   x_mem_len;

				char *y_mem;
				int   y_mem_len;

				char *mem;
				int   mem_len;


				prefix_len  = strlen(prefix);
				middle_len  = strlen(middle);
				postfix_len = strlen(postfix);

				x_mem_len = snprintf(NULL, 0, "%ld", ivec2->x);
				y_mem_len = snprintf(NULL, 0, "%ld", ivec2->y);

				x_mem = emalloc(x_mem_len+1);
				y_mem = emalloc(y_mem_len+1);

				//snprintf(x_mem, x_mem_len, "%ld", ivec2->x);
				//snprintf(y_mem, y_mem_len, "%ld", ivec2->y);
				sprintf(x_mem, "%ld", ivec2->x);
				sprintf(y_mem, "%ld", ivec2->y);


				mem_len = prefix_len + x_mem_len + middle_len + y_mem_len + postfix_len;

				mem = emalloc(mem_len);

				memcpy( mem                                                   , prefix  , prefix_len  );
				memcpy( mem + prefix_len                                      , x_mem   , x_mem_len   );
				memcpy( mem + prefix_len + x_mem_len                          , middle  , middle_len  );
				memcpy( mem + prefix_len + x_mem_len + middle_len             , y_mem   , y_mem_len   );
				memcpy( mem + prefix_len + x_mem_len + middle_len + y_mem_len , postfix , postfix_len );


				efree(x_mem);
				efree(y_mem);


/////////////// RETURN
				RETURN_STRINGL(mem, mem_len, 0);

			} else if (  resource_type_id == le_num_ivec3  ) {

				php_num_ivec3 *ivec3;

				ZEND_FETCH_RESOURCE(ivec3, php_num_ivec3 *, &user_variable, -1, "num_ivec3", le_num_ivec3);



				char *prefix  = "<vector><cn>";
				int   prefix_len;

				char *middle  = "</cn><cn>";
				int   middle_len;

				char *postfix = "</cn></vector>";
				int   postfix_len;

				char *x_mem;
				int   x_mem_len;

				char *y_mem;
				int   y_mem_len;

				char *z_mem;
				int   z_mem_len;

				char *mem;
				int   mem_len;


				prefix_len  = strlen(prefix);
				middle_len  = strlen(middle);
				postfix_len = strlen(postfix);

				x_mem_len = snprintf(NULL, 0, "%ld", ivec3->x);
				y_mem_len = snprintf(NULL, 0, "%ld", ivec3->y);
				z_mem_len = snprintf(NULL, 0, "%ld", ivec3->z);

				x_mem = emalloc(x_mem_len+1);
				y_mem = emalloc(y_mem_len+1);
				z_mem = emalloc(z_mem_len+1);

				//snprintf(x_mem, x_mem_len, "%ld", ivec3->x);
				//snprintf(y_mem, y_mem_len, "%ld", ivec3->y);
				//snprintf(z_mem, z_mem_len, "%ld", ivec3->z);
				sprintf(x_mem, "%ld", ivec3->x);
				sprintf(y_mem, "%ld", ivec3->y);
				sprintf(z_mem, "%ld", ivec3->z);


				mem_len = prefix_len + x_mem_len + middle_len + y_mem_len + middle_len + z_mem_len + postfix_len;

				mem = emalloc(mem_len);

				memcpy( mem                                                                            , prefix  , prefix_len  );
				memcpy( mem + prefix_len                                                               , x_mem   , x_mem_len   );
				memcpy( mem + prefix_len + x_mem_len                                                   , middle  , middle_len  );
				memcpy( mem + prefix_len + x_mem_len + middle_len                                      , y_mem   , y_mem_len   );
				memcpy( mem + prefix_len + x_mem_len + middle_len + y_mem_len                          , middle  , middle_len  );
				memcpy( mem + prefix_len + x_mem_len + middle_len + y_mem_len + middle_len             , z_mem   , z_mem_len   );
				memcpy( mem + prefix_len + x_mem_len + middle_len + y_mem_len + middle_len + z_mem_len , postfix , postfix_len );


				efree(x_mem);
				efree(y_mem);
				efree(z_mem);


/////////////// RETURN
				RETURN_STRINGL(mem, mem_len, 0);

			} else if (  resource_type_id == le_num_ivec4  ) {

				php_num_ivec4 *ivec4;

				ZEND_FETCH_RESOURCE(ivec4, php_num_ivec4 *, &user_variable, -1, "num_ivec4", le_num_ivec4);



				char *prefix  = "<vector><cn>";
				int   prefix_len;

				char *middle  = "</cn><cn>";
				int   middle_len;

				char *postfix = "</cn></vector>";
				int   postfix_len;

				char *x_mem;
				int   x_mem_len;

				char *y_mem;
				int   y_mem_len;

				char *z_mem;
				int   z_mem_len;

				char *w_mem;
				int   w_mem_len;

				char *mem;
				int   mem_len;


				prefix_len  = strlen(prefix);
				middle_len  = strlen(middle);
				postfix_len = strlen(postfix);

				x_mem_len = snprintf(NULL, 0, "%ld", ivec4->x);
				y_mem_len = snprintf(NULL, 0, "%ld", ivec4->y);
				z_mem_len = snprintf(NULL, 0, "%ld", ivec4->z);
				w_mem_len = snprintf(NULL, 0, "%ld", ivec4->w);

				x_mem = emalloc(x_mem_len+1);
				y_mem = emalloc(y_mem_len+1);
				z_mem = emalloc(z_mem_len+1);
				w_mem = emalloc(w_mem_len+1);

				//snprintf(x_mem, x_mem_len, "%ld", ivec3->x);
				//snprintf(y_mem, y_mem_len, "%ld", ivec3->y);
				//snprintf(z_mem, z_mem_len, "%ld", ivec3->z);
				sprintf(x_mem, "%ld", ivec4->x);
				sprintf(y_mem, "%ld", ivec4->y);
				sprintf(z_mem, "%ld", ivec4->z);
				sprintf(w_mem, "%ld", ivec4->w);


				mem_len = prefix_len + x_mem_len + middle_len + y_mem_len + middle_len + z_mem_len + middle_len + w_mem_len + postfix_len;

				mem = emalloc(mem_len);

				memcpy( mem                                                                                                     , prefix  , prefix_len  );
				memcpy( mem + prefix_len                                                                                        , x_mem   , x_mem_len   );
				memcpy( mem + prefix_len + x_mem_len                                                                            , middle  , middle_len  );
				memcpy( mem + prefix_len + x_mem_len + middle_len                                                               , y_mem   , y_mem_len   );
				memcpy( mem + prefix_len + x_mem_len + middle_len + y_mem_len                                                   , middle  , middle_len  );
				memcpy( mem + prefix_len + x_mem_len + middle_len + y_mem_len + middle_len                                      , z_mem   , z_mem_len   );
				memcpy( mem + prefix_len + x_mem_len + middle_len + y_mem_len + middle_len + z_mem_len                          , middle  , middle_len  );
				memcpy( mem + prefix_len + x_mem_len + middle_len + y_mem_len + middle_len + z_mem_len + middle_len             , w_mem   , w_mem_len  );
				memcpy( mem + prefix_len + x_mem_len + middle_len + y_mem_len + middle_len + z_mem_len + middle_len + w_mem_len , postfix , postfix_len );


				efree(x_mem);
				efree(y_mem);
				efree(z_mem);
				efree(w_mem);


/////////////// RETURN
				RETURN_STRINGL(mem, mem_len, 0);

			} else if (  resource_type_id == le_num_vec2  ) {

				php_num_vec2 *vec2;

			} else if (  resource_type_id == le_num_vec3  ) {

				php_num_vec3 *vec3;

			} else if (  resource_type_id == le_num_vec4  ) {

				php_num_vec4 *vec4;

			} else {

/////////////// RETURN
				RETURN_NULL();
			}


/////////// RETURN
			RETURN_NULL();
		}
		break;

		case IS_ARRAY:
/////////// RETURN
			RETURN_NULL();
		break;

		case IS_OBJECT:
/////////// RETURN
			RETURN_NULL();
		break;

		default:
/////////// RETURN
			RETURN_NULL();
		break;
	}

/// RETURN
	RETURN_NULL();
}

PHP_FUNCTION(num_mathml_unserialize)
{
    char *mathml_str;
    int mathml_str_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &mathml_str, &mathml_str_len) == FAILURE) {
        RETURN_NULL();
    }

    //DEBUG
    //php_printf("MathML code: %s", mathml_str);

// ############# TODO
    RETURN_TRUE;
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
//#### TODO: These should be int's not double's
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
