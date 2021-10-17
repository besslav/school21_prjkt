int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while ((*(s1 + i) || *(s2 + i)) && (i < n))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
		count++;
	}
	return (0);
}
