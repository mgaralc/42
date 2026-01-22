#include <stdio.h>
#include <string.h>

int     main(int ac, char **av)
{       
        if (ac == 3)
        {       
                printf("%s\n", strpbrk(av[1], av[2]));
                printf("%s\n", ft_strpbrk(av[1], av[2]));
	}
}

