/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:28:51 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/15 15:57:02 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_die(t_philo *philo, t_args *args, int swt)
{
	if (swt == 0)
	{
		usleep(100);
		pthread_mutex_lock(&args->print);
		if (!(args->stop == 1))
		{
			args->stop = 1;
			printf("|%u|\t", time_of_day() - args->first_time);
			printf("|%d|\t|%s|\n", philo->id + 1, " 💀 Died\t\t");
		}
		pthread_mutex_unlock(&args->main);
	}
	if (swt == 1)
	{
		usleep(100);
		pthread_mutex_lock(&args->print);
		if (!(args->stop == 1))
		{
			args->stop = 1;
			printf("|\teach philo has eaten %d meals\t|\n", args->num_of_meals);
		}
		pthread_mutex_unlock(&args->main);
	}
}

void	check_if_die2(t_philo *philo, t_args *args)
{
	while (1)
	{
		if (time_of_day() > philo->time_left_to_die && args->dlock == 0)
		{
			args->dlock = 1;
			ft_die(philo, args, 0);
			args->stop = 1;
		}
		if (philo->meals == args->num_of_meals)
		{
			if (philo->locker == 0)
			{
				args->noid++;
				philo->locker = 1;
			}
			if (args->noid == args->philo_num && args->flock == 0)
			{
				args->flock = 1;
				ft_die(philo, args, 1);
				args->stop = 1;
			}
			usleep(100);
		}
	}
}

void	*check_if_die(void *arg)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)arg;
	args = philo->args;
	philo->time_left_to_die = time_of_day() + args->time_to_die;
	check_if_die2(philo, args);
	return (NULL);
}

void	routine(t_args *args, t_philo *philo)
{
	while (args->stop == 0)
	{
		if (philo->meals == args->num_of_meals)
			while (1)
				;
		pthread_mutex_lock(&args->fork[philo->l_f]);
		ft_printf(args, philo, " 🍴take the left fork");
		pthread_mutex_lock(&args->fork[philo->r_f]);
		ft_printf(args, philo, " 🍴take the right fork");
		ft_printf(args, philo, " 🍽️  start eating!!");
		philo->time_left_to_die = time_of_day() + args->time_to_die;
		ml_sleep(args->time_to_eat);
		pthread_mutex_unlock(&args->fork[philo->l_f]);
		pthread_mutex_unlock(&args->fork[philo->r_f]);
		philo->meals++;
		if (philo->meals == args->num_of_meals)
			while (1)
				;
		ft_printf(args, philo, " 😴 is sleeping!!");
		ml_sleep(args->time_to_sleep);
		ft_printf(args, philo, " 🤔 is thinking!!");
		if (philo->id % 2 == 0)
			usleep(100);
	}
}

void	*threading(void *arg)
{
	t_philo		*philo;
	t_args		*args;
	pthread_t	th;

	philo = (t_philo *)arg;
	args = philo->args;
	pthread_create(&th, NULL, &check_if_die, philo);
	pthread_detach(th);
	routine(args, philo);
	return (NULL);
}
