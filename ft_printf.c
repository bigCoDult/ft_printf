/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:17:26 by sanbaek           #+#    #+#             */
/*   Updated: 2024/05/10 13:17:26 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_format(char c, va_list ap);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_put_format(*str, ap);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(ap);
	return (count);
}

int	ft_put_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		count += ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	else if (c == 'x')
		count += ft_puthex_fd(1, va_arg(ap, unsigned int), 1);
	else if (c == 'X')
		count += ft_puthex_fd(0, va_arg(ap, unsigned int), 1);
	else if (c == 'p')
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_puthex_fd(1, va_arg(ap, unsigned long long), 1);
	}
	return (count);	
}
