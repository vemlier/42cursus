/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:56:23 by chukim            #+#    #+#             */
/*   Updated: 2022/08/10 23:43:43 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_philo
{
	struct s_arg	*arg;
	pthread_t		thread;
	int				id;
	int				right;
	int				left;
	long long		last_eat_time;
	int				eat_count;
}	t_philo;

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				finish;
	int				finished_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_arg;

// philosophers.c
void		*ft_thread_action(void *argv);
void		ft_free_thread(t_arg *arg, t_philo *philo);
void		ft_philo_check_finish(t_arg *arg, t_philo *philo);
int			ft_philo_start(t_arg *arg, t_philo *philo);

// action.c
void		ft_pass_time(long long wait_time, t_arg *arg);
int			ft_philo_printf(t_arg *arg, int id, char *msg);
int			ft_philo_action(t_arg *arg, t_philo *philo);

// preprocess.c
int			print_error(char *error, int code);
int			ft_arg_init_mutex(t_arg *arg);
int			ft_arg_init(t_arg *arg, int argc, char *argv[]);
int			ft_philo_init(t_philo **philo, t_arg *arg);

// utils.c
int			ft_atoi(char const *str);
long long	ft_get_time(void);

#endif