/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:09:53 by zkasmi            #+#    #+#             */
/*   Updated: 2022/02/14 16:14:52 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	unsigned int	time_left_to_die;
	pthread_mutex_t	lock;
	int				locker;
	int				r_f;
	int				l_f;
	int				id;
	int				meals;
	pthread_t		th;
	struct s_args	*args;

}	t_philo;

typedef struct s_args
{
	int				block;
	int				stop;
	unsigned int	start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	main;
	pthread_mutex_t	finish;
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
}	t_data;

int				checkargs(int ac, char **av, t_data *data);
int				intcheck(char *str);
void			error(char *str);
void			settargs(char **av, t_data *data, int ac);
unsigned int	time_of_day(void);
void			ml_sleep(long int time_in_ms);
void			*threading(void *arg);
void			ft_printf(t_args *args, t_philo *philo, char *str);
t_args			*ft_init(t_data *data, int ac);
void			*checkifdie(void *arg);
void			ft_die(t_philo *philo, t_args *args, int swt);
int				ft_atoiplus(const char *str);
void			*check_if_die(void *arg);
void			clearall(t_philo *philo, t_args *args);
t_philo			*ft_init2(t_args *args);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);

#endif