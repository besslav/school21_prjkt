/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:45:09 by pskip             #+#    #+#             */
/*   Updated: 2022/03/22 12:45:10 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define DIED  0
# define ALIVE 1

typedef struct s_philos
{
	int				num_philos;
	int				num_ate_phil;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	int				num_of_eat;
	int				any_dead;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
}		t_philos;

typedef struct s_phil
{
	pthread_t	id;
	int			place;
	char		status;
	long long	last_eat_time;
	int			ate_time;
	t_philos	*meta;
	int			prev;
	int			next;
}		t_phil;

void	*living(void *phil);
int		ft_atoi(char *str);
#endif