/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:39:03 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 15:20:10 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_ull_base2(unsigned long long address, int length,
		char *address_chr, int base)
{
	while (address)
	{
		if ((address % base) < 10)
			address_chr[length - 1] = address % base + 48;
		else
			address_chr[length - 1] = address % base + 87;
		length--;
		address /= base;
	}
	return (address_chr);
}

char		*ft_ull_base(unsigned long long address, int base)
{
	int					length;
	char				*address_chr;
	unsigned long long	address_cpy;

	length = 0;
	address_cpy = address;
	if (address == 0)
		return (ft_strdup("0"));
	while (address_cpy)
	{
		length++;
		address_cpy /= base;
	}
	if (!(address_chr = malloc(sizeof(char) * (length + 1))))
		return (0);
	address_chr[length] = '\0';
	address_chr = ft_ull_base2(address, length, address_chr, base);
	return (address_chr);
}
