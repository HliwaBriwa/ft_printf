/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:27:11 by sel-mir           #+#    #+#             */
/*   Updated: 2024/11/16 18:44:11 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr(int n, size_t *lentos);
void	ft_lil_hexconvert(unsigned long long n, size_t *lentos);
void	ft_big_hexconvert(unsigned long long n, size_t *lentos);
void	ft_print_adr_run(unsigned long long n, size_t *lentos);
int		ft_printf(const char *spf, ...);
void	ft_putnbr_unsigned(unsigned int n, size_t *lentos);
void	ft_second_other(const char *spf, va_list	*holder,
			size_t	*a, size_t *lentos);
#endif