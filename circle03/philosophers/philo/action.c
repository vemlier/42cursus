/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:38:03 by chukim            #+#    #+#             */
/*   Updated: 2022/08/05 18:03:27 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_pass_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	while (!(arg->finish))
	{
		now = ft_get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(arg->philo_num);
	}
}

int	ft_philo_printf(t_arg *arg, int id, char *msg)
{
	long long	now;

	pthread_mutex_lock(&(arg->print));
	if (!(arg->finish))
	{
		now = ft_get_time();
		if (now == -1)
		{
			pthread_mutex_unlock(&(arg->print));
			return (-1);
		}
		printf("%lld %d %s\n", now - arg->start_time, id + 1, msg);
	}
	pthread_mutex_unlock(&(arg->print));
	return (0);
}

int	ft_philo_action(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left]));
	ft_philo_printf(arg, philo->id, "has taken a fork");
	if (arg->philo_num != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right]));
		ft_philo_printf(arg, philo->id, "has taken a fork");
		ft_philo_printf(arg, philo->id, "is eating");
		philo->last_eat_time = ft_get_time();
		philo->eat_count = philo->eat_count + 1;
		ft_pass_time((long long)arg->time_to_eat, arg);
		pthread_mutex_unlock(&(arg->forks[philo->right]));
	}
	pthread_mutex_unlock(&(arg->forks[philo->left]));
	return (0);
}
