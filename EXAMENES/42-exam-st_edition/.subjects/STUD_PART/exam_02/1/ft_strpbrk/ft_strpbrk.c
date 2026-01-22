#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i = 0;
	int	j;
	
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return(NULL);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%s\n", strpbrk(av[1], av[2]));
		printf("%s\n", ft_strpbrk(av[1], av[2]));
	}
}
