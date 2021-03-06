/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:23:30 by fsarbout          #+#    #+#             */
/*   Updated: 2022/02/13 16:11:17 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philos	*ph;

	ph = (t_philos *)arg;
	while (1)
	{
		take_forks(ph);
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
	return (NULL);
}

void	take_forks(t_philos *ph)
{
	pthread_mutex_lock(&ph->data->f_mutex[ph->id]);
	print_status("has taken a fork", "\e[1;33m", ph, ph->id);
	pthread_mutex_lock(&ph->data->f_mutex[(ph->id + 1)
		% ph->data->nb_philos]);
	print_status("has taken a fork", "\e[1;33m", ph, ph->id);
}

void	eating(t_philos *ph)
{
	ph->is_eating = 1;
	pthread_mutex_lock(&ph->data->e_mutex[ph->id]);
	ph->last_eat = get_time();
	pthread_mutex_unlock(&ph->data->e_mutex[ph->id]);
	print_status("is eating", "\e[1;32m", ph, ph->id);
	ph->eat_nb++;
	u_sleep(ph->data->time_to_eat * 1000);
	pthread_mutex_unlock(&ph->data->f_mutex[(ph->id + 1)
		% ph->data->nb_philos]);
	pthread_mutex_unlock(&ph->data->f_mutex[ph->id]);
	ph->is_eating = 0;
}

void	sleeping(t_philos *ph)
{
	print_status("is sleeping", "\e[1;35m", ph, ph->id);
	u_sleep(ph->data->time_to_sleep * 1000);
}

void	thinking(t_philos *ph)
{
	print_status("is thinking", "\e[1;34m", ph, ph->id);
}
