from mako.template import Template

TYPEMAP = {}
i = 0

def add_type(name, cl, cuda, sz):
    global i
    TYPEMAP[i] = (cl, cuda, sz), name
    i+=1

add_type("bool", "bool", "uint8_t", 1)
add_type("byte", "char", "int8_t", 1)
add_type("ubyte", "unsigned char", "uint8_t", 1)

for name, sz in [("short", 2), ("int", 4), ("long", 8)]:
    add_type(name, name, "int%d_t"%(sz*8), sz)
    add_type("u"+name, "unsigned "+name, "uint%d_t"%(sz*8), sz)

add_type("longlong", "long long", "int128_t", 16)
add_type("ulonglong", "unsigned long long", "uint128_t", 16)

add_type("float", "float", "float", 4)
add_type("double", "double", "double", 8)
add_type("longdouble", "quad", "long double", 16)
add_type("cfloat", "cfloat_t", "cfloat_t", 8)
add_type("cdouble", "cdouble_t", "cdouble_t", 16)
add_type("clongdouble", "complex quad", "clongdouble_t", 32)

assert i <= 23
i=23 # to sync with numpy.
add_type("half", "half", "half_t", 2);

complex_decl = """
typedef struct _cfloat {
  float r;
  float i;
} cfloat_t;
"""

cl_decl = complex_decl

cuda_decl = """
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
""" + complex_decl

ntypes = i

VECTORMAP = {}
i = 0

def add_type(name, cl, cuda, sz):
    global i
    VECTORMAP[i] = (cl, cuda, sz, "GA_"+name.upper()), name
    i+=1

for s in [2, 3, 4, 8, 16]:
    add_type("byte"+str(s), "char"+str(s), "char"+str(s), s)
    add_type("ubyte"+str(s), "uchar"+str(s), "uchar"+str(s), s)

for name, sz in [("short", 2), ("int", 4), ("long", 8)]:
    for s in [2, 3, 4, 8, 16]:
        add_type(name+str(s), name+str(s), name+str(s), sz*s)
        add_type("u"+name+str(s), "u"+name+str(s), "u"+name+str(s), sz*s)

for name, sz in [("float", 4), ("double", 8), ("half", 2)]:
    for s in [2, 4, 8, 16]:
        add_type(name+str(s), name+str(s), name+str(s), sz*s)

nvec = i

head_tmpl = Template(""" /* This file is generated by gen_types.py */

#ifndef COMPYTE_TYPES
#define COMPYTE_TYPES
#include <sys/types.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
#ifdef CONFUSE_EMACS
}
#endif

typedef struct _compyte_type {
  const char *cl_name;
  const char *cuda_name;
  size_t size;
  size_t align;
  int typecode;
} compyte_type;

enum COMPYTE_TYPES {
% for i, v in sorted(TYPEMAP.items()):
  GA_${v[1].upper()} = ${i},
% endfor
  GA_NBASE = ${ntypes},

  GA_DELIM = 255, /* To be forward-compatible with numpy */

% for i, v in sorted(VECTORMAP.items()):
  GA_${v[1].upper()},
% endfor
};

extern compyte_type scalar_types[];
extern compyte_type vector_types[];

extern const char CL_HEAD[];
extern const char CUDA_HEAD[];

#ifdef __cplusplus
}
#endif

#endif /* COMPYTE_TYPES */
""")

impl_tmpl = Template(""" /* This file is generated by gen_types.py */
#include "compyte_types.h"
#include <stdlib.h> /* For NULL */

${cuda_decl}

const char CL_HEAD[] = ""
%for l in cl_decl.split('\\n'):
 "${l}\\n"
%endfor
;
const char CUDA_HEAD[] = ""
% for l in cuda_decl.split('\\n'):
 "${l}\\n"
% endfor
;

% for k, v in TYPEMAP.items():
typedef struct {char c; ${v[0][1]} x; } st_${v[1]};
#define ${v[1].upper()}_ALIGN (sizeof(st_${v[1]}) - sizeof(${v[0][1]}))
% endfor

compyte_type scalar_types[] = {
% for i in range(ntypes):
  % if i in TYPEMAP:
  {"${TYPEMAP[i][0][0]}", "${TYPEMAP[i][0][1]}", ${TYPEMAP[i][0][2]}, ${TYPEMAP[i][1].upper()}_ALIGN, GA_${TYPEMAP[i][1].upper()}},
  % else:
  {NULL, NULL, 0, 0, -1},
  % endif
% endfor
};

compyte_type vector_types[] = {
% for i, v in sorted(VECTORMAP.items()):
  {"${v[0][0]}", "${v[0][1]}", ${v[0][2]}, 0, GA_${v[1].upper()}},
% endfor
};
""")

header = open("compyte_types.h", "w")
header.write(head_tmpl.render(TYPEMAP=TYPEMAP, VECTORMAP=VECTORMAP, ntypes=ntypes))
header.close()

impl = open("compyte_types.c", "w")
impl.write(impl_tmpl.render(TYPEMAP=TYPEMAP, VECTORMAP=VECTORMAP, ntypes=ntypes, cl_decl=cl_decl, cuda_decl=cuda_decl))
impl.close()
