//#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	num = 0;
	int	i = 0;
	int	sig = 1;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num*sig);
}
/*
int	main(void)
{
	char	*num = "           +27147!";
	int	res = 0;

	res = ft_atoi(num);
	printf("%d", res);
}*/
