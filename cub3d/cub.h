#ifndef CUB_H
# define CUB_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH		800
# define HEIGHT		600
# define ALPHA_DIF	0.6
# define _USE_MATH_DEFINES

typedef struct s_map
{
	char	*points;
	short	*walid_visited;
	int		y_len;
	int		x_len;
	int		start;
	char	dir;
}   t_map;

typedef struct s_game_data
{
	float	alpha_player;
	float	x_player;
	float	y_player;
	char	*map;
	int		x_len;
	int		y_len;

	int		ceilling_color;
	int		floor_color;
}	t_game_data;

typedef struct s_global
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceilling;
	t_map	*map_data;
	int		line_start;

}   t_global;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;


}	t_mlx_data;


void		error(char *err);
void		cleaner(char **spl);
int			is_map(char *row);
char		*add_info(int fd, t_global *global);
void		create_map(char *file_name, t_map *map, int	map_first_line);
void		drow_image(t_game_data *game_data, t_mlx_data *mlx_data);
t_map		*get_size(int fd, char *line);

int			newcolor(int r, int g, int b);
void		pars_colors_line(t_global *data, t_game_data *game);
void		drow_back(t_mlx_data *mlx_data, t_game_data *color);
void		throw_rays(t_game_data *game, t_mlx_data *mlx_data);
void		drow_line_of_wall(int h_wall, int x, t_mlx_data *mlx_data);

int			array_pos(int	x, int	y, int x_len);
void		put_pixel(int	pixel, t_mlx_data *mlx_data, int color);

#endif