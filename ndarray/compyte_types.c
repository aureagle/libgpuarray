 /* This file is generated by gen_types.py */
#include "compyte_types.h"
#include <stdlib.h> /* For NULL */


#ifdef _MSC_VER
typedef __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

typedef struct _int128 {
    union int128_u {
        int8_t  as_int8[16];
        int16_t as_int16[8];
        int32_t as_int32[4];
        int64_t as_int64[2];
    } value;
} int128_t;

typedef struct _uint128 {
    union uint128_u {
        uint8_t  as_uint8[16];
        uint16_t as_uint16[8];
        uint32_t as_uint32[4];
        uint64_t as_uint64[2];
    } value;
} uint128_t;

typedef uint16_t half_t;

typedef struct _cdouble {
  double r;
  double i;
} cdouble_t;

typedef struct _clongdouble {
 long double r;
 long double i;
} clongdouble_t;

typedef struct _cfloat {
  float r;
  float i;
} cfloat_t;


const char CL_HEAD[] = ""
 "\n"
 "typedef struct _cfloat {\n"
 "  float r;\n"
 "  float i;\n"
 "} cfloat_t;\n"
 "\n"
;
const char CUDA_HEAD[] = ""
 "\n"
 "#ifdef _MSC_VER\n"
 "typedef __int8 int8_t;\n"
 "typedef unsigned __int8 uint8_t;\n"
 "typedef __int16 int16_t;\n"
 "typedef unsigned __int16 uint16_t;\n"
 "typedef __int32 int32_t;\n"
 "typedef unsigned __int32 uint32_t;\n"
 "typedef __int64 int64_t;\n"
 "typedef unsigned __int64 uint64_t;\n"
 "#else\n"
 "#include <stdint.h>\n"
 "#endif\n"
 "\n"
 "typedef struct _int128 {\n"
 "    union int128_u {\n"
 "        int8_t  as_int8[16];\n"
 "        int16_t as_int16[8];\n"
 "        int32_t as_int32[4];\n"
 "        int64_t as_int64[2];\n"
 "    } value;\n"
 "} int128_t;\n"
 "\n"
 "typedef struct _uint128 {\n"
 "    union uint128_u {\n"
 "        uint8_t  as_uint8[16];\n"
 "        uint16_t as_uint16[8];\n"
 "        uint32_t as_uint32[4];\n"
 "        uint64_t as_uint64[2];\n"
 "    } value;\n"
 "} uint128_t;\n"
 "\n"
 "typedef uint16_t half_t;\n"
 "\n"
 "typedef struct _cdouble {\n"
 "  double r;\n"
 "  double i;\n"
 "} cdouble_t;\n"
 "\n"
 "typedef struct _clongdouble {\n"
 " long double r;\n"
 " long double i;\n"
 "} clongdouble_t;\n"
 "\n"
 "typedef struct _cfloat {\n"
 "  float r;\n"
 "  float i;\n"
 "} cfloat_t;\n"
 "\n"
;

typedef struct {char c; uint8_t x; } st_bool;
#define BOOL_ALIGN (sizeof(st_bool) - sizeof(uint8_t))
typedef struct {char c; int8_t x; } st_byte;
#define BYTE_ALIGN (sizeof(st_byte) - sizeof(int8_t))
typedef struct {char c; uint8_t x; } st_ubyte;
#define UBYTE_ALIGN (sizeof(st_ubyte) - sizeof(uint8_t))
typedef struct {char c; int16_t x; } st_short;
#define SHORT_ALIGN (sizeof(st_short) - sizeof(int16_t))
typedef struct {char c; uint16_t x; } st_ushort;
#define USHORT_ALIGN (sizeof(st_ushort) - sizeof(uint16_t))
typedef struct {char c; int32_t x; } st_int;
#define INT_ALIGN (sizeof(st_int) - sizeof(int32_t))
typedef struct {char c; uint32_t x; } st_uint;
#define UINT_ALIGN (sizeof(st_uint) - sizeof(uint32_t))
typedef struct {char c; int64_t x; } st_long;
#define LONG_ALIGN (sizeof(st_long) - sizeof(int64_t))
typedef struct {char c; uint64_t x; } st_ulong;
#define ULONG_ALIGN (sizeof(st_ulong) - sizeof(uint64_t))
typedef struct {char c; int128_t x; } st_longlong;
#define LONGLONG_ALIGN (sizeof(st_longlong) - sizeof(int128_t))
typedef struct {char c; uint128_t x; } st_ulonglong;
#define ULONGLONG_ALIGN (sizeof(st_ulonglong) - sizeof(uint128_t))
typedef struct {char c; float x; } st_float;
#define FLOAT_ALIGN (sizeof(st_float) - sizeof(float))
typedef struct {char c; double x; } st_double;
#define DOUBLE_ALIGN (sizeof(st_double) - sizeof(double))
typedef struct {char c; long double x; } st_longdouble;
#define LONGDOUBLE_ALIGN (sizeof(st_longdouble) - sizeof(long double))
typedef struct {char c; cfloat_t x; } st_cfloat;
#define CFLOAT_ALIGN (sizeof(st_cfloat) - sizeof(cfloat_t))
typedef struct {char c; cdouble_t x; } st_cdouble;
#define CDOUBLE_ALIGN (sizeof(st_cdouble) - sizeof(cdouble_t))
typedef struct {char c; clongdouble_t x; } st_clongdouble;
#define CLONGDOUBLE_ALIGN (sizeof(st_clongdouble) - sizeof(clongdouble_t))
typedef struct {char c; half_t x; } st_half;
#define HALF_ALIGN (sizeof(st_half) - sizeof(half_t))

compyte_type scalar_types[] = {
  {"bool", "uint8_t", 1, BOOL_ALIGN, GA_BOOL},
  {"char", "int8_t", 1, BYTE_ALIGN, GA_BYTE},
  {"unsigned char", "uint8_t", 1, UBYTE_ALIGN, GA_UBYTE},
  {"short", "int16_t", 2, SHORT_ALIGN, GA_SHORT},
  {"unsigned short", "uint16_t", 2, USHORT_ALIGN, GA_USHORT},
  {"int", "int32_t", 4, INT_ALIGN, GA_INT},
  {"unsigned int", "uint32_t", 4, UINT_ALIGN, GA_UINT},
  {"long", "int64_t", 8, LONG_ALIGN, GA_LONG},
  {"unsigned long", "uint64_t", 8, ULONG_ALIGN, GA_ULONG},
  {"long long", "int128_t", 16, LONGLONG_ALIGN, GA_LONGLONG},
  {"unsigned long long", "uint128_t", 16, ULONGLONG_ALIGN, GA_ULONGLONG},
  {"float", "float", 4, FLOAT_ALIGN, GA_FLOAT},
  {"double", "double", 8, DOUBLE_ALIGN, GA_DOUBLE},
  {"quad", "long double", 16, LONGDOUBLE_ALIGN, GA_LONGDOUBLE},
  {"cfloat_t", "cfloat_t", 8, CFLOAT_ALIGN, GA_CFLOAT},
  {"cdouble_t", "cdouble_t", 16, CDOUBLE_ALIGN, GA_CDOUBLE},
  {"complex quad", "clongdouble_t", 32, CLONGDOUBLE_ALIGN, GA_CLONGDOUBLE},
  {NULL, NULL, 0, 0, -1},
  {NULL, NULL, 0, 0, -1},
  {NULL, NULL, 0, 0, -1},
  {NULL, NULL, 0, 0, -1},
  {NULL, NULL, 0, 0, -1},
  {NULL, NULL, 0, 0, -1},
  {"half", "half_t", 2, HALF_ALIGN, GA_HALF},
};

compyte_type vector_types[] = {
  {"char2", "char2", 2, 0, GA_BYTE2},
  {"uchar2", "uchar2", 2, 0, GA_UBYTE2},
  {"char3", "char3", 3, 0, GA_BYTE3},
  {"uchar3", "uchar3", 3, 0, GA_UBYTE3},
  {"char4", "char4", 4, 0, GA_BYTE4},
  {"uchar4", "uchar4", 4, 0, GA_UBYTE4},
  {"char8", "char8", 8, 0, GA_BYTE8},
  {"uchar8", "uchar8", 8, 0, GA_UBYTE8},
  {"char16", "char16", 16, 0, GA_BYTE16},
  {"uchar16", "uchar16", 16, 0, GA_UBYTE16},
  {"short2", "short2", 4, 0, GA_SHORT2},
  {"ushort2", "ushort2", 4, 0, GA_USHORT2},
  {"short3", "short3", 6, 0, GA_SHORT3},
  {"ushort3", "ushort3", 6, 0, GA_USHORT3},
  {"short4", "short4", 8, 0, GA_SHORT4},
  {"ushort4", "ushort4", 8, 0, GA_USHORT4},
  {"short8", "short8", 16, 0, GA_SHORT8},
  {"ushort8", "ushort8", 16, 0, GA_USHORT8},
  {"short16", "short16", 32, 0, GA_SHORT16},
  {"ushort16", "ushort16", 32, 0, GA_USHORT16},
  {"int2", "int2", 8, 0, GA_INT2},
  {"uint2", "uint2", 8, 0, GA_UINT2},
  {"int3", "int3", 12, 0, GA_INT3},
  {"uint3", "uint3", 12, 0, GA_UINT3},
  {"int4", "int4", 16, 0, GA_INT4},
  {"uint4", "uint4", 16, 0, GA_UINT4},
  {"int8", "int8", 32, 0, GA_INT8},
  {"uint8", "uint8", 32, 0, GA_UINT8},
  {"int16", "int16", 64, 0, GA_INT16},
  {"uint16", "uint16", 64, 0, GA_UINT16},
  {"long2", "long2", 16, 0, GA_LONG2},
  {"ulong2", "ulong2", 16, 0, GA_ULONG2},
  {"long3", "long3", 24, 0, GA_LONG3},
  {"ulong3", "ulong3", 24, 0, GA_ULONG3},
  {"long4", "long4", 32, 0, GA_LONG4},
  {"ulong4", "ulong4", 32, 0, GA_ULONG4},
  {"long8", "long8", 64, 0, GA_LONG8},
  {"ulong8", "ulong8", 64, 0, GA_ULONG8},
  {"long16", "long16", 128, 0, GA_LONG16},
  {"ulong16", "ulong16", 128, 0, GA_ULONG16},
  {"float2", "float2", 8, 0, GA_FLOAT2},
  {"float4", "float4", 16, 0, GA_FLOAT4},
  {"float8", "float8", 32, 0, GA_FLOAT8},
  {"float16", "float16", 64, 0, GA_FLOAT16},
  {"double2", "double2", 16, 0, GA_DOUBLE2},
  {"double4", "double4", 32, 0, GA_DOUBLE4},
  {"double8", "double8", 64, 0, GA_DOUBLE8},
  {"double16", "double16", 128, 0, GA_DOUBLE16},
  {"half2", "half2", 4, 0, GA_HALF2},
  {"half4", "half4", 8, 0, GA_HALF4},
  {"half8", "half8", 16, 0, GA_HALF8},
  {"half16", "half16", 32, 0, GA_HALF16},
};
