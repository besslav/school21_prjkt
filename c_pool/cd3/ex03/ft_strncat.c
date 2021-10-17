char	*ft_strncat(char *s1, char *s2, unsigned int nb)
{
	int				i;
	int				j;
	unsigned int	coun;

	i = 0;
	while (*(s1 + i))
		i++;
	j = 0;
	while (coun < nb)
	{
		*(s1 + i) = *(s2 + j);
		i++;
		j++;
		coun++;
	}
	return (s1);
}
