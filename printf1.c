#include "main.h"
/**
 *_printf - formatted output conversion and print data.
 *@format: input string.
 *
 *Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;

				case 's':
					{
						const char *str = va_arg(args, const char *);
						count += fputs(str, stdout);
						break;
					}

				case '%':
					putchar('%');
					count++;
					break;

				case 'd':
				case 'i':
					count += printf("%d", va_arg(args, int));
					break;

				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return count;
}