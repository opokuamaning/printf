#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: identifier for all initial strings
 * Return: strings with all indentifiers
 */
int _printf(const char *format, ...)
{
        int count = 0;
        /* A list to hold arguments received */
        va_list args;
        /* Initialise the argument list with the format */
        va_start(args, format);
        /* This count tracks the number of characters we print */

        while (*format)
        {
                if (*format == '%')
                {
                        format++;
                        if (*format == 'c')
                        {
                                int character = va_arg(args, int);

                                write(1, &character, 1);
                                count++;
                        }
                        else if (*format == 's')
                        {
                                char *str = va_arg(args, char *);

                                while (*str)
                                {
                                        write(1, str, 1);
                                        count++;
                                        str++;
                                }
                        }
                        else if (*format == '%')
                        {
                                write(1, "%", 1);
                                {
                                        count++;
                                }
                        }
                        else if (*format == 'd' || *format == 'i')
                        {
                                int num = va_arg(args, int);
                                char buffer[12];
                                int digits = sprintf(buffer, "%d", num);
                                write(1, buffer, digits);
                                count += digits;
                        }
                        else
                        {
                                write(1, "%", 1);
                                if (*format)
                                {
                                        write(1, format, 1);
                                        count += 2;
                                }
                        }

                }
                else
                {
                        write(1, format, 1);
                        count++;
                }
                format++;
        }
        va_end(args);
        return (count);
}
