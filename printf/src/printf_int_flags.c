/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:39:28 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 15:20:42 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		printf_int_flags2(t_lists flags, long long nmbr, char *chr)
{
	int char_count;

	char_count = 0;
	if (nmbr < 0)
		flags.width -= 1;
	if (nmbr < 0 && flags.zero == 1)
	{
		write(1, "-", 1);
		char_count++;
	}
	if (flags.minus == 0)
		char_count += ft_write_sp_or_zero(flags.width, flags.dot, 0);
	if (nmbr < 0 && flags.zero == 0)
	{
		write(1, "-", 1);
		char_count++;
	}
	char_count += ft_write_sp_or_zero(flags.dot, ft_strlen(chr), 1);
	char_count += ft_putstr(chr, ft_strlen(chr));
	if (flags.minus == 1)
		char_count += ft_write_sp_or_zero(flags.width, flags.dot, 0);
	return (char_count);
}

int		print_int_flags(t_lists flags, long long n, int n_len, char *chr)
{
	int char_count;

	char_count = 0;
	if (n < 0 && flags.zero == 1)
	{
		write(1, "-", 1);
		char_count++;
	}
	if (flags.minus == 0)
		char_count += ft_write_sp_or_zero(flags.width, n_len, flags.zero);
	if (n < 0 && flags.zero == 0)
	{
		write(1, "-", 1);
		char_count++;
	}
	char_count += ft_putstr(chr, ft_strlen(chr));
	if (flags.minus == 1)
		char_count += ft_write_sp_or_zero(flags.width, n_len, flags.zero);
	return (char_count);
}

int		ft_treat_int(int nmbr, t_lists flags)
{
	char	*n_chr;
	int		char_count;
	long	nmbr_cpy;
	int		nmbr_lengt;

	nmbr_cpy = nmbr;
	char_count = 0;
	if (nmbr < 0)
		nmbr_cpy *= -1;
	if (flags.dot >= 0)
		flags.zero = 0;
	n_chr = ft_itoa(nmbr_cpy);
	nmbr_lengt = nmbr < 0 ? (int)ft_strlen(n_chr) + 1 : (int)ft_strlen(n_chr);
	if (flags.dot == 0 && nmbr == 0)
		char_count += ft_write_sp_or_zero(flags.width, flags.dot, 0);
	else if (flags.dot < nmbr_lengt)
		char_count += print_int_flags(flags, nmbr, nmbr_lengt, n_chr);
	else
		char_count += printf_int_flags2(flags, nmbr, n_chr);
	free(n_chr);
	return (char_count);
}
