/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:25:16 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/14 16:14:28 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printf(t_args *args, t_philo *philo, char *str)
{
	unsigned int	time;

	if (args->stop == 0)
	{
		pthread_mutex_lock(&args->print);
		time = time_of_day() - args->first_time;
		printf("|%u|\t|%d|\t|%s\t|\n", time, philo->id + 1, str);
		pthread_mutex_unlock(&args->print);
	}
}

void	clearall(t_philo *philo, t_args *args)
{
	int		i;

	i = -1;
	while (++i < args->philo_num)
		pthread_mutex_destroy(&args->fork[i]);
	pthread_mutex_destroy(&args->print);
	pthread_mutex_destroy(&args->main);
	pthread_mutex_destroy(&philo->lock);
	free(args);
	free(philo);
}

t_philo	*ft_init2(t_args *args)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc (sizeof(t_philo) * args->philo_num);
	pthread_mutex_init(&philo->lock, NULL);
	i = -1;
	while (++i < args->philo_num)
	{
		pthread_mutex_init(&args->fork[i], NULL);
		philo[i].l_f = i;
		philo[i].id = i;
		philo[i].args = args;
		philo[i].time_left_to_die = 0;
		philo[i].r_f = (i + 1) % args->philo_num;
		philo[i].meals = 0;
		philo[i].locker = 0;
	}
	return (philo);
}

t_args	*ft_init(t_data *data, int ac)
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
	args->fork = malloc (sizeof(pthread_mutex_t) * args->philo_num);
	args->start_time = time_of_day();
	pthread_mutex_init(&args->main, NULL);
	pthread_mutex_lock(&args->main);
	return (args);
}
