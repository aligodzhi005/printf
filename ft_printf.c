/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:19:27 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 13:18:54 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int		ft_putstr(char *str, int len)
{
	write(1, str, len);
	return (len);
}

int		ft_write_sp_or_zero(int width, int length_str, int has_zero)
{
	int count_char;

	count_char = 0;
	while (width - length_str > 0)
	{
		if (has_zero == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		width--;
		count_char++;
	}
	return (count_char);
}

char	*ft_str_toupper(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}

int		putchr(int chr)
{
	write(1, &chr, 1);
	return (1);
}

int		ft_printf(const char *src, ...)
{
	va_list		arguments;
	int			i;
	t_lists		list_of_flags;
	int			count_char;

	va_start(arguments, src);
	count_char = 0;
	i = 0;
	while (src[i] != '\0')
		if (src[i] != '%' && src[i])
			count_char += putchr(src[i++]);
		else if (src[i] == '%' && !src[i + 1])
			break ;
		else if (src[i] == '%' && src[i + 1])
		{
			list_of_flags = ft_init_flags();
			i++;
			i += flag_parser(&src[i], arguments, &list_of_flags, 0);
			if (list_of_flags.type > 0 && src[i++] != '\0')
				count_char += format_treatment(list_of_flags, arguments);
		}
	va_end(arguments);
	return (count_char);
}
