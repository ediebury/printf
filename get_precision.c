#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Index of argument to be printed.
 * @list: Variable argument list.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int i, va_list list)
{
    int precision = -1; /* default precision */

    /* Find the precision */
    /* Loop through format string */
    for (; *format != '\0'; format++)
    {
        /* Check for precision specifier */
        if (*format == '.')
        {
            format++; /* Move past the period */

            /* Check for optional precision value */
            if (*format == '*')
            {
                /* Get precision from argument list */
                precision = va_arg(list, int);
            }
            else
            {
                /* Parse precision value from format string */
                precision = 0;
                while (*format >= '0' && *format <= '9')
                {
                    precision = precision * 10 + (*format - '0');
                    format++;
                }
                format--; /* Move back one character */
            }
        }
    }

    return precision;
}

