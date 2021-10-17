#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	out[10];
	int		ind;

	if (nb == 0)
		write(1, "0", 1);
	ind = 10;
	if (nb < 0)
	{
		ind--;
		write(1, "-", 1);
		out[ind] = (nb % 10) * (-1) + 48;
		nb = -(nb / 10);
	}
	while (nb != 0)
	{
		ind--;
		out[ind] = (nb % 10) + 48;
		nb = nb / 10;
	}
	while (ind < 10)
	{
		write(1, &out[ind], 1);
		ind++;
	}
}
/*int main(void)
{
	ft_putnbr(-45);
	write(1,"\n", 1);
	ft_putnbr(-2147483648);
	write(1,"\n", 1);
	ft_putnbr(2147483647);
	write(1,"\n", 1);
	ft_putnbr(45);
	write(1,"\n", 1);
	ft_putnbr(0);
}*/
