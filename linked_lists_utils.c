/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:39:48 by mzoheir           #+#    #+#             */
/*   Updated: 2023/02/24 14:39:57 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_list(t_data *utils)
{
	int		i;
	t_list	*head;
	t_list	*tmp;

	i = 0;
	head = ft_create_node(i, utils->all_data[i], 0);
	tmp = head;
	while (++i < utils->matrix_size)
	{
		tmp->next = ft_create_node(i, utils->all_data[i], 0);
		tmp = tmp->next;
	}
	return (head);
}

void	set_positions(int *array, t_list **list, t_data *utils)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < utils->matrix_size)
	{
		tmp = *list;
		while (tmp != NULL)
		{
			if (array[i] == tmp->data)
				tmp->position = i + 1;
			tmp = tmp->next;
		}
		i++;
	}
}

void	first_push_stack_a(t_list **stack_a, t_list **stack_b, t_data *utils)
{
	int	i;

	i = 1;
	while (*stack_a)
	{
		if ((*stack_a)->position <= i)
		{
			push_b(stack_a, stack_b);
			i++;
			utils->pushes++;
		}
		else if ((*stack_a)->position < i + utils->range)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			i++;
			utils->pushes++;
		}
		else
			rotate_a(stack_a);
	}
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b, t_data *utils)
{
	int	i;

	i = utils->matrix_size;
	while (*stack_b)
	{
		indexing_stack(stack_b);
		while ((*stack_b)->position != i)
		{
			if (biggest(stack_b) <= (i / 2))
				rotate_b(stack_b);
			else if (biggest(stack_b) > (i / 2))
				rrb(stack_b);
		}
		push_a(stack_a, stack_b);
		i--;
	}
}

int	biggest(t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *stack_b;
	indexing_stack(&tmp);
	while (tmp->position != ft_list_size(*stack_b))
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
