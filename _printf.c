#include <unistd.h>
#include <stdarg.h>

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
	for (; *format; format++)
	{
		if(*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int num = va_arg(args, int);
			int temp = num;

			/* Count the number of digits */
			int digits = (num == 0) ? 1 : 0;
			
			while(temp != 0)
			{
				temp /= 10;
				digits++;
			}

			/* Convert each digit to a character adn wrtie to stdout */
			temp = num;

			for (; digits > 0; digits--)
			{
				char digit = '0' + temp % 10;
				write(1, &digit, 1);
				count++;
				temp /= 10;
			}
			/* Move to the next charachter after the spcifier */
			format++;
		}
		else if(*format == '%' && *(format + 1) == 'n')
		{
			int *nptr = va_arg(args, int *);
			*nptr = count;
			format += 2;
		}
		else
		{
			write(1, format, 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
