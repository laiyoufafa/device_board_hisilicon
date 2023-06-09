/*
 * Copyright (C) 2021 HiSilicon (Shanghai) Technologies CO., LIMITED.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __TYPES_H__
#define __TYPES_H__


typedef signed char s8;
typedef unsigned char u8;

typedef signed short s16;
typedef unsigned short u16;

typedef signed int s32;
typedef unsigned int u32;

typedef signed long long s64;
typedef unsigned long long u64;

typedef unsigned int size_t;
typedef int ptrdiff_t;

#define BITS_PER_LONG 32

/* Dma addresses are 32-bits wide.  */
typedef u32 dma_addr_t;

#undef NULL
#if defined(__cplusplus)
#define NULL 0
#else
#define NULL ((void *)0)
#endif


typedef s8  INT8;
typedef s16 INT16;
typedef s32 INT32;

typedef u8  UINT8;
typedef u16 UINT16;
typedef u32 UINT32;

typedef int BOOL;
typedef int STATUS;

#define TRUE    1
#define FALSE   0

#define ERROR   -1
#define OK      0

#define FOREVER         while(1)
#define IN
#define OUT

#define PRIVATE static

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef   long      int64_t; 
typedef   unsigned   long       uint64_t; 

typedef unsigned char u_char;
typedef unsigned long u_long;
typedef unsigned int u_int;
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;

#endif

