#include <unistd.h>

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	char	num[5];

	a = 0;
	b = 1;
	num[2] = 32;
	while (a < 100)
	{
		while (b < 100)
		{
			num[0] = (a / 10) + 48;
			num[1] = (a % 10) + 48;
			num[3] = (b / 10) + 48;
			num[4] = (b % 10) + 48;
			write(1, num, 5);
			if ((num[0] != '9') || (num[1] != '8')
				|| (num[3] != '9') || (num[4] != '9'))
				write(1, ", ", 2);
			b++;
		}
		a++;
		b = a + 1;
	}
}
