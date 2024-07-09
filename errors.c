/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 04:36:47 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/02 05:28:36 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0' || !ft_isdigit((unsigned char)str[i]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicated(t_stack *a, int number)
{
	while (a)
	{
		if (a->value == number)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_error(t_stack **a, char *numbers, long number)
{
	if (number > INT_MAX || number < INT_MIN)
		return (1);
	if (is_duplicated(*a, number))
		return (1);
	if (is_not_digit(numbers))
		return (1);
	return (0);
}

void	free_exit(t_stack **a, char **numbers, int argc)
{
	int		i;
	t_stack	*temp;
	t_stack	*temp2;

	i = 0;
	if (argc == 2)
	{
		while (numbers[i] != NULL)
		{
			free(numbers[i]);
			i++;
		}
		free(numbers);
		numbers = NULL;
	}
	if (a == NULL || *a == NULL)
		return ;
	temp = *a;
	while (temp)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*a = NULL;
}
