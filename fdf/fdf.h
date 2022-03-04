/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:46:16 by pskip             #+#    #+#             */
/*   Updated: 2022/03/04 20:42:02 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define BUFFER_SIZE 15
# define HEIGHT			1000
# define WIDTH			1000

typedef struct s_element
{
	float	x;
	float	y;
	float	z;
}	t_element;

typedef struct s_meta
{
	t_element	**array;
	int			col;
	int			row;
	int			max;
	int			min;

	double		angle;
	int			color;
	float		scale;
	float		z_scale;
	int			shift_x;
	int			shift_y;

	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_meta;

// main func
void	drow_line(t_meta *data, t_element o1, t_element o2);
void	drow_map(t_meta *data);
int		event_hook(void);
int		deal_key(int key, t_meta *data);
void	errors(char *error, int err_len);
void	choice_of_color(t_meta *data, float z);

// additional func
char	*gnl(int fd);
void	cleaner(char **cleanit, int ind);
int		ft_numslen(char **string);
int		ft_strlen(const char *string);
int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *str, int findit);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr_gnl(char const *s, int start, int len);

#endif