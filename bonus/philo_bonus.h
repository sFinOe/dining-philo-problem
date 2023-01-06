/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:48:32 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/14 16:19:31 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_args
{
	sem_t			*fork;
	sem_t			*main;
	sem_t			*stops;
	sem_t			*print;
	int				block;
	int				stop;
	unsigned int	start_time;
	struct s_philo	*philo;
	struct s_data	*data;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	unsigned int	first_time;
	int				noid;
	int				dlock;
	int				flock;
}	t_args;

typedef struct s_data
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_meals;
	int	noid;
}	t_data;

typedef struct s_philo
{
	unsigned int	time_left_to_die;
	int				locker;
	int				id;
	int				meals;
	int				noid;
	struct s_args	*args;
	t_data			*data;
	pid_t			pid;
}	t_philo;

int				checkargs(int ac, char **av, t_data *data);
int				intcheck(char *str);
void			error(char *str);
void			settargs(char **av, t_data *data, int ac);
unsigned int	time_of_day(void);
void			ml_sleep(long int time_in_ms);
void			ft_printf(t_args *args, t_philo *philo, char *str);
t_args			*args_init(t_data *data, int ac);
void			ft_die(t_philo *philo, t_args *args, int swt);
int				ft_atoiplus(const char *str);
void			*check_if_die(void *arg);
t_philo			*philo_init(t_args *args, t_data *data);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
void			routine(t_philo *philo, t_args *args);
void			check_if_die2(t_philo *philo, t_args *args);
void			clearall(t_philo *philo, t_args *args);

#endif