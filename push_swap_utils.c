/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:13:12 by mzoheir           #+#    #+#             */
/*   Updated: 2023/02/24 16:26:09 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list *stack_a, t_list *stack_b)
{
	rra(&stack_a);
	rrb(&stack_b);
}

void	main_bis(t_list **stack_a, t_list **stack_b, t_data *utils)
{
	if (utils->matrix_size <= 100 && utils->matrix_size > 5)
	{
		utils->range = 15;
		first_push_stack_a(stack_a, stack_b, utils);
		push_back_to_a(stack_a, stack_b, utils);
	}
	if (utils->matrix_size > 100)
	{
		utils->range = 35;
		first_push_stack_a(stack_a, stack_b, utils);
		push_back_to_a(stack_a, stack_b, utils);
	}
}

void	return_args(char **av, int ac, t_data *utils)
{
	char	*arg;
	int		max_len;
	int		i;

	max_len = 0;
	i = 0;
	while (++i < ac)
		max_len += ft_strlen(av[i]) + 1;
	arg = malloc(sizeof(char) * max_len + 1);
	i = 0;
	while (++i < ac)
		concatinate(arg, av[i]);
	utils->matrix_size = count_space(arg);
	utils->matrix = ft_split(arg, ' ');
}

int	*sort_all_data(t_data *utils)
{
	int	i;
	int	j;
	int	tmp;
	int	*sorted;

	sorted = utils->all_data;
	i = -1;
	while (++i < utils->matrix_size)
	{
		j = i + 1;
		while (j < utils->matrix_size)
		{
			if (sorted[i] > sorted[j])
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
			j++;
		}
	}
	return (sorted);
}

void	indexing_stack(t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *stack_b;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}
