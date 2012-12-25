#ifndef PHP_NUM_TYPES_H
#define PHP_NUM_TYPES_H 1



typedef struct _php_num_ivec2 {
    long x;
    long y;
} php_num_ivec2;

typedef struct _php_num_ivec3 {
    long x;
    long y;
    long z;
} php_num_ivec3;

typedef struct _php_num_ivec4 {
    long x;
    long y;
    long z;
    long w;
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



#endif /* PHP_NUM_TYPES_H */

