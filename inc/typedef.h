#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <stdint.h>

typedef uint8_t             u8;
typedef uint16_t            u16;
typedef uint32_t            u32;

typedef int8_t              s8;
typedef int16_t             s16;
typedef int32_t             s32;

typedef volatile int8_t     _s8;
typedef volatile int16_t    _s16;
typedef volatile int32_t    _s32;

typedef volatile uint8_t    _u8;
typedef volatile uint16_t   _u16;
typedef volatile uint32_t   _u32;

typedef int                 INT;
typedef unsigned int        UINT;



typedef enum : u8
{
    false = 0,
    true  = 1
} BOOL;

#endif