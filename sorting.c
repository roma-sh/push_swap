/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 03:45:21 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/02 08:57:24 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (!sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_tre(a);
		else
			push_swap(a, b);
	}
}

bool	sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

int	biggest(t_stack *a)
{
	int	biggest;

	biggest = INT_MIN;
	while (a != NULL)
	{
		if (a->value > biggest)
			biggest = a->value;
		a = a->next;
	}
	return (biggest);
}

void	sort_tre(t_stack **a)
{
	int	biggest_value;

	biggest_value = biggest(*a);
	if ((*a)->value == biggest_value)
		ra(a);
	else if ((*a)->next->value == biggest_value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
