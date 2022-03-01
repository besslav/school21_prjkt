#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
#include <stdio.h>
# define BUFFER_SIZE 15

typedef struct 
{
	int		**array;
	int		col;
	int		row;
	
	double	angle;
	int		color;
	int		scale;
	int		shift_x;
	int		shift_y;

	void		*mlx_ptr;
	void		*win_ptr;
}	t_meta;

// main func


// additional func
char	*gnl(int fd);
void	cleaner(char **cleanit, int ind);
int		ft_numslen(char **string);
int		ft_strlen(const char *string);
int		ft_atoi(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *str, int findit);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr_gnl(char const *s, int start, int len);

#endif