/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:31:12 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/02 10:02:43 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int					index;
	int					value;
	int					push_price;
	bool				cheapest;
	bool				above_median;
	struct s_stack		*target_node;
	struct s_stack		*prev;
	struct s_stack		*next;
}				t_stack;

void					init(t_stack **a, char **numbers, int argc);
long					ft_atol(const char *str);
void					set_stack(t_stack **a, int number);
void					sort(t_stack **a, t_stack **b);
bool					sorted(t_stack *a);
int						stack_len(t_stack *stack);
void					swap(t_stack **stack);
void					sa(t_stack **a);
void					sb(t_stack **b);
void					ss(t_stack **a, t_stack **b);
void					rotate(t_stack **stack);
void					ra(t_stack **a);
void					rb(t_stack **b);
void					rr(t_stack **a, t_stack **b);
void					reverse_rotate(t_stack **stack);
void					rra(t_stack **a);
void					rrb(t_stack **b);
void					rrr(t_stack **a, t_stack **b);
void					push(t_stack **target_stack, t_stack **src_stack);
void					pa(t_stack **a, t_stack **b);
void					pb(t_stack **a, t_stack **b);
int						biggest(t_stack *a);
void					sort_tre(t_stack **a);
int						is_not_digit(char *str);
int						is_duplicated(t_stack *a, int number);
int						check_error(t_stack **a, char *numbers, long number);
void					free_exit(t_stack **a, char **numbers, int argc);
void					push_swap(t_stack **a, t_stack **b);
void					set_index(t_stack *stack);
void					set_target(t_stack *a, t_stack *b);
t_stack					*get_smallest(t_stack *stack);
void					set_price(t_stack *a, t_stack *b);
void					set_cheapest(t_stack *b);
void					move_it(t_stack **a, t_stack **b);
t_stack					*give_me_cheapest(t_stack *b);
void					keep_rotating(t_stack **stack, t_stack *target, char c);

#endif
