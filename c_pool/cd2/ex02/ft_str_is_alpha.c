int	ft_str_is_alpha(char *str)
{
	char	i;

	i = *str;
	while (i != '\0')
	{
		if ((i <= 64) || ((i >= 91)
				&& (i <= 96)) || (i >= 123))
			return (0);
		i++;
	}
	return (1);
}
