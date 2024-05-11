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
# include <stdlib.h>
# include <unistd.h>

typedef struct s_nums
{
	int				count;
	unsigned int	u;
}	t_nums;

int	ft_printf(const char *str, ...);
int	ft_putfmt(t_nums *nums, va_list ap, char c, unsigned long long int ptr);

int	ft_strlen(const char *s);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);

int	ft_putlonglong_fd(long long n, int fd);
int	ft_puthex_fd(int islower, unsigned long long int n, int fd);

#endif /* FT_PRINTF_H */
