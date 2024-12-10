/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_topush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:39:59 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/04 09:39:15 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

void	set_target(t_stack *a, t_stack *b)
{
	int		target_value;
	t_stack	*temp;

	temp = NULL;
	while (b)
	{
		temp = a;
		target_value = INT_MAX;
		while (temp)
		{
			if (temp->value > b->value && temp->value < target_value)
			{
				b->target_node = temp;
				target_value = temp->value;
			}
			temp = temp->next;
		}
		if (target_value == INT_MAX)
			b->target_node = get_smallest(a);
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;
	int	price;

	a_len = stack_len(a);
	b_len = stack_len(b);
	price = 0;
	while (b != NULL)
	{
		if (b->above_median == true)
			price = b->index;
		else
			price = b_len - (b->index);
		if (b && b->target_node && b->target_node->above_median == true)
			price += b->target_node->index;
		else
			price += a_len - (b->target_node->index);
		b->push_price = price;
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	if (b == NULL)
		return ;
	while (b)
	{
		if (b->push_price < cheapest->push_price)
			cheapest = b;
		b = b->next;
	}
	cheapest->cheapest = true;
}
