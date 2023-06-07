/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_arg_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:04:26 by mzoheir           #+#    #+#             */
/*   Updated: 2023/05/31 17:52:39 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_2(t_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_a(stack_a);
}

void	list_3(t_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		swap_a(stack_a);
		rra(stack_a);
	}
	if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
		rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data)
		rotate_a(stack_a);
	if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	if ((*stack_a)->next->data < (*stack_a)->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
		swap_a(stack_a);
}

void	list_5_bis_2(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->position == 2)
	{
		push_b(stack_a, stack_b);
	}
	else if ((*stack_a)->next->position == 2)
	{
		rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->position == 2)
	{
		rra(stack_a);
		rra(stack_a);
		push_b(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->position == 2)
	{
		rra(stack_a);
		push_b(stack_a, stack_b);
	}
}

void	list_5(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
	{
		list_5_bis(stack_a, stack_b);
		break ;
	}
	while (*stack_a)
	{
		list_5_bis_2(stack_a, stack_b);
		break ;
	}
	list_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	list_all(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->size == 2)
		list_2(stack_a);
	else if ((*stack_a)->size == 3)
		list_3(stack_a);
	else if ((*stack_a)->size == 4)
		list_4(stack_a, stack_b);
	else if ((*stack_a)->size == 5)
		list_5(stack_a, stack_b);
}
