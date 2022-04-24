#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct s_data
{
	int		col;
	int		row;
	char	bg;
	char	**array;
}	t_data;

typedef struct s_fig
{
	float	x;
	float	y;
	float	r;
	char	symbol;
	char	type_f;
}			t_fig;



int	get_data(t_data *data, FILE *file)
{
	int	count;
	int	i;

    if ((count = fscanf(file, "%d %d %c\n", &data->col, &data->row, &data->bg)) != 3)
        return (0);
	if (data->col <= 0 || data->col > 300 || data->row <= 0 || data->row > 300)
		return (0);
	data->array = (char **)malloc (sizeof(char *) * data->row);
	if (!data->array)
		return (0);
	i = -1;
	while (++i < data->row)
	{
		data->array[i] = (char *)malloc (sizeof(char ) * data->col);
		if (!data->array[i])
		{
			cleaner(data);
			return (0);
		}
	}
	i = -1;
	while (++i < data->col * data->row)
		data->array[i] = data->bg;
	return (1);
}

int	main(int ac, char **av)
{
	FILE 	*file;
	t_data	*data;
	int		count;
	t_fig	figura;
	float	dist;
	int		point_x;
	int		point_y;

	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (0);
	}
	if (!(file = fopen(av[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 25);
		return (0);
	}
	if (!get_data(&data, file))
		return (0);

	while (count = fscanf(file, "%c %f %f %f %c\n", &figura.type_f, &figura.x, &figura.y, &figura.r, &figura.symbol) == 5)
	{
		point_y = 0;
		while (point_y <= data->row)
		{
			point_x = 0;
			while (point_x <= data->col)
			{
				if ((figura.type_f == 'c' && (sqrtf((point_x - figura.x) * (point_x - figura.x) + (point_y - figura.y) * (point_y - figura.y)) <= figura.r)))
					data->array[point_y][point_x]  = figura.symbol;
			}
		}
	}



}