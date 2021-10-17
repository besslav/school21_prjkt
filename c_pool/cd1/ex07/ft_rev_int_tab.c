#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		save;

	while (size > 1)
	{
		save = *tab;
		*tab = *(tab + size - 1);
		*(tab + size - 1) = save;
		size = size - 2;
		tab++;
	}
}
