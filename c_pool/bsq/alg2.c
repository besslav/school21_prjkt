#include "infa_map.h"
#include <stdlib.h>
#include <unistd.h>

void	algo(t_inf *data)
{
	int	row;
	int	col;
	int	new;

	row = 1;
	while (row < data->count_str)
	{
		col = 1;
		while (col < data->len_str)
		{
			if (data->map_bi[row][col] != 0)
			{
				new = data->map_bi[row][col - 1];
				if (data->map_bi[row - 1][col - 1] < new)
					new = data->map_bi[row - 1][col - 1];
				if (data->map_bi[row - 1][col] < new)
					new = data->map_bi[row - 1][col];
				data->map_bi[row][col] = new + 1;
			}
			col++;
		}
		row++;
	}
}

int	*max_finder(t_inf *data)
{
	int	*max;
	int	col;
	int	row;

	max = (int *) malloc(sizeof(int) * 3);
	max[0] = 0;
	row = 1;
	while (row < data->count_str)
	{
		col = 1;
		while (col < data->len_str)
		{
			if (data->map_bi[row][col] > max[0])
			{
				max[0] = data->map_bi[row][col];
				max[1] = row;
				max[2] = col;
			}
			col++;
		}
		row++;
	}
	return (max);
}

void	change_orig(t_inf *data, int *max)
{
	int	colup;
	int	rowup;

	rowup = 0;
	colup = 0;
	while (rowup < max[0])
	{
		colup = 0;
		while (colup < max[0])
		{
			data->map[max[1] - rowup][max[2] - colup] = data->full;
			colup++;
		}
		rowup++;
	}
}

void	write_orig(t_inf *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->count_str)
	{
		col = 0;
		while (col < data->len_str)
		{
			write(1, data->map[row] + col, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	main_alg(t_inf *data)
{
	int	*max_plase;

	algo(data);
	max_plase = max_finder(data);
	change_orig(data, max_plase);
	write_orig(data);
	free(max_plase);
}
