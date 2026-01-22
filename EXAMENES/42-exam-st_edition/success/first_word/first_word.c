#include <unistd.h>

void	first_word(char *str)
{
	int	i = 0;
	
	while(str[i] && (str[i] == ' ' || (str[i] > 9 && str[i] < 13)))
		i++;

	while(str[i] && !(str[i] == ' ' || (str[i] > 9 && str[i] < 13)))
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	first_word(argv[1]);
	
}
