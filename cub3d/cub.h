/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:28:26 by pskip             #+#    #+#             */
/*   Updated: 2022/07/31 22:06:17 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define STEP		0.30
# define STEP_ALPHA	0.15
# define _USE_MATH_DEFINES
# define NORTH	0
# define SOUTH	1
# define WEST	2
# define EAST	3

typedef struct s_map
{
	char	*points;
	short	*walid_visited;
	int		y_len;
	int		x_len;
	int		start;
	char	dir;
}	t_map;

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

}	t_global;

typedef struct s_ray
{
	int		x_dir;
	int		y_dir;
	float	x_pos;
	float	y_pos;
	float	x_ray_len;
	float	y_ray_len;
}	t_ray;

typedef struct s_doors
{
	int				door_pos;
	int				time_open;
	struct s_doors	*next_door;
	struct s_doors	*prev_door;
}	t_doors;

typedef struct s_game_data
{
	float	alpha_player;
	float	x_player;
	float	y_player;
	char	*map;
	int		x_len;
	int		y_len;
	int		side;
	float	x_img_pos;
	int		x_mouse;
	t_doors	*doors;
}	t_game_data;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img_data;

typedef struct s_textures
{
	int			ceilling_color;
	int			floor_color;
	t_img_data	*wall_textures;
}	t_textures;

typedef struct s_all_data
{
	t_game_data	*game_data;
	t_img_data	*screen_img_data;
	t_textures	*textures;
	void		*mlx;
	void		*win;
}	t_all_data;

typedef struct s_drow
{
	int		y_start;
	int		color;
	float	step;
	int		x_in_img;
	float	y_in_img;
}	t_drow;

char	*add_info(int fd, t_global *global);
t_map	*get_size(int fd, char *line);
void	create_map(char *file_name, t_map *map, int map_first_line);
void	is_map_close(t_map *map);

void	error(char *err);
void	cleaner(char **spl);
int		newcolor(int r, int g, int b);
int		array_pos(int x, int y, int x_len);
void	put_pixel(int x, int y, t_img_data *img_data, int color);
void	check_color_len(char **color);
int		len_file_way(char *str);

void	all_data_group(t_global *global, t_all_data *all_data);
void	pars_colors_line(t_global *data, t_textures *game);
void	drow_back(t_img_data *img_data, t_textures *color);
void	throw_rays(t_all_data *all_data);
float	ray_cycle(t_ray *ray_info, t_game_data *game_data, float alpha);
void	drow_line_of_wall(int h_wall, int x, t_all_data *all_data);
void	drow_image(t_all_data *all_data);

int		lh_events(t_all_data *all_data);
void	mouse_hook(t_all_data *all_data);
int		key_hook(int key, t_all_data *all_data);
int		event_hook(void);
int		doors_closer(t_game_data *game);
void	add_door_textur(
			t_img_data **wall_textures, void *mlx);
int		find_door(t_game_data *game);
float	get_len_of_ray(char x_y, t_ray *ray);

void	drow_minimap(t_all_data *all_data);
void	try_open_door(t_game_data *game);
int		doors_closer(t_game_data *game);

#endif