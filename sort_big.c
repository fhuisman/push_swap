/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 14:30:52 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/02/01 16:47:52 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	sort_chunk(t_node **a_ptr, t_node **b_ptr, int *range, char **output)
{
	int	top_pos;
	int	bot_pos;

	top_pos = get_node_position_top(*a_ptr, range[0], range[1]);
	bot_pos = get_node_position_bot(*a_ptr, range[0], range[1]);
	while (top_pos != -1)
	{
		if (top_pos <= bot_pos)
		{
			while (top_pos-- != 0)
				moves(a_ptr, b_ptr, "ra\n", output);
		}
		else
		{
			while (bot_pos-- != 0)
				moves(a_ptr, b_ptr, "rra\n", output);
		}
		moves(a_ptr, b_ptr, "pb\n", output);
		top_pos = get_node_position_top(*a_ptr, range[0], range[1]);
		bot_pos = get_node_position_bot(*a_ptr, range[0], range[1]);
	}
}

void	make_chunks(t_node **a_ptr, t_node **b_ptr, int chunks, char **output)
{
	int	chunk;
	int	range[2];
	int	i;

	range[1] = get_high(*a_ptr);
	range[0] = 0;
	chunk = range[1] / chunks;
	i = chunks - 1;
	while (i != 0)
	{
		range[1] = range[0] + chunk;
		sort_chunk(a_ptr, b_ptr, range, output);
		range[0] += chunk;
		i--;
	}
	range[1] = get_high(*a_ptr);
	sort_chunk(a_ptr, b_ptr, range, output);
}

void	sort_hundred(t_node **a_ptr, t_node **b_ptr, char **output)
{
	make_chunks(a_ptr, b_ptr, 5, output);
	moves(a_ptr, b_ptr, "pa\n", output);
	while (*b_ptr)
	{
		if ((*b_ptr)->num < get_low(*a_ptr))
		{
			smart_rotate_a(a_ptr, b_ptr, get_low(*a_ptr), output);
			moves(a_ptr, b_ptr, "pa\n", output);
		}
		else if ((*b_ptr)->num > get_high(*a_ptr))
		{
			smart_rotate_a(a_ptr, b_ptr, get_low(*a_ptr), output);
			moves(a_ptr, b_ptr, "pa\n", output);
			moves(a_ptr, b_ptr, "ra\n", output);
		}
		else
			sort_top_b_in_a(a_ptr, b_ptr, output);
	}
	smart_rotate_a(a_ptr, b_ptr, get_low(*a_ptr), output);
}

void	sort_over_hundred(t_node **a_ptr, t_node **b_ptr, char **output)
{
	make_chunks(a_ptr, b_ptr, 11, output);
	moves(a_ptr, b_ptr, "pa\n", output);
	while (*b_ptr)
	{
		if ((*b_ptr)->num < get_low(*a_ptr))
		{
			smart_rotate_a(a_ptr, b_ptr, get_low(*a_ptr), output);
			moves(a_ptr, b_ptr, "pa\n", output);
		}
		else if ((*b_ptr)->num > get_high(*a_ptr))
		{
			smart_rotate_a(a_ptr, b_ptr, get_low(*a_ptr), output);
			moves(a_ptr, b_ptr, "pa\n", output);
			moves(a_ptr, b_ptr, "ra\n", output);
		}
		else
			sort_top_b_in_a(a_ptr, b_ptr, output);
	}
	smart_rotate_a(a_ptr, b_ptr, get_low(*a_ptr), output);
}
