/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_arg_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:47:08 by mzoheir           #+#    #+#             */
/*   Updated: 2023/05/31 19:20:07 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_4(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
	{
		if ((*stack_a)->position == 1)
			push_b(stack_a, stack_b);
		else if ((*stack_a)->next->position == 1)
		{
			rotate_a(stack_a);
			push_b(stack_a, stack_b);
		}
		else if ((*stack_a)->next->next->position == 1)
		{
			rra(stack_a);
			rra(stack_a);
			push_b(stack_a, stack_b);
		}
		else if ((*stack_a)->next->next->next->position == 1)
		{
			rra(stack_a);
			push_b(stack_a, stack_b);
		}
		break ;
	}
	list_3(stack_a);
	push_a(stack_a, stack_b);
}

void	list_5_bis(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->position == 1)
		push_b(stack_a, stack_b);
	else if ((*stack_a)->next->position == 1)
	{
		rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->position == 1)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->position == 1)
	{
		rra(stack_a);
		rra(stack_a);
		push_b(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->next->position == 1)
	{
		rra(stack_a);
		push_b(stack_a, stack_b);
	}
}

void	free_all(t_data *utils)
{
	int	i;

	i = -1;
	while (utils->matrix[++i])
		free(utils->matrix[i]);
	free(utils->matrix);
	if (utils->all_data)
		free(utils->all_data);
	free(utils);
	exit(0);
}

int	sorted(t_data *utils)
{
	int	i;
	int	j;

	i = 0;
	while (i < utils->matrix_size)
	{
		j = i + 1;
		while (j < utils->matrix_size)
		{
			if (utils->all_data[i] > utils->all_data[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	norm_bis(t_data *utils, t_list *tmp)
{
	while (tmp)
	{
		tmp->size = utils->matrix_size;
		tmp = tmp->next;
	}
}
