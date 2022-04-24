/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:45:09 by pskip             #+#    #+#             */
/*   Updated: 2022/03/23 18:39:51 by pskip            ###   ########.fr       */
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

typedef struct s_philos_data
{
	int				num_philos;
	int				num_ate_phil;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	int				num_of_eat;
	int				any_dead;

}		t_philos_data;

typedef struct s_phil
{
	pthread_t		p_id;
	int				place;
	char			status;
	long long		last_eat_time;
	int				ate_time_at_all;
	t_philos_data	*meta;
}		t_phil;

void	*living(void *phil);
int		ft_atoi(char *str);
#endif