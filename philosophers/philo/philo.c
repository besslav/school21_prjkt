/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:47:22 by pskip             #+#    #+#             */
/*   Updated: 2022/03/22 12:53:57 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philos	*get_philos_info(int ac, char **av)
{
	t_philos	*info;

	info = (t_philos *)malloc (sizeof(t_philos));
	if (info)
	{
		info->num_philos = ft_atoi(av[1]);
		info->die_time = ft_atoi(av[2]);
		info->eat_time = ft_atoi(av[3]);
		info->sleep_time = ft_atoi(av[4]);
		info->any_dead = 0;
		info->num_of_eat = -1;
		if (ac == 6)
			info->num_of_eat = ft_atoi(av[5]);
		info->num_ate_phil = 0;
		if (info->num_of_eat == 0 || info->num_philos < 2
			|| info->die_time <= 0 || info->eat_time <= 0
			|| info->sleep_time <= 0 || info->num_of_eat < -1)
		{
			printf("bad input\n");
			return (NULL);
		}
		return (info);
	}
	printf("cant init info for philos\n");
	return (NULL);
}

static void	get_place(t_phil *phil, int place, t_philos *info)
{
	phil->status = 't';
	phil->place = place;
	phil->meta = info;
	phil->ate_time = 0;
	if (phil->place == 0)
		phil->prev = phil->meta->num_philos - 1;
	else
		phil->prev = phil->place - 1;
	phil->next = phil->place;
}

static int	destroer(t_phil *phil, int mutexs, int pthreads, char *message)
{
	int	i;

	i = -1;
	while (++i < pthreads)
		pthread_detach(phil[i].id);
	i = -1;
	while (++i < mutexs)
		pthread_mutex_destroy(&(phil->meta->forks[i]));
	pthread_mutex_destroy(&(phil->meta->print_mutex));
	free(phil->meta->forks);
	free(phil->meta);
	free(phil);
	if (message)
		printf("%s", message);
	return (0);
}

static int	initer(t_philos *philos_info, t_phil *phil)
{
	int	i;
	int	j;

	j = 1;
	if (pthread_mutex_init(&philos_info->print_mutex, NULL))
		j = destroer(phil, 0, 0, "cant init print mutex\n");
	i = -1;
	while (++i < philos_info->num_philos)
	{
		if (pthread_mutex_init(&philos_info->forks[i], NULL))
			j = destroer(phil, i, 0, "cant init mutex\n");
		get_place(&phil[i], i, philos_info);
	}
	i = -1;
	while (++i < philos_info->num_philos)
	{
		if (pthread_create(&phil[i].id, NULL, living, &phil[i]))
			j = destroer(phil, philos_info->num_philos,
					i, "cant init pthread\n");
	}
	return (j);
}

int	main(int ac, char **av)
{
	t_philos	*philos_info;
	t_phil		*phil;

	if (ac < 5 || ac > 6)
	{
		printf("incorrect number of arguments\n");
		return (0);
	}
	philos_info = get_philos_info(ac, av);
	if (!philos_info)
		return (0);
	phil = (t_phil *) malloc (sizeof(t_phil) * philos_info->num_philos);
	if (!phil)
		return (0);
	philos_info->forks = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * philos_info->num_philos);
	if (!philos_info->forks)
		return (0);
	if (!initer(philos_info, phil))
		return (0);
	while (!philos_info->any_dead
		&& !(philos_info->num_ate_phil == philos_info->num_philos))
		usleep(50);
	destroer(phil, philos_info->num_philos, philos_info->num_philos, "");
	return (1);
}
