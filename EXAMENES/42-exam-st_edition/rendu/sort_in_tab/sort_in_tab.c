#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	unsigned int	j;
	int	aux;

	while (i < size)
	{
		j = 0;
		while (j + 1 < size)
		{
			if (tab[j] > tab[j + 1])
			{
				aux = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	i = 0;
	int	tab[] = {12, 42, 5, 23, 6, 5};
	
	sort_int_tab(tab, 6);

	while(i < 6)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}
