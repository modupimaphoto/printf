#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string.
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
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
					break;
				case 'd':
					count += printf("%d", va_arg(args, int));
					break;
				case 'i':
					count += printf("%i", va_arg(args, int));
					break;
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
