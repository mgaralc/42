//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while(str[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char	text[] = "cuentame";
	int	num = 0;


	num = ft_strlen(text);
	printf("%d", num);
}*/
