char	*ft_strcat(char *s1, char *s2, unsigned int nb)
{
	int	i;

	i = 0;
	while (*(s1 + i))
		i++;
	*s1 = *(s1 + i);
	i = 0;
	while (*(s2 + i))
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	return (s1);
}
