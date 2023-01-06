/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:49:33 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/14 15:49:40 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_printf(t_args *args, t_philo *philo, char *str)
{
	unsigned int	time;

	sem_wait(args->print);
	if (args->stop == 0)
	{
		time = time_of_day() - args->first_time;
		printf("|%u|\t|%d|\t|%s\t|\n", time, philo->id + 1, str);
	}
	sem_post(args->print);
}
