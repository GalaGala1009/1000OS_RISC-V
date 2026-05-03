#include "common.h"

void putchar(char ch);

void printf(const char *fmt, ...) {
    va_list vargs;         // pointer to args
    va_start(vargs, fmt); // init begin from last fixed arg

    while (*fmt) {
        if (*fmt == '%') {
            fmt++; // Skip '%'
            switch (*fmt) { // Read the next character
                case '\0': // '%' at the end of the format string
                    putchar('%');
                    goto end;
                case '%': // Print '%'
                    putchar('%');
                    break;
                case 's': { // Print a NULL-terminated string.
                    const char *s = va_arg(vargs, const char *);
                    while (*s) {
                        putchar(*s);
                        s++;
                    }
                    break;
                }
                case 'd': { // Print an integer in decimal.
                    int value = va_arg(vargs, int);
                    unsigned magnitude = value; // https://github.com/nuta/operating-system-in-1000-lines/issues/64
                    if (value < 0) {
                        putchar('-');
                        magnitude = -magnitude;
                    }

                    unsigned divisor = 1;
                    while (magnitude / divisor > 9)
                        divisor *= 10;

                    while (divisor > 0) {
                        putchar('0' + magnitude / divisor);
                        magnitude %= divisor;
                        divisor /= 10;
                    }

                    break;
                }
                case 'x': { // Print an integer in hexadecimal.
                    unsigned value = va_arg(vargs, unsigned);
                    for (int i = 7; i >= 0; i--) {
                        unsigned nibble = (value >> (i * 4)) & 0xf;
                        putchar("0123456789abcdef"[nibble]);
                    }
                }
            }
        } else {
            putchar(*fmt);
        }

        fmt++;
    }

end:
    va_end(vargs);
}

void *memcpy(void *dst, const void *src, size_t n){
    /* copy src address n bytes data to dst address */
    uint8_t *d = (uint8_t *) dst;
    const uint8_t *s = (const uint8_t *) src;
    while(n--)
	*d++ = *s++;
    return dst;
}

void *memset(void *buf, char c, size_t n){
    /* write c in to first n bytes of buf */
    uint8_t *p = (uint8_t *) buf;
    while(n--){
	    *p++ = c; // *p = c; p = p + 1;
    }
    return buf;
}

char *strcpy(char *dst, const char *src){
    /* copy string from src to dst*/
    char *d = dst;
    while (*src){
	    *d++ = *src++;
    }
    *d = '\0'; // ensure string ending
    return dst;
}

char *strcpy_s(char *dst, const char *src, size_t dst_size){
    /* safe copy string from src to dst*/
    if(dst_size == 0) return dst;
    char *d = dst;
    size_t i = 0;

    while( i < dst_size-1 && src[i]){
        d[i] = src[i];
        i++;
    }
    d[i] = '\0';
    return dst;
}

int strcmp(const char *s1, const char *s2){
    /* 
    compare str s1 and str s2 order
        s1 == s2 return 0
        s1 > s2 return positive value
        s1 < s2 return negative value
    */
    while(*s1 && *s2){
        if(*s1 != *s2){
            break;
        }
        s1++;
        s2++;
    }
    
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

