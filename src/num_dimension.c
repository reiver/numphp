#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "num.h"

#include "num_types.h"





static long _php_num_dimension_resource_id(long resource_id)
{
		long ERROR = -1;
		long result = ERROR;

		//const char *resource_type_name = zend_rsrc_list_get_rsrc_type(resource_id TSRMLS_CC);
		int resource_type_id;

		if (!zend_list_find(resource_id, &resource_type_id)) {
/////////// RETURN
			return ERROR;
		}

		//DEBUG
		//php_printf("RESOURCE ID: %ld \n",       resource_id);
		//php_printf("RESOURCE TYPE NAME: %s \n", resource_type_name);
		//php_printf("RESOURCE TYPE ID: %d \n",   resource_type_id);


		if        (  resource_type_id == le_num_ivec2  ) {
			result = 2;
		} else if (  resource_type_id == le_num_ivec3  ) {
			result = 3;
		} else if (  resource_type_id == le_num_ivec4  ) {
			result = 4;

		} else if (  resource_type_id == le_num_vec2  ) {
			result = 2;
		} else if (  resource_type_id == le_num_vec3  ) {
			result = 3;
		} else if (  resource_type_id == le_num_vec4  ) {
			result = 4;

		} else {
/////////// RETURN
			return ERROR;
		}


/////// RETURN
		return result;
}




PHP_FUNCTION(num_dimension)
{
	zval *x;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &x) == FAILURE) {
/////// RETURN
		RETURN_NULL();
	}


	switch (Z_TYPE_P(x)) {

		case IS_BOOL:
			//DEBUG
			php_printf("BOOL\n");

/////////// RETURN
			RETURN_LONG(1);
		break;

		case IS_NULL:
			//DEBUG
			php_printf("NULL\n");

/////////// RETURN
			RETURN_LONG(0);
		break;

		case IS_LONG:
			//DEBUG
			php_printf("LONG\n");

/////////// RETURN
			RETURN_LONG(1);
		break;

		case IS_DOUBLE:
			//DEBUG
			php_printf("DOUBLE\n");

/////////// RETURN
			RETURN_LONG(1);
		break;

		case IS_STRING:
			//DEBUG
			php_printf("STRING\n");

/////////// RETURN
			RETURN_NULL();
		break;

		case IS_RESOURCE:
		{
			//DEBUG
			php_printf("RESOURCE\n");


			long resource_id = Z_LVAL_P(x);

			long result = _php_num_dimension_resource_id(resource_id);

			if (  -1 == result  ) {
/////////////// RETURN
				RETURN_NULL();
			} else {
/////////////// RETURN
				RETURN_LONG(result);
			}
		}
		break;

		case IS_ARRAY:
			//DEBUG
			php_printf("ARRAY\n");

/////////// RETURN
			RETURN_NULL();
		break;

		case IS_OBJECT:
			//DEBUG
			php_printf("OBJECT\n");

/////////// RETURN
			RETURN_NULL();
		break;

		default:
			//DEBUG
			php_printf("DEFAULT\n");

/////////// RETURN
			RETURN_NULL();
		break;

	} // switch
}
