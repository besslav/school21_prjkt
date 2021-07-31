int	ft_str_is_numeric(char *str)
{
	char	i;

	i = *str;
	while (i != '\0')
	{
		if ((i <= 47) || (i >= 58))
			return (0);
		i++;
	}
	return (1);
}
