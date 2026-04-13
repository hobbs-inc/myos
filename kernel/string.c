// string.c

#include <stddef.h>

// A simple implementation of some string manipulation utilities.

/**
 * Computes the length of a string.
 * @param str Pointer to the string.
 * @return Length of the string.
 */
size_t string_length(const char *str) {
    const char *s = str;
    while (*s) ++s;
    return s - str;
}

/**
 * Copies a string from src to dest.
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string.
 * @return Pointer to the destination string dest.
 */
char *string_copy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++));
    return dest;
}

/**
 * Compares two strings.
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 * @return Negative if str1 < str2, positive if str1 > str2, 0 if they are equal.
 */
int string_compare(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}