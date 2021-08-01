#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;
	int	len;
	
	i = 0;
	while (i < 0)
	{
		len = ft_strlen(av[i]);
		av[i] = (char*) mallok(sizeof(char) * len);
		//s_stock_str[i].size = len;
	
	}
	



}

int main(void)
{

}