#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

t_node	*node_new(int value);
void	stack_add_back(t_node **head, t_node **tail, t_node *new_node);
int		stack_size(t_node *a);
int		is_sorted(t_node *a);
void	print_stack(t_node *a, char name);
void	free_stack(t_node *a);

void	push_swap(t_node **a, t_node **b);

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

void	sort_2(t_node **a);
void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);
void	sort(t_node **a, t_node **b);

#endif
