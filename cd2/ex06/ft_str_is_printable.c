int	ft_str_is_printable(char *str)
{
	char	i;

	i = *str;
	while (i != '\0')
	{
		if ((i <= 31) || (i >= 127))
			return (0);
		i++;
	}
	return (1);
}
