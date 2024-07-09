/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:31:02 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/04 09:38:48 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		size;

	size = stack_len(*a);
	while (size-- > 3)
		pb(a, b);
	sort_tre(a);
	while (*b)
	{
		set_index(*a);
		set_index(*b);
		set_target(*a, *b);
		set_price(*a, *b);
		set_cheapest(*b);
		move_it(a, b);
	}
	set_index(*a);
	smallest = get_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}

void	move_it(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = give_me_cheapest(*b);
	if (temp->above_median && temp->target_node->above_median)
	{
		while (*a != temp->target_node && *b != temp)
			rr(a, b);
		set_index(*a);
		set_index(*b);
	}
	else if (!(temp->above_median) && !(temp->target_node->above_median))
	{
		while (*a != temp->target_node && *b != temp)
			rrr(a, b);
		set_index(*a);
		set_index(*b);
	}
	keep_rotating(b, temp, 'b');
	keep_rotating(a, temp->target_node, 'a');
	pa(a, b);
}

void	keep_rotating(t_stack **stack, t_stack *target, char c)
{
	while (target && *stack != target)
	{
		if (c == 'a')
		{
			if (target && target->above_median)
				ra(stack);
			else if (target && !target->above_median)
				rra(stack);
		}
		else if (c == 'b')
		{
			if (target && target->above_median)
				rb(stack);
			else if (target && !target->above_median)
				rrb(stack);
		}
	}
}
