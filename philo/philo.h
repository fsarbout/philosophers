/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:27:38 by fsarbout          #+#    #+#             */
/*   Updated: 2021/12/03 14:22:32 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
# include <sys/time.h>
# include <string.h>

# define TO_MICRO_S 1000

#define DEFAULT "\033[0m"
#define GREEN "\e[1;32m"
#define RED "\e[1;31m"
#define WHITE "\e[1;37m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define PURPLE "\033[1;35m"

typedef struct s_data
{
    int nb_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int n_necessity_to_eat;
    int num_forks;
    pthread_t th;
    pthread_mutex_t mutex;
    //data type : ID of a thread . return by pthread_create
}       t_data;

typedef struct s_philos
{
    t_data  data;
    int     id;
    // int     is_dead;
    // int     last_eat; 
}   t_philos;

int	    ft_atoi(const char *s);
void	exit_(char *string, int error);
void    print_status(t_data *data);
int     is_pair(int i);
void	fill_data(t_data *data, t_philos **philo, char **av,int ac);
void    *routine(void *);

#endif