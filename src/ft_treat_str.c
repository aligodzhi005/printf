/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:25:35 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 15:14:36 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_treat_str(char *str, t_lists flags)
{
	int	count_char;

	count_char = 0;
	if (!str)
		str = "(null)";
	if ((size_t)flags.dot >= ft_strlen(str) || flags.dot < 0)
		flags.dot = ft_strlen(str);
	if (flags.width >= flags.dot && flags.minus == 1)
	{
		count_char += ft_putstr(str, flags.dot);
		count_char += ft_write_sp_or_zero(flags.width, flags.dot, flags.zero);
	}
	else if (flags.width >= flags.dot && flags.minus == 0)
	{
		count_char += ft_write_sp_or_zero(flags.width, flags.dot, flags.zero);
		count_char += ft_putstr(str, flags.dot);
	}
	else
		count_char += ft_putstr(str, flags.dot);
	return (count_char);
}
