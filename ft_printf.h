/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:24:15 by sanbaek           #+#    #+#             */
/*   Updated: 2024/05/11 15:24:15 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_etc
{
	int						n;
	unsigned int			u;
	char					*string;
	long long unsigned int	*ads;
}	t_etc;
int	ft_printf(const char *str, ...);
int	ft_putfmt_cdux(t_etc *etc, va_list ap, char c);
int	ft_putfmt_sp(t_etc *etc, va_list ap, char c);
int	ft_strlen(const char *s);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putll_fd(long long int n, int fd);
int	ft_puthex_fd(int islower, long long unsigned int n, int fd);

#endif /* FT_PRINTF_H */
