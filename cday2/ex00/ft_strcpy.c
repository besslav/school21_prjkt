char	*ft_strcpy(char *dest, char *src)
{
	char	ind;
	int		i;

	ind = *dest;
	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (*(dest + i) != '\0')
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
