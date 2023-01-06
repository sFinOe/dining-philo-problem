/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:22:53 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/08 19:53:06 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoiplus2(const char *str, int i, int long total, int long pow)
{
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		total = total * 10 + (str[i] - '0');
		i++;
	}
	if ((total * pow) > 2147483647 || (total * pow) < -2147483648)
		return (0);
	return (1);
}

int	ft_atoiplus(const char *str)
{
	int long	pow;
	int			i;
	int long	total;
	int			j;

	j = 0;
	total = 0;
	pow = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			pow = -1;
			j++;
		}
		i++;
	}
	if (j > 1)
		return (0);
	return (ft_atoiplus2(str, i, total, pow));
}

int	ft_atoi(const char *str)
{
	int		pow;
	int		i;
	int		total;

	total = 0;
	pow = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			pow = -1 ;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	return (total * pow);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
		i++;
		}
	}
}
