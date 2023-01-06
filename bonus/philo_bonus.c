/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:44:25 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/15 15:05:43 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main2(t_args *args, t_philo *philo, int i, int j)
{
	i = -1;
	while (++i < args->philo_num)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			routine(&philo[i], args);
			exit(0);
		}
		if (philo[i].pid == -1)
		{
			printf("error creating childs!!\n");
			return (1);
		}
		usleep(100);
	}
	j = -1;
	while (++j < args->philo_num)
		sem_wait(args->main);
	clearall(philo, args);
	return (0);
}

int	main(int ac, char **av)
{
	t_args		*args;
	t_philo		*philo;
	t_data		data;
	int			i;
	int			j;

	if (ac == 5 || ac == 6)
	{
		if (checkargs(ac, av, &data) == 1)
			return (1);
		if (data.philo_num == 0)
		{
			error("atleast one philo\n");
			return (1);
		}
		args = args_init(&data, ac);
		philo = philo_init(args, &data);
		args->first_time = time_of_day();
		i = 0;
		j = 0;
		return (main2(args, philo, i, j));
	}
	else
		error("4 agrs pls!\n");
	return (0);
}
