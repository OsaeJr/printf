#include "main.h"
/**
 * _printf - printf function
 * @format: format
 * Return: Printed char
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char buffer[20];
	int num,i;
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
					while (*str)
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				}
				case '%':
					putchar('%');
					count++;
					break;
					case 'd': case 'i': {
                    
                    num = va_arg(args, int);
                    sprintf(buffer, "%d", num);
                    for (i = 0; buffer[i] != '\0'; i++) {
                        putchar(buffer[i]);
                        count++;
                    }
                    break;
                }
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

