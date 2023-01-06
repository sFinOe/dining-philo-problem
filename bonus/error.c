/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:41:42 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/14 15:41:45 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	return ;
}

int	intcheck(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_atoi(str);
	if (ft_atoiplus(str) == 0)
	{
		error("Wrong Num input\n");
		return (1);
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
		{
			error("Only Numbers allowed!\n");
			return (1);
		}
	}
	return (0);
}
