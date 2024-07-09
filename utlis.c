/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:12:26 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/02 08:16:10 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int		len;

	len = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*get_smallest(t_stack *stack)
{
	t_stack	*smallest;

	smallest = stack;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*give_me_cheapest(t_stack *b)
{
	if (b == NULL)
		return (NULL);
	while (b)
	{
		if (b->cheapest)
			return (b);
		b = b->next;
	}
	return (NULL);
}
