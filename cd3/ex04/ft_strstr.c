char	*ft_strstr(char *str, char *to_find)
{
	char	*p1;
	char	*p2;
	char	*p3;
	int		i;
	int		lenn;

	lenn = 0;
	p1 = str;
	p2 = to_find;
	while (*str)
	{
		if (*p1 == *p2)
		{
			p3 = p1;
			while (*to_find)
			{
				if (*p2 != *p3)
					break ;
				p2++;
				p3++;
				lenn++;
			}
			if (! *to_find)
				return (p1);
			p2 = to_find;
		}
	}
	return (0);
}
