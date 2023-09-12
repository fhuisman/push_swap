/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 17:54:08 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/01/27 15:55:51 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	moves_s_p(t_node **a_ptr, t_node **b_ptr, const char *move)
{
	if (move[0] == 's')
	{
		if (move[1] == 'a' || move[1] == 's')
			*a_ptr = swap(*a_ptr);
		if (move[1] == 'b' || move[1] == 's')
			*b_ptr = swap(*b_ptr);
	}
	else if (move[0] == 'p')
	{
		if (move[1] == 'a')
			push(b_ptr, a_ptr);
		if (move[1] == 'b')
			push(a_ptr, b_ptr);
	}
}

void	moves_r(t_node **a_ptr, t_node **b_ptr, const char *move)
{
	if (move[1] == 'a')
		*a_ptr = rotate(*a_ptr);
	else if (move[1] == 'b')
		*b_ptr = rotate(*b_ptr);
	else if (move[1] == 'r')
	{
		if (move[2] == '\n')
		{
			*a_ptr = rotate(*a_ptr);
			*b_ptr = rotate(*b_ptr);
		}
		if (move[2] == 'a' || move[2] == 'r')
			*a_ptr = reverse_rotate(*a_ptr);
		if (move[2] == 'b' || move[2] == 'r')
			*b_ptr = reverse_rotate(*b_ptr);
	}
}

void	moves(t_node **a_ptr, t_node **b_ptr, const char *move, char **result)
{
	if (move == NULL)
		return ;
	*result = ft_strjoin(*result, move);
	if (!result)
		error_free_and_exit(*a_ptr, *b_ptr);
	if (move[0] == 's' || move[0] == 'p')
		moves_s_p(a_ptr, b_ptr, move);
	else if (move[0] == 'r')
		moves_r(a_ptr, b_ptr, move);
}

void	smart_rotate_a(t_node **a_ptr, t_node **b_ptr, int num, char **result)
{
	int		stack_size;
	int		position;

	stack_size = get_stack_size(*a_ptr);
	position = get_node_position_top(*a_ptr, num, num) + 1;
	if (position <= stack_size - (stack_size / 2))
	{
		while ((*a_ptr)->num != num)
			moves(a_ptr, b_ptr, "ra\n", result);
	}
	else
	{
		while ((*a_ptr)->num != num)
			moves(a_ptr, b_ptr, "rra\n", result);
	}
}

void	smart_rotate_b(t_node **a_ptr, t_node **b_ptr, int num, char **result)
{
	int		stack_size;
	int		position;

	stack_size = get_stack_size(*b_ptr);
	position = get_node_position_top(*b_ptr, num, num) + 1;
	if (position <= stack_size - (stack_size / 2))
	{
		while ((*b_ptr)->num != num)
			moves(a_ptr, b_ptr, "ra\n", result);
	}
	else
	{
		while ((*b_ptr)->num != num)
			moves(a_ptr, b_ptr, "rra\n", result);
	}
}
