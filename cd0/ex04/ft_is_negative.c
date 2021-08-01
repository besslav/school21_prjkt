#include <unistd.h>

void	ft_is_negative(int num)
{
	char	ans;

	if (num < 0)
	{
		ans = 78;
		write(1, &ans, 1);
	}
	else
	{
		ans = 80;
		write(1, &ans, 1);
	}
}
