#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int i)
{
	long int	n;
	n = i;
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	if (n > 9)
        {	
		ft_putnbr(n / 10);
        }

	ft_putchar((i % 10) + '0');
}

int	main(void)
{
	int	num = 8343;

	ft_putnbr(num);
}
