/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:49:41 by pskip             #+#    #+#             */
/*   Updated: 2022/03/22 12:49:59 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	real_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

static void	printer(t_phil *phil, char *str)
{
	long long	time;

	time = real_time();
	if (!phil->meta->any_dead)
	{
		pthread_mutex_lock(&(phil->meta->print_mutex));
		printf("%16s %3d ---> %lld\n", str, phil->place, time % 10000000);
		pthread_mutex_unlock(&(phil->meta->print_mutex));
	}
}

static int	sleeper(t_phil *phil, int sleep_time)
{
	long long	time;
	long long	new_time;

	time = real_time();
	new_time = real_time();
	while (new_time - time <= sleep_time)
	{
		usleep(50);
		new_time = real_time();
		if (new_time - phil->last_eat_time > phil->meta->die_time)
		{
			pthread_mutex_lock(&(phil->meta->print_mutex));
			phil->meta->any_dead = 1;
			printf("dead_man_detected\n");
			return (DIED);
		}
	}
	return (ALIVE);
}

static int	eater(t_phil *phil)
{
	pthread_mutex_lock(&(phil->meta->forks[phil->prev]));
	printer(phil, "took_left_fork");
	pthread_mutex_lock(&(phil->meta->forks[phil->next]));
	printer(phil, "took_right_fork");
	printer(phil, "start_eating");
	if (!sleeper(phil, phil->meta->eat_time))
		return (DIED);
	phil->last_eat_time = real_time();
	pthread_mutex_unlock(&(phil->meta->forks[phil->prev]));
	printer(phil, "drop_left_fork");
	pthread_mutex_unlock(&(phil->meta->forks[phil->next]));
	printer(phil, "drop_right_fork");
	printer(phil, "end_eating");
	phil->ate_time++;
	if (phil->ate_time == phil->meta->num_of_eat)
	{
		phil->meta->num_ate_phil++;
		return (DIED);
	}
	return (ALIVE);
}

void	*living(void *phil_void)
{
	t_phil			*phil;

	phil = (t_phil *)phil_void;
	printer(phil, "start");
	phil->last_eat_time = real_time();
	if (!(phil->place % 2))
		sleeper(phil, (phil->meta->eat_time / 3));
	if (!(phil->place))
		sleeper(phil, (phil->meta->eat_time / 3 * 2));
	while (((phil->meta->num_of_eat == -1)
			|| (phil->ate_time < phil->meta->num_of_eat))
		&& (!phil->meta->any_dead))
	{
		if (!(phil->meta->any_dead || eater(phil)))
			return ((void *)DIED);
		printer(phil, "sleep_start");
		if (!(phil->meta->any_dead || sleeper(phil, phil->meta->sleep_time)))
			return ((void *)DIED);
		printer(phil, "sleep_end");
	}
	return ((void *)ALIVE);
}
