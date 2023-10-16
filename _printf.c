#include "main.h"

/**
 * _printf - program to print whatever is given as arguments
 * @format: Format specifier
 *
 * Return: True
 */
int _printf(const char *format, ...)
{
	int prnt_char = 0;
	va_list list_args;

	if (format == NULL)
		return (-1);

	va_start(list_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			prnt_char++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				prnt_char++;
			}
			
			else if (*format =='c')
			{
				char c = va_arg(list_args, int);
				write(1, &c, 1);
				prnt_char++;
			}

			else if (*format == 's')
			{
				char *str = va_arg(list_args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				prnt_char += str_len;
			}
		}

		format++;
	}
	va_end(list_args);

	return prnt_char;
}
