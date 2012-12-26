#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "num.h"

#include "num_types.h"





PHP_FUNCTION(num_mathml_serialize)
{
	zval *user_variable;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &user_variable) == FAILURE) {
		RETURN_NULL();
	}

	switch (Z_TYPE_P(user_variable)) {

		case IS_BOOL:
			if        (   1 == Z_BVAL_P(user_variable)  ) {
/////////////// RETURN
				RETURN_STRING("<true />", 1);
			} else if (  0 == Z_BVAL_P(user_variable)  ) {
/////////////// RETURN
				RETURN_STRING("<false />", 1);
			} else {
/////////////// RETURN
				RETURN_NULL();
			}
		break;

		case IS_NULL:
			RETURN_NULL();
		break;

		case IS_LONG:
		{
			char *prefix  = "<cn>";
			int   prefix_len;

			char *postfix = "</cn>";
			int   postfix_len;

			char *mem_long;
			int   mem_long_len;

			char *mem;
			int   mem_len;

			prefix_len  = strlen(prefix);
			postfix_len = strlen(postfix);

			mem_long_len = snprintf(NULL, 0, "%ld", Z_LVAL_P(user_variable));
			mem_long = emalloc(mem_long_len + 1);

			//snprintf(mem_long, mem_long_len, "%ld", Z_LVAL_P(user_variable));
			sprintf(mem_long, "%ld", Z_LVAL_P(user_variable));


			mem_len = prefix_len + mem_long_len + postfix_len;

			mem = emalloc(mem_len);

			memcpy( mem                             , prefix   , prefix_len   );
			memcpy( mem + prefix_len                , mem_long , mem_long_len );
			memcpy( mem + prefix_len + mem_long_len , postfix  , postfix_len  );


			efree(mem_long);


/////////// RETURN
			RETURN_STRINGL(mem, mem_len, 0);
		}
		break;

		case IS_DOUBLE:
		{
			char *prefix  = "<cn>";
			int   prefix_len;

			char *postfix = "</cn>";
			int   postfix_len;

			char *mem_double;
			int   mem_double_len;

			char *mem;
			int   mem_len;

			prefix_len  = strlen(prefix);
			postfix_len = strlen(postfix);

			mem_double_len = snprintf(NULL, 0, "%f", Z_DVAL_P(user_variable));
			mem_double = emalloc(mem_double_len + 1);

			//snprintf(mem_double, mem_double_len, "%f", Z_DVAL_P(user_variable));
			sprintf(mem_double, "%f", Z_DVAL_P(user_variable));


			mem_len = prefix_len + mem_double_len + postfix_len;

			mem = emalloc(mem_len);

			memcpy( mem                               , prefix     , prefix_len   );
			memcpy( mem + prefix_len                  , mem_double , mem_double_len );
			memcpy( mem + prefix_len + mem_double_len , postfix    , postfix_len  );


			efree(mem_double);


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

			//php_printf("RESOURCE ID: %ld \n", resource_id);
			//php_printf("RESOURCE TYPE NAME: %s \n", resource_type_name);
			//php_printf("RESOURCE TYPE ID: %d \n", resource_type_id);

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
				//snprintf(w_mem, w_mem_len, "%ld", ivec3->w);
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

				ZEND_FETCH_RESOURCE(vec2, php_num_vec2 *, &user_variable, -1, "num_vec2", le_num_vec2);



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

				x_mem_len = snprintf(NULL, 0, "%f", vec2->x);
				y_mem_len = snprintf(NULL, 0, "%f", vec2->y);

				x_mem = emalloc(x_mem_len+1);
				y_mem = emalloc(y_mem_len+1);

				//snprintf(x_mem, x_mem_len, "%f", vec2->x);
				//snprintf(y_mem, y_mem_len, "%f", vec2->y);
				sprintf(x_mem, "%f", vec2->x);
				sprintf(y_mem, "%f", vec2->y);


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

			} else if (  resource_type_id == le_num_vec3  ) {

				php_num_vec3 *vec3;

				ZEND_FETCH_RESOURCE(vec3, php_num_vec3 *, &user_variable, -1, "num_vec3", le_num_vec3);



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

				x_mem_len = snprintf(NULL, 0, "%f", vec3->x);
				y_mem_len = snprintf(NULL, 0, "%f", vec3->y);
				z_mem_len = snprintf(NULL, 0, "%f", vec3->z);

				x_mem = emalloc(x_mem_len+1);
				y_mem = emalloc(y_mem_len+1);
				z_mem = emalloc(z_mem_len+1);

				//snprintf(x_mem, x_mem_len, "%f", vec3->x);
				//snprintf(y_mem, y_mem_len, "%f", vec3->y);
				//snprintf(z_mem, z_mem_len, "%f", vec3->z);
				sprintf(x_mem, "%f", vec3->x);
				sprintf(y_mem, "%f", vec3->y);
				sprintf(z_mem, "%f", vec3->z);


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

			} else if (  resource_type_id == le_num_vec4  ) {

				php_num_vec4 *vec4;

				ZEND_FETCH_RESOURCE(vec4, php_num_vec4 *, &user_variable, -1, "num_vec4", le_num_vec4);



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

				x_mem_len = snprintf(NULL, 0, "%f", vec4->x);
				y_mem_len = snprintf(NULL, 0, "%f", vec4->y);
				z_mem_len = snprintf(NULL, 0, "%f", vec4->z);
				w_mem_len = snprintf(NULL, 0, "%f", vec4->w);

				x_mem = emalloc(x_mem_len+1);
				y_mem = emalloc(y_mem_len+1);
				z_mem = emalloc(z_mem_len+1);
				w_mem = emalloc(w_mem_len+1);

				//snprintf(x_mem, x_mem_len, "%f", vec4->x);
				//snprintf(y_mem, y_mem_len, "%f", vec4->y);
				//snprintf(z_mem, z_mem_len, "%f", vec4->z);
				//snprintf(w_mem, w_mem_len, "%f", vec4->w);
				sprintf(x_mem, "%f", vec4->x);
				sprintf(y_mem, "%f", vec4->y);
				sprintf(z_mem, "%f", vec4->z);
				sprintf(w_mem, "%f", vec4->w);


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
	} // switch

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
