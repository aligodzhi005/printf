/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:45:43 by rvena             #+#    #+#             */
/*   Updated: 2021/01/27 19:40:41 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_lists
{
	int			dot;
	int			width;
	int			minus;
	int			type;
	int			zero;
	int			star;
}				t_lists;

int				ft_printf(const char *src, ...);
int				format_treatment(t_lists list_of_flags,
							va_list arguments);
int				ft_putstr(char *str, int len);
char			*ft_ull_base(unsigned long long address, int base);
int				ft_is_in_type_list(int c);
int				ft_is_in_flags_list(int c);
t_lists			ft_init_flags(void);
int				flag_parser(const char *src, va_list arg,
							t_lists *flags, int i);
int				ft_treat_uix(unsigned int nmbr, t_lists flags);
int				ft_treat_percent(t_lists flags);
int				ft_treat_hexa(unsigned int nmbr, t_lists flags, int higher);
int				ft_treat_pointer(unsigned long long address, t_lists flags);
int				ft_treat_int(int nmbr, t_lists flags);
int				ft_treat_char(char c, t_lists flags);
int				ft_treat_str(char *str, t_lists flags);
int				ft_write_sp_or_zero(int width, int length_str, int has_zero);
int				ft_putstr(char *str, int len);
int				printf_int_flags2(t_lists flags, long long nmbr, char *chr);
int				print_int_flags(t_lists flags, long long n,
							int n_len, char *chr);
char			*ft_str_toupper(char *str);

#endif
