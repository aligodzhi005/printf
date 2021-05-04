/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:30:45 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 15:06:16 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_treat_percent(t_lists flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		ft_putchar_fd('%', 1);
	char_count += ft_write_sp_or_zero(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ft_putchar_fd('%', 1);
	return (char_count + 1);
}
