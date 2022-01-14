#include "push_swap.h"

void	printer(int *mass, int len)
{
	int	i = 0;
	while (i < len)
		printf("(%d) ", mass[i++]);
	printf("\n");
}

void	list_printer(t_stack *a)
{
	t_stack *start;

	start = a;
	printf("start:(%d ", a->real_ind);
	a = a->next;
	while (a != start)
	{
		printf("(%d ,", a->real_ind);
		a = a->next;
	}
	printf("\n");
}