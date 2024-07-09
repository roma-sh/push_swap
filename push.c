/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 00:41:22 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/02 08:21:46 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **target_stack, t_stack **src_stack)
{
	t_stack	*temp;

	if (*src_stack == NULL)
		return ;
	temp = *src_stack;
	*src_stack = (*src_stack)->next;
	if (*src_stack)
		(*src_stack)->prev = NULL;
	temp->next = *target_stack;
	temp->prev = NULL;
	if (*target_stack)
		(*target_stack)->prev = temp;
	*target_stack = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
