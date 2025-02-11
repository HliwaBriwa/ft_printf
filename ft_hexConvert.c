/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexConvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:58:39 by sel-mir           #+#    #+#             */
/*   Updated: 2024/11/16 18:39:15 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_adr_run(unsigned long long n, size_t *lentos)
{
	*lentos += write(1, "0x", 2);
	ft_lil_hexconvert(n, lentos);
}

void	ft_big_hexconvert(unsigned long long n, size_t *lentos)
{
	unsigned long long	mod;

	if (n < 16 && n >= 0)
	{
		if (n <= 9 && n >= 0)
		{
			mod = n + 48;
			*lentos += write(1, &mod, 1);
		}
		else if (n <= 15 && n >= 10)
		{
			mod = n + 'A' - 10;
			*lentos += write(1, &mod, 1);
		}
	}
	else if (!(n < 16 && n >= 0) && n)
	{
		ft_big_hexconvert(n / 16, lentos);
		ft_big_hexconvert(n % 16, lentos);
	}
}

void	ft_lil_hexconvert(unsigned long long n, size_t *lentos)
{
	unsigned long long	mod;

	if (n < 16 && n >= 0)
	{
		if (n <= 9 && n >= 0)
		{
			mod = n + 48;
			*lentos += write(1, &mod, 1);
		}
		else if (n <= 15 && n >= 10)
		{
			mod = n + 'a' - 10;
			*lentos += write(1, &mod, 1);
		}
	}
	else if (!(n < 16 && n >= 0) && n)
	{
		ft_lil_hexconvert(n / 16, lentos);
		ft_lil_hexconvert(n % 16, lentos);
	}
}
