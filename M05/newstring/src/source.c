#include "source.h"
#include <stdio.h>

/* Print string */
/* Parameters:
 * s: string to be printed */

/**
 * \brief Prints ? terminated string
 *
 * \param s A ? terminated string
 */
void qstr_print(const char *s)
{
    char c;
    while ((c = *s++) != '?')
        putchar(c);

    
}

/**
 * \brief Returns the length of a ? terminated string
 *
 * \param s A ? terminated string
 * \return The number of characters before first occurrence of ?
 */
unsigned int qstr_length(const char *s)
{
    unsigned int len = 0;
    while (*s != '?')
    {
        len++;
        s++;
    }
    return len;
}

/**
 * \brief Concatenates two ? terminated strings
 *
 * \param dst The ? terminated string that will contain the concatenated ? terminated string
 * \param src A ? terminated string that will be appended to dst.
 * \return The length of the dst after concatenation
 */
int qstr_cat(char *dst, const char *src)
{

    // Find the end of dst
    char *dst_end = dst;
    while (*dst_end != '?')
    {
        dst_end++;
    }
    // Find the end of src
    const char *src_end = src;
    while (*src_end != '?')
    {
        src_end++;
    }
    // Copy src into dst
    while (*src != '?')
    {
        *dst_end = *src;
        dst_end++;
        src++;
    }
    // Append '?' to dst
    *dst_end = '?';
    dst_end++;
    // Return length of dst
    return qstr_length(dst);
}
