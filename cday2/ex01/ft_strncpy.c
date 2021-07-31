char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	i;

	i = 0;
	while (*(src + i) && (i < n))
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
