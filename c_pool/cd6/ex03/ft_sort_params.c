#include <unistd.h>

void	requr( char **str, int first, int left);
void	qsort(char **str, int first, int last);

int	swaper(char **str, int first, int second)
{
	char	*save;

	save = str[first];
	str[first] = str[second];
	str[second] = save;
	return (1);
}

int	shoold(char **str, int first, int second)
{
	int	i;

	i = 0;
	while (str[first][i] || str[second][i])
	{
		if (str[first][i] < str[second][i])
			return (1);
		else if (str[first][i] > str[second][i])
			return (0);
		i++;
	}
	return (1);
}

void	qsort(char **str, int first, int last)
{
	int		base;
	int		left;
	int		right;

	left = first + 1;
	right = last;
	base = first;
	while (left < right)
	{
		if (shoold(str, left, right))
			left++;
		else
			right = right - swaper(str, left, right);
	}
	if (shoold(str, left, base))
	{
		left = left - swaper(str, base, left);
		right++;
	}
	else
		left = left - (2 * swaper(str, base, left - 1));
	requr(str, first, left);
	requr(str, right, last);
}

void	requr(char **str, int first, int left)
{
	if (first < left)
		qsort(str, first, left);
}

int	main(int argc, char **argv)
{
	int	row;
	int	col;

	if (argc > 2)
		qsort (argv, 1, argc - 1);
	col = 1;
	while (col < argc)
	{
		row = 0;
		while (argv[col][row])
		{
			write(1, &argv[col][row], 1);
			row++;
		}	
		write(1, "\n", 1);
		col++;
	}
}
