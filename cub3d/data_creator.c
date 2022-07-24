/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:44:32 by pskip             #+#    #+#             */
/*   Updated: 2022/07/24 17:42:21 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	game_data_collect(t_global *info, t_game_data *game)
{
	if (info->map_data->dir == 'W')
		game->alpha_player = M_PI;
	else if (info->map_data->dir == 'E')
		game->alpha_player = 0;
	else if (info->map_data->dir == 'N')
		game->alpha_player = M_PI_2;
	else if (info->map_data->dir == 'S')
		game->alpha_player = 3 * M_PI_2;
	game->x_player = (float)(info->map_data->start % info->map_data->x_len) + 0.5;
	game->y_player = (float)(info->map_data->start / info->map_data->x_len) + 0.5;
	game->map = info->map_data->points;
	game->x_len = info->map_data->x_len;
	game->y_len = info->map_data->y_len;
}

void	screen_data_collect(t_img_data *img_data, t_all_data *all_data)
{
	all_data->mlx = mlx_init();
	if (!all_data->mlx)
		error("mlx_init_error\n");
	all_data->win = mlx_new_window(all_data->mlx, WIDTH, HEIGHT, "CUB");
	if (!(all_data->win))
		error("mlx_win_error\n");
	img_data->img = mlx_new_image(all_data->mlx, WIDTH, HEIGHT);
	if (!(img_data->img))
		error("mlx_img_error\n");
	img_data->addr = mlx_get_data_addr
		(img_data->img, &img_data->bits_per_pixel,
			&img_data->line_length, &img_data->endian);
	if (!img_data->addr)
		error("addr_err\n");
}

void	textur_data_collect(t_textures *textures, t_global *global, void *mlx)
{	
	char	*dirs[4];
	int		i;

	dirs[NORTH] = global->north;
	dirs[SOUTH] = global->south;
	dirs[EAST] = global->east;
	dirs[WEST] = global->west;
	textures->wall_textures = (t_img_data*) malloc(4 * sizeof(t_img_data ));
	if (!textures->wall_textures)
		error("textur_init_error\n");
	i = -1;
	while (++i < 4)
		textures->wall_textures[i].img = mlx_xpm_file_to_image(mlx, dirs[i],
			&textures->wall_textures[i].width, &textures->wall_textures[i].height);
	if (!textures->wall_textures[NORTH].img || !textures->wall_textures[SOUTH].img
		|| !textures->wall_textures[EAST].img || !textures->wall_textures[WEST].img)
		error("wall_texturs_init_error\n");
	while (--i >= 0)
		textures->wall_textures[i].addr = mlx_get_data_addr
			(textures->wall_textures[i].img, &textures->wall_textures[i].bits_per_pixel,
				&textures->wall_textures[i].line_length, &textures->wall_textures[i].endian);	
	if (!textures->wall_textures[NORTH].addr || !textures->wall_textures[SOUTH].addr
		|| !textures->wall_textures[EAST].addr || !textures->wall_textures[WEST].addr)
		error("wall_texturs_init_addr_error\n");
}

void	all_data_group(t_global *global, t_all_data *all_data)
{
	t_game_data	*game;
	t_img_data	*img_data;
	t_textures	*texturs;
	int			y;

	game = (t_game_data *) malloc(sizeof(t_game_data));
	if (!game)
		error("game_malloc error\n");
	game_data_collect(global, game);
	img_data = (t_img_data *) malloc(sizeof(t_img_data));
	if (!img_data)
		error("img_malloc error\n");
	screen_data_collect(img_data, all_data);
	texturs = (t_textures *) malloc(sizeof(t_textures));
	if (!texturs)
		error("img_malloc error\n");
	pars_colors_line(global, texturs);
	textur_data_collect(texturs, global, all_data->mlx);
	mlx_mouse_get_pos(all_data->win, &game->x_mouse, &y);
	all_data->game_data = game;
	all_data->screen_img_data = img_data;
	all_data->textures = texturs;
}