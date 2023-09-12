/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 17:09:36 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/02/02 12:41:58 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	get_low(t_node *top)
{
	t_node	*temp;
	int		low;

	temp = top;
	low = top->num;
	while (temp)
	{
		if (temp->num < low)
			low = temp->num;
		temp = temp->next;
	}
	return (low);
}

int	get_high(t_node *top)
{
	t_node	*temp;
	int		high;

	temp = top;
	high = top->num;
	while (temp)
	{
		if (temp->num > high)
			high = temp->num;
		temp = temp->next;
	}
	return (high);
}

int	get_node_position_top(t_node *top, int min, int max)
{
	t_node	*temp;
	int		position;

	temp = top;
	position = 0;
	while (temp)
	{
		if (temp->num >= min && temp->num <= max)
			return (position);
		temp = temp->next;
		position++;
	}
	return (-1);
}

int	get_node_position_bot(t_node *top, int min, int max)
{
	t_node	*temp;
	int		position;
	int		save_pos;

	save_pos = -1;
	position = 0;
	temp = top;
	while (temp)
	{
		if (temp->num >= min && temp->num <= max)
			save_pos = position;
		temp = temp->next;
		position++;
	}
	if (save_pos == 0)
		return (0);
	if (save_pos == -1)
		return (-1);
	return (position - save_pos);
}
