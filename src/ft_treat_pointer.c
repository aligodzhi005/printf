/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:27:58 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 15:12:00 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_treat_pointer(unsigned long long address, t_lists flags)
{
	int		c_cnt;
	char	*adr_chr;

	c_cnt = 0;
	if (address == 0 && flags.dot == 0)
	{
		if (flags.minus == 0)
			c_cnt += ft_write_sp_or_zero(flags.width, 2, 0);
		c_cnt += ft_putstr("0x", 2);
		if (flags.minus == 1)
			return (c_cnt += ft_write_sp_or_zero(flags.width, 2, 0));
		return (c_cnt);
	}
	adr_chr = ft_ull_base(address, 16);
	if (flags.minus == 0)
		c_cnt += ft_write_sp_or_zero(flags.width, ft_strlen(adr_chr) + 2, 0);
	c_cnt += ft_putstr("0x", 2);
	c_cnt += ft_putstr(adr_chr, ft_strlen(adr_chr));
	if (flags.minus == 1)
		c_cnt += ft_write_sp_or_zero(flags.width, ft_strlen(adr_chr) + 2, 0);
	free(adr_chr);
	return (c_cnt);
}
