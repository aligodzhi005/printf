/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_treatment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:29:47 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 19:41:48 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_lists		ft_init_flags(void)
{
	t_lists	flags;

	flags.dot = -1;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.type = 0;
	return (flags);
}

int			ft_is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int			ft_is_in_flags_list(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int			format_treatment(t_lists flags, va_list arg)
{
	int count_char;

	count_char = 0;
	if (flags.type == 's')
		count_char += ft_treat_str(va_arg(arg, char*), flags);
	if (flags.type == 'c')
		count_char += ft_treat_char(va_arg(arg, int), flags);
	if (flags.type == 'd' || flags.type == 'i')
		count_char += ft_treat_int(va_arg(arg, int), flags);
	if (flags.type == 'p')
		count_char += ft_treat_pointer(va_arg(arg, unsigned long long), flags);
	if (flags.type == 'x')
		count_char += ft_treat_hexa(va_arg(arg, unsigned long long), flags, 0);
	if (flags.type == 'X')
		count_char += ft_treat_hexa(va_arg(arg, unsigned long long), flags, 1);
	if (flags.type == 'u')
		count_char += ft_treat_uix(va_arg(arg, unsigned int), flags);
	if (flags.type == '%')
		count_char += ft_treat_percent(flags);
	return (count_char);
}
