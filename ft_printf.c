/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:00:26 by sel-mir           #+#    #+#             */
/*   Updated: 2024/11/18 00:47:30 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(const char *str, size_t	*lentos)
{
	int	a;

	if (!str)
	{
		*lentos += write(1, "(null)", 6);
		return ;
	}
	a = 0;
	while (str[a])
	{
		*lentos += write (1, &str[a], 1);
		a++;
	}
}

void	ft_other_cases(const char *str, va_list *holder,
	size_t	*a, size_t *lentos)
{
	if (str[*a] == '%' && str[(*a) + 1] == 's')
	{
		ft_write(va_arg(*holder, const char *), lentos);
		(*a)++;
	}
	else if (str[*a] == '%' && str[*a + 1] == 'u')
	{
		ft_putnbr_unsigned(va_arg(*holder, unsigned int), lentos);
		(*a)++;
	}
	else if (str[*a] == '%' && str[*a + 1] == 'X')
	{
		ft_big_hexconvert(va_arg(*holder, unsigned int), lentos);
		(*a)++;
	}
	else if (str[*a] == '%' && str[*a + 1] == 'x')
	{
		ft_lil_hexconvert(va_arg(*holder, unsigned int), lentos);
		(*a)++;
	}
	else if (str[*a] == '%' && str[*a + 1] == 'p')
	{
		ft_print_adr_run(va_arg(*holder, unsigned long long), lentos);
		(*a)++;
	}
}

int	ft_printf(const char *spf, ...)
{
	size_t	a;
	va_list	holder;
	size_t	lentos;

	if (write(1, 0, 0) == -1)
		return (-1);
	a = 0;
	lentos = 0;
	va_start(holder, spf);
	while (spf[a])
	{
		if (spf[a] == '%' && spf[a + 1] == '%')
		{
			lentos += write(1, "%", 1);
			a++;
		}
		else if ((spf[a] == '%' && spf[a + 1] != '%'))
			ft_second_other(spf, &holder, &a, &lentos);
		else
			lentos += write(1, &spf[a], 1);
		a++;
	}
	va_end(holder);
	return (lentos);
}

void	ft_second_other(const char *spf, va_list	*holder,
	size_t	*a, size_t *lentos)
{
	char	c;

	if (spf[*a] == '%' && (spf[*a + 1] == 'd' || spf[*a + 1] == 'i'))
	{
		ft_putnbr(va_arg(*holder, int), lentos);
		(*a)++;
	}
	else if (spf[*a] == '%' && spf[*a + 1] == 'c')
	{
		c = (va_arg(*holder, int));
		*lentos += write(1, &c, 1);
		(*a)++;
	}
	else
		ft_other_cases(spf, holder, a, lentos);
}
