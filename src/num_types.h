#ifndef PHP_NUMPHP_TYPES_H
#define PHP_NUMPHP_TYPES_H 1



typedef struct _php_num_ivec2 {
    int x;
    int y;
} php_num_ivec2;

typedef struct _php_num_ivec3 {
    int x;
    int y;
    int z;
} php_num_ivec3;

typedef struct _php_num_ivec4 {
    int x;
    int y;
    int z;
    int w;
} php_num_ivec4;



typedef struct _php_num_vec2 {
    double x;
    double y;
} php_num_vec2;

typedef struct _php_num_vec3 {
    double x;
    double y;
    double z;
} php_num_vec3;

typedef struct _php_num_vec4 {
    double x;
    double y;
    double z;
    double w;
} php_num_vec4;



#endif /* PHP_NUMPHP_TYPES_H */

