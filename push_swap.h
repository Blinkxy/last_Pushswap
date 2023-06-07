/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:46:25 by mzoheir           #+#    #+#             */
/*   Updated: 2023/05/31 19:22:13 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BASE_LOW "0123456789abcdef"
# define BASE_UP "0123456789ABCDEF"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_utils
{
	char			**matrix;
	int				matrix_size;
	int				*all_data;
	int				pushes;
	int				range;
}					t_data;

typedef struct t_node
{
	int				index;
	int				data;
	int				position;
	int				size;
	struct t_node	*next;
}					t_list;

void				ft_list_push_front(t_list *begin_list, void *data);
int					ft_list_size(t_list *begin_list);
void				ft_list_push_back(t_list *begin_list, void *data);
t_list				*ft_list_push_strs(int size, char **strs);
void				ft_list_foreach(t_list *begin_list, void (*f)(void *));

void				rrr(t_list *stack_a, t_list *stack_b);
void				rrb(t_list **stack_b);
void				rra(t_list **stack_a);
void				rr(t_list **stack_a, t_list **stack_b);
void				rotate_b(t_list **stack_b);
void				rotate_a(t_list **stack_a);
void				push_b(t_list **stack_a, t_list **stack_b);
void				push_a(t_list **stack_a, t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				swap_b(t_list **stack_b);
void				swap_a(t_list **stack_a);

int					ft_putchar(char c);
int					valid_args(t_data *utils);
int					valid_arg_bis(char **av);
void				return_args(char **av, int ac, t_data *utils);
t_list				*ft_create_list(t_data *utils);
t_list				*ft_create_node(int index, int data, int position);
int					*sort_all_data(t_data *utils);
void				set_positions(int *array, t_list **list, t_data *utils);
void				error_arg_bis(char **av);
void				error_arg(t_data *utils);
void				error_dupe(t_data *utils);
void				error_int(t_data *utils);
void				free_all(t_data *utils);
void				first_push_stack_a(t_list **stack_a, t_list **stack_b,
						t_data *utils);
void				push_back_to_a(t_list **stack_a, t_list **stack_b,
						t_data *utils);
void				indexing_stack(t_list **stack);
void				list_2(t_list **stack_a);
void				list_3(t_list **stack_a);
void				list_4(t_list **stack_a, t_list **stack_b);
void				list_5(t_list **stack_a, t_list **stack_b);
void				list_5_bis(t_list **stack_a, t_list **stack_b);
void				list_5_bis_2(t_list **stack_a, t_list **stack_b);
void				list_all(t_list **stack_a, t_list **stack_b);
int					biggest(t_list **stack_b);
void				main_bis(t_list **stack_a, t_list **stack_b, t_data *utils);
int					count_space(char *str);
int					concatinate(char *str1, char *str2);
int					sorted(t_data *utils);
void				norm_bis(t_data *utils, t_list *tmp);
void				errors(t_data *utils);
#endif