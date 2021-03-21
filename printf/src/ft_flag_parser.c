/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:08:40 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 14:57:09 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	flag_dot(const char *src, t_lists *flags, int i)
{
	i++;
	flags->dot = 0;
	while (ft_isdigit(src[i]))
		flags->dot = (flags->dot * 10) + (src[i++] - '0');
	return (i);
}

static void	flag_star(va_list arg, t_lists *flags)
{
	if (flags->dot >= 0)
		flags->dot = va_arg(arg, int);
	else
	{
		flags->width = va_arg(arg, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->zero = 0;
			flags->width *= -1;
		}
	}
}

static void	flag_minus(t_lists *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

static void	flag_width(t_lists *flags, const char *str, int i)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (str[i] - '0');
}

int			flag_parser(const char *src, va_list arg, t_lists *flags, int i)
{
	while (1)
	{
		if (!ft_isdigit(src[i]) && !ft_is_in_type_list(src[i])
				&& !ft_is_in_flags_list(src[i]))
			break ;
		if (src[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (src[i] == '-')
			flag_minus(flags);
		if (src[i] == '.')
			i = flag_dot(src, flags, i);
		if (src[i] == '*')
			flag_star(arg, flags);
		if (ft_isdigit(src[i]))
			flag_width(flags, src, i);
		else if (ft_is_in_type_list(src[i]))
		{
			flags->type = src[i];
			break ;
		}
		i++;
	}
	return (i);
}
