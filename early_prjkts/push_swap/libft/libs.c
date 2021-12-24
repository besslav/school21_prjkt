#include "../push_swap.h"

int	*numcpy(int *sors)
//copy from strfr to strto no more then n-1 symbol and add \0 to the end.
{
	int		ind;
	int		len;
	int		*sortit;

	len = mass_len(sors);
	ind = 0;
	sortit = (int *)malloc (sizeof(int) * (len + 1));
	while (sors[ind])
	{
		sortit[ind] = sors[ind];
		ind++;
	}
	return (sortit);
}

int	ft_strlen(char **string)
// len of string
{
	int	lenstring;

	lenstring = 0;
	while (string[lenstring])
		lenstring++;
	return (lenstring);
}

int	mass_len(int *mass)
{
	int	len;

	len = 0;
	while (mass[len])
		len++;
	return (len);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		ans;

	ans = 0;
	i = 0;
	sign = 1;
	if (*(str + i) == '-')
	{
		sign = sign * -1;
		i++;
	}
	while ((*(str + i) >= '0') && (*(str + i) <= '9'))
	{
		ans = (ans * 10) + (*(str + i) - 48);
		i++;
	}
	return (ans * sign);
}

char	*ft_strjoin(int *s1, int *s2, int s1len, int s2len)
{
	char	*news;
	int	ind;

	ind = -1;
	if (!s1 || !s2)
		return (0);

	news = (int *)malloc((s1len + s2len) * sizeof(int));
	if (news == NULL)
		return (NULL);
	while (++ind < s1len)
		news[ind] = s1[ind];
	ind = -1;
	while (++ind < s2len)
		news[s1len + ind] = s2[ind];
	free(s1);
	return (news);
}