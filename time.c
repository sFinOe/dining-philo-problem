/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:21:51 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/08 19:22:43 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	time_of_day(void)
{
	unsigned int	time_ms;
	struct timeval	current_time;

	time_ms = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		error("error getting time\n");
	time_ms = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time_ms);
}

void	ml_sleep(long int time_in_ms)
{
	long int	start_time;

	start_time = time_of_day();
	while ((time_of_day() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
