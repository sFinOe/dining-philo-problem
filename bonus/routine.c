/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:49:48 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/14 15:51:01 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine2(t_philo *philo, t_args *args)
{
	while (args->stop == 0)
	{
		if (philo->meals == args->num_of_meals)
			break ;
		sem_wait(args->fork);
		ft_printf(args, philo, " 🍴take the left fork");
		sem_wait(args->fork);
		ft_printf(args, philo, " 🍴take the right fork");
		ft_printf(args, philo, " 🍽️  start eating!!");
		philo->time_left_to_die = time_of_day() + args->time_to_die;
		ml_sleep(args->time_to_eat);
		philo->meals++;
		philo->noid++;
		sem_post(args->fork);
		sem_post(args->fork);
		if (philo->meals == args->num_of_meals)
			break ;
		ft_printf(args, philo, " 😴 is sleeping!!");
		ml_sleep(args->time_to_sleep);
		ft_printf(args, philo, " 🤔 is thinking!!");
	}
	sem_post(args->main);
}

void	routine(t_philo *philo, t_args *args)
{
	pthread_t	ph;

	pthread_create(&ph, NULL, &check_if_die, philo);
	pthread_detach(ph);
	if (philo->id % 2 == 0)
		usleep(100);
	routine2(philo, args);
}
