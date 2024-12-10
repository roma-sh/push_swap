/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:01:42 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/02 09:17:24 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**numbers;

	a = NULL;
	b = NULL;
	numbers = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_putstr_fd("Error: Not enough argumnts.\n", 1);
		return (1);
	}
	else if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		init(&a, numbers, argc);
	}
	else
		init(&a, argv + 1, argc);
	sort(&a, &b);
	if (numbers != NULL)
		free_exit(NULL, numbers, 2);
	free_exit(&a, NULL, 0);
	free_exit(&b, NULL, 0);
	return (0);
}
