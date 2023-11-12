#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: identifier for all initial strings
 * Return: strings with all indentifiers
 */
int _printf(const char *format, ...)
{
	/* A list to hold arguments received */
	va_list args;
	/* Initialise the argument list with the format */
	va_start(args, format);
	
	/* This count tracks the number of characters we print */
	int count = 0;

	/* loop through each charater in the format string */
	for(; *format; format++)
	{
		if(*format == "%")
		{
			format++;
			switch(*format)
			{
				case 'c':
					{
						int character;

						character = va_args(args, int);
						write(1, &character, 1);
						count++;
						break;
					}
			}
		}
	}
}
