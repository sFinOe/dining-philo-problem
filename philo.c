/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:13:56 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/08 19:13:56 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main2(t_args *args, t_philo *philo, int i)
{
	while (++i < args->philo_num)
	{
		if (pthread_create(&philo->th, NULL, threading, &philo[i]) != 0)
		{
			error("Error Creating thread\n");
			return (1);
		}
		pthread_detach(philo->th);
	}
	pthread_mutex_lock(&args->main);
	clearall(philo, args);
	return (1);
}

int	main(int ac, char **av)
{
	t_args		*args;
	t_philo		*philo;
	t_data		data;
	int			i;

	if (ac == 5 || ac == 6)
	{
		if (checkargs(ac, av, &data) == 1)
			return (1);
		if (data.philo_num == 0)
		{
			error("atleast one philo\n");
			return (1);
		}
		args = ft_init(&data, ac);
		philo = ft_init2(args);
		i = -1;
		args->first_time = time_of_day();
		return (main2(args, philo, i));
	}
	else
		error("4 agrs pls!\n");
	return (0);
}
