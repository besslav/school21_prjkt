int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		ans;

	ans = 0;
	i = 0;
	sign = 1;
	while (((str[i] > 8) && (str[i] < 13)) || (str[i] == 32))
		i++;
	while ((*(str + i) == '-') || (*(str + i) == '+'))
	{	
		if (*(str + i) == '-')
			sign = sign * -1;
		i++;
	}
	while ((*(str + i) >= '0') && (*(str + i) <= '9'))
	{
		ans = (ans * 10) + (*(str + i) - 48);
		i++;
	}
	return (ans * sign);
}
/*
int main(void)
{
	char o[] = "  \t+--234t";
	char *p;
	int ans;
	p = o;
	ans = ft_atoi(p);
	printf("%d", ans);

}*/
