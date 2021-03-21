/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:31:31 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 15:15:19 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_treat_uix(unsigned int nmbr, t_lists flags)
{
	int					i;
	char				*n_chr;
	int					char_count;
	unsigned long long	nmbr_cpy;
	int					nmbr_length;

	nmbr_cpy = nmbr;
	i = 0;
	char_count = 0;
	if (nmbr < 0)
		nmbr_cpy *= -1;
	if (flags.dot >= 0)
		flags.zero = 0;
	n_chr = ft_ull_base(nmbr_cpy, 10);
	nmbr_length = nmbr < 0 ? (int)ft_strlen(n_chr) + 1 : (int)ft_strlen(n_chr);
	if (flags.dot == 0 && nmbr == 0)
		char_count += ft_write_sp_or_zero(flags.width, flags.dot, 0);
	else if (flags.dot < nmbr_length)
		char_count += print_int_flags(flags, nmbr, nmbr_length, n_chr);
	else
		char_count += printf_int_flags2(flags, nmbr, n_chr);
	free(n_chr);
	return (char_count);
}
