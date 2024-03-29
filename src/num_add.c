#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "num.h"

#include "num_types.h"
#include "num_dimension.h"





static void _php_num_add_ivec2(php_num_ivec2 *r, php_num_ivec2 *a, php_num_ivec2 *b)
{
php_printf("[_php_num_add_ivec2] BEGIN \n");
	r->x = a->x + b->x;
	r->y = a->y + b->y;
php_printf("[_php_num_add_ivec2] END \n");
}

static void _php_num_add_ivec3(php_num_ivec3 *r, php_num_ivec3 *a, php_num_ivec3 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
	r->z = a->z + b->z;
}

static void _php_num_add_ivec4(php_num_ivec4 *r, php_num_ivec4 *a, php_num_ivec4 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
	r->z = a->z + b->z;
	r->w = a->w + b->w;
}


static void _php_num_add_vec2(php_num_vec2 *r, php_num_vec2 *a, php_num_vec2 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
}

static void _php_num_add_vec3(php_num_vec3 *r, php_num_vec3 *a, php_num_vec3 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
	r->z = a->z + b->z;
}

static void _php_num_add_vec4(php_num_vec4 *r, php_num_vec4 *a, php_num_vec4 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
	r->z = a->z + b->z;
	r->w = a->w + b->w;
}



static void _php_num_add_vec2_ivec2(php_num_vec2 *r, php_num_vec2 *a, php_num_ivec2 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
}

static void _php_num_add_vec3_ivec3(php_num_vec3 *r, php_num_vec3 *a, php_num_ivec3 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
	r->z = a->z + b->z;
}

static void _php_num_add_vec4_ivec4(php_num_vec4 *r, php_num_vec4 *a, php_num_ivec4 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
	r->z = a->z + b->z;
	r->w = a->w + b->w;
}



static void _php_num_add_ivec2_vec2(php_num_vec2 *r, php_num_ivec2 *a, php_num_vec2 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
}

static void _php_num_add_ivec3_vec3(php_num_vec3 *r, php_num_ivec3 *a, php_num_vec3 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
	r->z = a->z + b->z;
}

static void _php_num_add_ivec4_vec4(php_num_vec4 *r, php_num_ivec4 *a, php_num_vec4 *b)
{
	r->x = a->x + b->x;
	r->y = a->y + b->y;
	r->z = a->z + b->z;
	r->w = a->w + b->w;
}





PHP_FUNCTION(num_add)
{
	zval *a;
	zval *b;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		RETURN_NULL();
	}


	switch (Z_TYPE_P(a)) {

		case IS_BOOL:
			RETURN_NULL();
		break;

		case IS_NULL:
			RETURN_NULL();
		break;

		case IS_LONG:
			if (  IS_LONG == Z_TYPE_P(b)  ) {
				long result = Z_LVAL_P(a) + Z_LVAL_P(b);

/////////////// RETURN
				RETURN_LONG(result);
			} else if (  IS_DOUBLE == Z_TYPE_P(b)  ) {
				double result = Z_LVAL_P(a) + Z_DVAL_P(b);

/////////////// RETURN
				RETURN_DOUBLE(result);
			} else {
/////////////// RETURN
				RETURN_NULL();
			}
		break;

		case IS_DOUBLE:
			if (  IS_LONG == Z_TYPE_P(b)  ) {
				double result = Z_DVAL_P(a) + Z_LVAL_P(b);

/////////////// RETURN
				RETURN_DOUBLE(result);
			} else if (  IS_DOUBLE == Z_TYPE_P(b)  ) {
				double result = Z_DVAL_P(a) + Z_DVAL_P(b);

/////////////// RETURN
				RETURN_DOUBLE(result);
			} else {
/////////////// RETURN
				RETURN_NULL();
			}
		break;

		case IS_STRING:
			RETURN_NULL();
		break;

		case IS_RESOURCE:
		{
			long a_dimension;
			long b_dimension;

			long a_resource_id = Z_LVAL_P(a);
			//const char *a_resource_type_name = zend_rsrc_list_get_rsrc_type(a_resource_id TSRMLS_CC);
			int a_resource_type_id;

			if (!zend_list_find(a_resource_id, &a_resource_type_id)) {
/////////////// RETURN
				RETURN_NULL();
			}

			//php_printf("a RESOURCE ID: %ld \n", a_resource_id);
			//php_printf("a RESOURCE TYPE NAME: %s \n", a_resource_type_name);
			//php_printf("a RESOURCE TYPE ID: %d \n", a_resource_type_id);



			long b_resource_id = Z_LVAL_P(b);
			//const char *b_resource_type_name = zend_rsrc_list_get_rsrc_type(b_resource_id TSRMLS_CC);
			int b_resource_type_id;

			if (!zend_list_find(b_resource_id, &b_resource_type_id)) {
/////////////// RETURN
				RETURN_NULL();
			}

			//php_printf("b RESOURCE ID: %ld \n", b_resource_id);
			//php_printf("b RESOURCE TYPE NAME: %s \n", b_resource_type_name);
			//php_printf("b RESOURCE TYPE ID: %d \n", b_resource_type_id);



			a_dimension = _php_num_dimension_resource_id(a_resource_id);
			b_dimension = _php_num_dimension_resource_id(b_resource_id);

			if (  a_dimension != b_dimension || 0 > a_dimension  ) {
/////////////// RETURN
				RETURN_NULL();
			}




			switch (a_dimension) { // == b_dimension

				case 2:
				{
					if (  a_resource_type_id == le_num_vec2 && b_resource_type_id == le_num_vec2  ) {

						php_num_vec2 *vec2_a;
						php_num_vec2 *vec2_b;
						php_num_vec2 *vec2 = emalloc( sizeof(php_num_vec2) );

						ZEND_FETCH_RESOURCE(vec2_a, php_num_vec2 *, &a, -1, "num_vec2", le_num_vec2);
						ZEND_FETCH_RESOURCE(vec2_b, php_num_vec2 *, &b, -1, "num_vec2", le_num_vec2);

						_php_num_add_vec2(vec2, vec2_a, vec2_b);

/////////////////////// RETURN
						ZEND_REGISTER_RESOURCE(return_value, vec2, le_num_vec2);

					} else if (  a_resource_type_id == le_num_vec2 && b_resource_type_id == le_num_ivec2  ) {

						php_num_vec2  *vec2_a;
						php_num_ivec2 *ivec2_b;
						php_num_vec2  *vec2 = emalloc( sizeof(php_num_vec2) );

						ZEND_FETCH_RESOURCE(vec2_a,  php_num_vec2 *,  &a, -1, "num_vec2",  le_num_vec2);
						ZEND_FETCH_RESOURCE(ivec2_b, php_num_ivec2 *, &b, -1, "num_ivec2", le_num_ivec2);

						_php_num_add_vec2_ivec2(vec2, vec2_a, ivec2_b);

/////////////////////// RETURN
						ZEND_REGISTER_RESOURCE(return_value, vec2, le_num_vec2);

					} else if (  a_resource_type_id == le_num_ivec2 && b_resource_type_id == le_num_vec2  ) {

						php_num_ivec2 *ivec2_a;
						php_num_vec2  *vec2_b;
						php_num_vec2  *vec2 = emalloc( sizeof(php_num_vec2) );

						ZEND_FETCH_RESOURCE(ivec2_a, php_num_ivec2 *, &a, -1, "num_ivec2", le_num_ivec2);
						ZEND_FETCH_RESOURCE(vec2_b,  php_num_vec2 *,  &b, -1, "num_vec2",  le_num_vec2);

						_php_num_add_ivec2_vec2(vec2, ivec2_a, vec2_b);

/////////////////////// RETURN
						ZEND_REGISTER_RESOURCE(return_value, vec2, le_num_vec2);

					} else if (  a_resource_type_id == le_num_ivec2 && b_resource_type_id == le_num_ivec2  ) {

						php_num_ivec2 *ivec2_a;
						php_num_vec2  *ivec2_b;
						php_num_ivec2 *ivec2 = emalloc( sizeof(php_num_ivec2) );

						ZEND_FETCH_RESOURCE(ivec2_a, php_num_ivec2 *, &a, -1, "num_ivec2", le_num_ivec2);
						ZEND_FETCH_RESOURCE(ivec2_b, php_num_ivec2 *, &b, -1, "num_ivec2", le_num_ivec2);

						_php_num_add_ivec2(ivec2, ivec2_a, ivec2_b);

/////////////////////// RETURN
						ZEND_REGISTER_RESOURCE(return_value, ivec2, le_num_ivec2);

					} else {
/////////////////////// RETURN
						RETURN_NULL();
					}
				}
				break;

				case 3:
				{
/////////////////// RETURN
					RETURN_NULL();
				}
				break;

				case 4:
				{
/////////////////// RETURN
					RETURN_NULL();
				}
				break;

			} // switch
//@TODO ----------------------------------------------------------------------------------
		}
		break;

		case IS_ARRAY:
			RETURN_NULL();
		break;

		case IS_OBJECT:
			RETURN_NULL();
		break;

		default:
			RETURN_NULL();
		break;

	} // switch
}
