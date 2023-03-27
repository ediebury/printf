#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int i, ...) {
    va_list args;
    va_start(args, i);

    // find the position of the ith argument in the argument list
    int arg_pos = 1;
    while (*format && arg_pos < i) {
        if (*format == '%') {
            // skip over any flags, width, and length modifiers
            format++;
            while (*format && !strchr("diouxXfFeEgGaAcspn%", *format))
                format++;
            if (*format == '\0')
                break;
            if (*format == '%' || *format == 'n') {
                // ignore these conversion specifiers
            } else {
                arg_pos++;
            }
        } else {
            format++;
        }
    }

    // find the precision specifier (if any) for the ith argument
    int precision = -1;
    while (*format && strchr(".0123456789", *format)) {
        if (*format == '.') {
            precision = 0;
        } else if (precision >= 0) {
            precision = precision * 10 + (*format - '0');
        }
        format++;
    }

    va_end(args);
    return precision;
}
