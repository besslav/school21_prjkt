int	ft_str_is_uppercase(char *str)
{
	char	i;

	i = *str;
	while (i != '\0')
	{
		if ((i <= 64) || (i >= 91))
			return (0);
	}
	return (1);
}
