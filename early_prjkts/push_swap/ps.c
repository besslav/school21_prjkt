#include "push_swap.h"

int	*init_mass(int ac,char **av, t_meta *data, int len)
{
	char	**pre_mass;
	int		*step_mass;
	int		i;
	int		j;
	int		*mass;

	i = -1;
	if (!(mass = (int *)malloc(sizeof(int))))
		return (NULL);
	while (av[++i])
	{
		j = 0;
		if (!(pre_mass = ft_split(av[i++], ' ')))
			return (NULL);
		len = ft_strlen(pre_mass);
		if (!(step_mass = (int *)malloc(len * sizeof(int))))
			return (NULL);
		while(pre_mass[j])
			step_mass[j++] = ft_atoi(pre_mass[j++]);
		cleaner(pre_mass, len);
		if (!(mass = ft_strjoin(mass, step_mass, data->len, len)))
			return (NULL);
		data->len += len;
		free(step_mass);
	}
	return (mass);
}

void	push_swap(int ac, char **av)
{
	t_meta	*data;
	int		*mass;
	int		*sort_mass;
	int		st_len;

	st_len = 0;
	if (ac < 2)
		return (0);
	data = (t_meta *)malloc(sizeof(t_meta));
	data->len = 0;
	if (!(mass = init_mass(ac, av, data, st_len)))
		return (0);
	sort_mass = numcpy(mass);
	quick(sort_mass, 0, mass_len(sort_mass));
}

int main(int ac, char **av)
{

	push_swap(ac, av);


}