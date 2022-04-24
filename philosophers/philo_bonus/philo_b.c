#include "philo_b.h"

static t_philos_data	*get_philos_info(int ac, char **av)
{
	t_philos_data	*info;

	info = (t_philos_data *)malloc (sizeof(t_philos_data));
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

void create_philo_info(t_phil *phil, t_philos_data *data)
{
	int	i;

	i = data->num_philos;
	while (--i > -1)
	{
		phil->ate_time_at_all = 0;
		phil->meta = data;
		phil->place = i;
	}
}

void	start_of_all(t_phil *phil)
{
	int i;

	i = -1;
	while (++i < phil->meta->num_philos)
	{
		phil->p_id = fork();
		if (phil->p_id == -1)
		{
			printf("problem with pros_init\n");
			//killer(phil, i);
			exit(1);
		}
		if (!phil[i].p_id)
			phil_start(phil);
	}
	
}

int	main(int ac, char **av)
{
	t_philos_data	*philos_info;
	t_phil			*phil;

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
	create_philo_info(&phil, philos_info);
	start_of_all(phil);
}