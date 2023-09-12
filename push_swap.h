/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 17:21:21 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/02/02 14:25:54 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	int			num;
	struct node	*next;	
}	t_node;

void	push_swap(int argc, char const *argv[]);
void	sort_three(t_node **a_ptr, t_node **b_ptr, char **output);
void	sort_five(t_node **a_ptr, t_node **b_ptr, int argc, char **output);
void	sort_hundred(t_node **a_ptr, t_node **b_ptr, char **output);
void	sort_over_hundred(t_node **a_ptr, t_node **b_ptr, char **output);
t_node	*validate_args(int argc, char const *argv[], t_node *top_a);
void	error_free_and_exit(t_node *top_a, t_node *top_b);
void	push(t_node **from_ptr, t_node **to_ptr);
t_node	*swap(t_node *top);
t_node	*rotate(t_node *top);
t_node	*reverse_rotate(t_node *top);
t_node	*insert_at_bottom(t_node *top, t_node *new_node);
t_node	*insert_at_top(t_node *top, t_node *new_node);
void	sort(t_node **a_ptr, t_node **b_ptr, int argc);
int		get_low(t_node *top);
int		get_high(t_node *top);
t_node	*get_bottom_node(t_node *top);
void	free_stack(t_node *top);
int		get_stack_size(t_node *top);
int		get_node_position_top(t_node *top, int min, int max);
int		get_node_position_bot(t_node *top, int min, int max);
void	smart_rotate_a(t_node **a_ptr, t_node **b_ptr, int num, char **output);
void	smart_rotate_b(t_node **a_ptr, t_node **b_ptr, int num, char **output);
void	sort_top_a_in_b(t_node **a_ptr, t_node **b_ptr, char **output);
void	sort_top_b_in_a(t_node **a_ptr, t_node **b_ptr, char **output);
int		check_int_max_min(int num, char next, int sign);
void	is_sorted(t_node *top_a);
void	moves(t_node **a_ptr, t_node **b_ptr, const char *move, char **output);

#endif
