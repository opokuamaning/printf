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
	while(*format)
	{
		if(*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int num = va_arg(args, int);
			int temp = num;

			/* Count the number of digits */
			int digits = 0;
			do
			{
				temp /= 10;
				digits++;
			}	
			while(temp != 0);

			/* Convert each digit to a character adn wrtie to stdout */
			temp = num;

			do
			{
				char digit = '0' + temp % 10;
				write(1, &digit, 1);
				count++;
				temp /= 10;
			}
			while(--digits != 0);

			/* Move to the next charachter after the spcifier */
			format += 2;
		}
		else
		{
			write(1, format, 1);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}
