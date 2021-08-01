int	ft_str_is_lowercase(char *str)
{
	char	i;

	i = *str;
	while (i != '\0')
	{
		if ((i <= 96) || (i >= 123))
			return (0);
		i++;
	}
	return (1);
}
