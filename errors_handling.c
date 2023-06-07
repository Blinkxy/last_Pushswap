/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:23:41 by mzoheir           #+#    #+#             */
/*   Updated: 2023/05/31 19:22:33 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_int(t_data *utils)
{
	int		i;
	long	nb;

	i = -1;
	while (utils->matrix[++i])
	{
		nb = ft_atoi(utils->matrix[i]);
		if (nb < INT_MIN || nb > INT_MAX)
		{
			ft_printf("Error\n");
			free_all(utils);
			exit(0);
		}
		utils->all_data[i] = nb;
	}
}

void	error_dupe(t_data *utils)
{
	int	i;
	int	save_i;

	i = -1;
	while (++i < utils->matrix_size)
	{
		save_i = i + 1;
		while (save_i < utils->matrix_size)
		{
			if (utils->all_data[i] == utils->all_data[save_i])
			{
				ft_printf("Error\n");
				free_all(utils);
				exit(0);
			}
			save_i++;
		}
	}
	if (sorted(utils))
	{
		free_all(utils);
		exit(0);
	}
}

void	error_arg_bis(char **av)
{
	if (valid_arg_bis(av) == 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
}

void	error_arg(t_data *utils)
{
	if (valid_args(utils) == 0)
	{
		ft_printf("Error\n");
		free_all(utils);
		exit(0);
	}
}

void	errors(t_data *utils)
{
	error_arg(utils);
	error_int(utils);
	error_dupe(utils);
}
