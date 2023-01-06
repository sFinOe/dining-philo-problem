/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:40:19 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/14 15:40:20 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	checkargs(int ac, char **av, t_data *data)
{
	int	i;

	i = ac - 1;
	while (av[i] && i != 0)
	{
		if (intcheck(av[i]) == 1)
		{
			error("Error\n");
			return (1);
		}
		i--;
	}
	settargs(av, data, ac);
	if (data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0)
	{
		error("Wrong num input only positive num\n");
		return (1);
	}
	return (0);
}

void	settargs(char **av, t_data *data, int ac)
{
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->noid = 0;
	if (ac == 6)
	{
		data->num_of_meals = ft_atoi(av[5]);
	}
}
