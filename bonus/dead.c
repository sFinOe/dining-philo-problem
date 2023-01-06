/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:40:25 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/14 15:41:38 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_die(t_philo *philo, t_args *args, int swt)
{
	int	i;

	if (swt == 0)
	{
		usleep(100);
		sem_wait(args->print);
		if (!(args->stop == 1))
		{
			args->stop = 1;
			printf("|%u|\t", time_of_day() - args->first_time);
			printf("|%d|\t|%s|\n", philo->id + 1, " 💀 Died\t\t");
		}
		i = -1;
		while (++i < args->philo_num)
			sem_post(args->main);
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
	}
}

void	clearall(t_philo *philo, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->philo_num)
		kill(philo[i].pid, SIGKILL);
	sem_close(args->fork);
	sem_close(args->main);
	sem_close(args->stops);
	sem_close(args->print);
	free(args);
	free(philo);
}
