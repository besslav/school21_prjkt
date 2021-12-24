#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				*content;
	int				*real_ind;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_meta
{
	struct s_stack	a;
	struct s_stack	b;
	int				len;
}	t_meta;

t_stack	*ft_lstnew(int *content);
t_meta	*init_stack(int ac, char **av);
void	quick(int *mass, int start, int end);
int	ft_strlen(char **string);
int	mass_len(int *mass);
char	**ft_split(char const *s, char c);
int	ft_atoi(char *str);
void	cleaner(char **cleanit, int ind);
int	*numcpy(int *sors);

# endif