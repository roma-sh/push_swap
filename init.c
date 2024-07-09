/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:02:57 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/02 06:04:43 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack **a, char **numbers, int argc)
{
	int		index;
	long	number;

	index = 0;
	while (numbers[index] != NULL)
	{
		number = ft_atol(numbers[index]);
		if (check_error(a, numbers[index], number) == 1)
		{
			ft_putstr_fd("Error: Duplicated \\ unvalidated arguments.\n", 1);
			free_exit(a, numbers, argc);
			exit(1);
		}
		set_stack(a, (int)number);
		index++;
	}
}

long	ft_atol(const char *str)
{
	int		index;
	int		sign;
	long	result;

	result = 0;
	index = 0;
	sign = 1;
	if (str[index] == '\0')
		return (0);
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		if (str[index + 1] == '-' || str[index + 1] == '+')
			return (0);
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result * sign);
}

void	set_stack(t_stack **a, int number)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		exit(1);
	new->value = number;
	new->push_price = -1;
	new->index = -1;
	new->cheapest = false;
	new->above_median = false;
	new->target_node = NULL;
	new->prev = NULL;
	new->next = NULL;
	if (*a == NULL)
	{
		*a = new;
		new->prev = NULL;
		return ;
	}
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}
