/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:41:52 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/14 16:19:19 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	args_init2(t_args *args)
{
	int	i;

	sem_unlink("forks");
	sem_unlink("main");
	sem_unlink("stops");
	sem_unlink("print");
	args->fork = sem_open("forks", O_CREAT, 0600, args->philo_num);
	args->main = sem_open("main", O_CREAT, 0600, args->philo_num);
	args->stops = sem_open("stops", O_CREAT, 0600, 1);
	args->print = sem_open("print", O_CREAT, 0600, 1);
	i = -1;
	while (++i < args->philo_num)
		sem_wait(args->main);
}

t_args	*args_init(t_data *data, int ac)
{
	t_args	*args;

	args = (t_args *)malloc (sizeof(t_args));
	args->philo_num = data->philo_num;
	args->time_to_die = data->time_to_die;
	args->time_to_eat = data->time_to_eat;
	args->time_to_sleep = data->time_to_sleep;
	args->num_of_meals = -1;
	args->flock = 0;
	args->dlock = 0;
	if (ac == 6)
		args->num_of_meals = data->num_of_meals;
	args->stop = 0;
	args->block = 0;
	args->noid = 1;
	args->start_time = time_of_day();
	args_init2(args);
	return (args);
}

t_philo	*philo_init(t_args *args, t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = malloc (sizeof(t_philo) * args->philo_num);
	i = -1;
	philo->noid = 0;
	while (++i < args->philo_num)
	{
		philo[i].pid = 0;
		philo[i].id = i;
		philo[i].noid = 0;
		philo[i].data = data;
		philo[i].args = args;
		philo[i].meals = 0;
		philo[i].time_left_to_die = 0;
		philo[i].locker = 0;
	}
	return (philo);
}
