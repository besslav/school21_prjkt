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

int lenn (int beg, char *str, char *seps)
{
	int	i;

	i = 0;
	while (!insep(str[beg], seps))
	{
		i++;
		beg++;
	}
	return (i);
}

char **ft_split(char *str, char *seps)
{
	int		i;
	int 	len;
	char	**ans;
	int		nword;
	int		j;

	nword = 0;
	i = 0;
	len = 0;
	while (str[i])
	{
		if (!insep(str[i], seps))
		{
			j = 0;
			len = lenn(i, str, seps);
			ans[nword] = (char *)malloc(sizeof(char) * len);
			while (j < len)
			{
				ans[nword][j] = str[i];
				write(1, &str[i], 1);
				j++;
				i++;
			}
			nword++;
			write(1,"\n", 1);
		}
		else
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
	return (0);
}