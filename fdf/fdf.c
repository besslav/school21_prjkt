#include "fdf.h"

static void  new_line_creator(char **pre_mass, int *step_mass)
{
	int  j;

	j = -1;
	while (pre_mass[++j])
	{
		step_mass[j] = ft_atoi(pre_mass[j]);
	}
}

static void	map_creator(char *file_with_data, t_meta *data)
{
	int		line;
	char	*str;
	char	**pre_mass;
	int		len;
	int		fd;

	fd = open(file_with_data, O_RDONLY);
	line = 0;
	str = gnl(fd);
	while (str)
	{
		pre_mass = ft_split(str, ' ');
		if (!pre_mass)
			exit (EXIT_FAILURE);
		len = ft_numslen(pre_mass);
		if (data->col && data->col != len)
			exit(1);
		data->col = len;
		data->array[line] = (int *)malloc(len * sizeof(int));
		if (!data->array[line])
			exit(1);
		new_line_creator(pre_mass, data->array[line++]);
		cleaner(pre_mass, len);
		str = gnl(fd);
	}
}

static void	is_map_valid(char *map_name, t_meta *data)
{
	char	*str;
	int		i;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit(1);
	str = gnl(fd);
	while (str)
	{
		data->row++;
		i = -1;
		while (str[++i] && str[i] != '\n')
		{
			if (str[i] != ' ' && str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
				exit (1);
		}
		str = gnl(fd);
	}
	close(fd);
}

static void	set_basic_value(t_meta *data)
{
	data->col = 0;
	data->row = 0;
	data->scale = 20;
	data->shift_x = 0;
	data->shift_y = 0;
	data->angle = 0.523599;
	data->color = 0xfffff;
}

int	main(int ac, char **av)
{
	t_meta	*data;

	if (ac != 2)
		exit(1);
	data = (t_meta *) malloc(sizeof(t_meta));
	if (!data)
		exit(1);
	set_basic_value(data);
	is_map_valid(av[1], data);
	data->array = (int **)malloc(data->row * sizeof(int *));
	if (!data->array)
		exit(1);
	map_creator(av[1], data);





	int	i = 0;
	int j = 0;
	while (i < data->row)
	{
		while (j < data->col)
		{
			printf("%3d ", data->array[i][j++]);
		}
		printf("\n");
		j = 0;
		i++;
		
	}


}