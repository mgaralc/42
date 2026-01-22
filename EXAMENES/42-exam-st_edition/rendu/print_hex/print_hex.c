#include <unistd.h>

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

void	print_hex(int num)
{
	char	*dic = "0123456789abcdef";

	if (num >= 16)
		print_hex(num/16);
	write(1, &dic[num%16], 1);
}

int	main(int argc, char **argv)
{
	int	num;

	if (argc != 2)
		return (write(1, "\n", 1));
	num = ft_atoi(argv[1]);
	print_hex(num);
	write(1, "\n", 1);
}
