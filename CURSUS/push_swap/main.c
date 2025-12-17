#include "push_swap.h"

int	main(void)
{
	int		i;
	int		values[] = {3, 7, 1, 5, 4, 2, 10, 21, 2354, 8, 2};
	int		size;
	t_node	*a;
	t_node	*b;
	t_node	*tail;
	t_node	*new;

	i = 0;
	size = 11;
	a = NULL;
	b = NULL;
	tail = NULL;
	while (i < size)
	{
		new = node_new(values[i]);
		if (!new)
			return (1);
		stack_add_back(&a, &tail, new);
		i++;
	}
	push_swap(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
