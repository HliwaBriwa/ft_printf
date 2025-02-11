/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:08:01 by sel-mir           #+#    #+#             */
/*   Updated: 2024/11/16 18:43:25 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(int c, size_t *lentos)
{
	c += 48;
	*lentos += write (1, &c, 1);
}

void	ft_putnbr(int n, size_t *lentos)
{
	if (n == -2147483648)
	{
		*lentos += write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*lentos += write (1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, lentos);
		ft_putnbr(n % 10, lentos);
	}
	else if (n <= 9 && n >= 0)
		ft_putchar(n, lentos);
}

void	ft_putnbr_unsigned(unsigned int n, size_t *lentos)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, lentos);
		ft_putnbr_unsigned(n % 10, lentos);
	}
	else if (n <= 9 && n >= 0)
		ft_putchar(n, lentos);
}
