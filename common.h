#pragma once // Ensure this header file can only be  included once

typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t;   // physical memory address data type 
typedef uint32_t vaddr_t;   // virtual memory address data type 

// __builtin__ : clang provide function
#define true 1
#define false 0
#define NULL ((void *) 0)
#define align_up(value, align)   __builtin_align_up(value, align)   // floor func to 2^x
#define is_aligned(value, align) __builtin_is_aligned(value, align) // check if value == 2^x
#define offsetof(type, member)   __builtin_offsetof(type, member)  
#define va_list  __builtin_va_list
#define va_start __builtin_va_start
#define va_end   __builtin_va_end
#define va_arg   __builtin_va_arg
#define PAGE_SIZE 4096

void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
char *strcpy(char *dst, const char *src);
char *strcpy_s(char *dst, const char *src, size_t dst_size);
int strcmp(const char *s1, const char * s2);
void printf(const char *fmt, ...);
