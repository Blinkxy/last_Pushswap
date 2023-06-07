/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:46:06 by mzoheir           #+#    #+#             */
/*   Updated: 2023/02/23 12:36:45 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*swap;
	t_list	*tmp;

	if (ft_list_size(*stack_a) > 1)
	{
		swap = (*stack_a)->next;
		tmp = *stack_a;
		(*stack_a)->next = swap->next;
		swap->next = tmp;
		*stack_a = swap;
		ft_printf("sa\n");
	}
}

void	swap_b(t_list **stack_b)
{
	t_list	*swap;
	t_list	*tmp;

	if (ft_list_size(*stack_b) > 1)
	{
		swap = (*stack_b)->next;
		tmp = *stack_b;
		(*stack_b)->next = swap->next;
		swap->next = tmp;
		*stack_b = swap;
		ft_printf("sb\n");
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*push;

	if (*stack_b)
	{
		push = *stack_b;
		*stack_b = (*stack_b)->next;
		push->next = *stack_a;
		*stack_a = push;
		ft_printf("pa\n");
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*push;

	if (*stack_a)
	{
		push = *stack_a;
		*stack_a = (*stack_a)->next;
		push->next = *stack_b;
		*stack_b = push;
		ft_printf("pb\n");
	}
}
