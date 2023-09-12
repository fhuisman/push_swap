/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 13:53:27 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/02/02 12:45:43 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct node
{
	int			data;
	int			num;
	struct node	*next;	
}	t_node;

void	checker(int argc, const char *argv[]);
t_node	*validate_args(int argc, char const *argv[], t_node *top_a);
void	error_free_and_exit(t_node *top_a, t_node *top_b);
t_node	*insert_at_bottom(t_node *top, t_node *new_node);
void	check(t_node **a_ptr, t_node **b_ptr);
t_node	*swap(t_node *top);
void	push(t_node **from_ptr, t_node **to_ptr);
t_node	*rotate(t_node *top);
t_node	*reverse_rotate(t_node *top);
int		check_int_max_min(int num, char next, int sign);
void	input_1(t_node **a_ptr, t_node **b_ptr, char *move);
void	is_ok(t_node **a_ptr, t_node **b_ptr);
void	free_stack(t_node *top);

#endif