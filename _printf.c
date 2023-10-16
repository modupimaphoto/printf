#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string.
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i;
	int count = 0;
	va_list args;

	va_start(args, format);
	i = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					count += printf("%%");
				default:
					break;
			}
		}
		else
		{
			count += printf("%c", format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
