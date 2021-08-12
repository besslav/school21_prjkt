#include <stdlib.h>
#include <unistd.h>

int	insep(char check, char *seps)
{
	int	i;

	i = 0;
	while (seps[i])
	{
		if (check == seps[i])
			return (1);
		i++;
	}
	return (0);
}

int nwords (char *str, char *seps)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if ((!insep(str[i], seps)) && (insep(str[i-1], seps)))
			i++;
	}
	return (i);
}

char **ft_split(char *str, char *seps)
{
	int		i;
	int		nw;
	int		j;
	char	**ans;

	i = 1;
	j = 0;
	nw = nwords(str, seps);
	ans = (char **)malloc(sizeof(*char) * (nw+2));
	if ((!insep(str[0], seps))
	{
		ans[0] = str[0];
		j = 1;
	}
	while (str[i])
	{
		if ((!insep(str[i], seps)) && (insep(str[i-1], seps)))
			ans[j] = str[i+1]
			i++;
	}
	return (ans);
}


int main(void)
{
	char str[] = "dfgh fghjk ghjk hjkigjgb fgh";
	char seps[] = " ";
	char **ans;
	ans = ft_split(str, seps);
	return (**ans);
}