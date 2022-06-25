/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:32:16 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 12:44:46 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * Function:  ft_printf
 * --------------------
 * prints a formatted string to stdout that mimics the
 * original printf() from libc
 *
 * parameters:
 *  str: input string, with formatting macros
 *  ...: variadic variables to be inserted into string
 *
 * returns: total number of printed characters
 *
 *
 * Requirements:
 * -------------
 * Doesn't implement the buffer management of printf()
 *
 * Handles the following conversions:
 *  %c: Character
 *  %s: String
 *  %p: Pointer (void * -> hex integer)
 *  %d and %i: Signed Integer
 *  %u: Unsigned Integer
 *  %x: Lowercase Hexadecimal Integer
 *  %X: Uppercase Hexadecimal Integer
 *  %%: Escaped % symbol
 */
int	ft_printf(const char *str, ...)
{
	size_t	chars;
	va_list	args;

	chars = 0;
	va_start(args, str);
	iterator(str, &args, &chars);
	va_end(args);
	return (chars);
}

void	put_charc(char c, size_t *count)
{
	(*count)++;
	write(STDOUT_FILENO, &c, 1);
}

void	put_longhex(unsigned long num, size_t *count)
{
	char	digit;

	if (num >= 16)
	{
		put_longhex(num / 16, count);
		num = num % 16;
	}
	digit = "0123456789abcdef"[num];
	put_charc(digit, count);
}

void	switcher(char c, va_list *list, size_t *count)
{
	if (c == 'c')
		put_charc(va_arg(*list, int), count);
	else if (c == 's')
		putstrip(va_arg(*list, char *), 0, count);
	else if (c == 'p')
		put_pointerc(va_arg(*list, void *), count);
	else if (c == 'd' || c == 'i')
		put_nbrc(va_arg(*list, int), count);
	else if (c == 'u')
		put_unbrc(va_arg(*list, unsigned int), count);
	else if (c == 'x' || c == 'X')
		put_hex(va_arg(*list, unsigned int),
			(unsigned char)((c - 'X') / 32), count);
	else if (c == '%')
		put_charc('%', count);
}

void	iterator(const char *str, va_list *list, size_t *count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			put_charc(str[i], count);
		else
		{
			i++;
			if (str[i] == 0)
				break ;
			switcher(str[i], list, count);
		}
		i++;
	}
}
