/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils1.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/07 14:18:16 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/01/19 17:11:00 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	free_stack(t_node *top)
{
	t_node	*temp;

	while (top)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}

t_node	*get_bottom_node(t_node *top)
{
	t_node	*temp;

	if (top == NULL)
		return (NULL);
	temp = top;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

t_node	*insert_at_top(t_node *top, t_node *new_node)
{
	if (top == NULL)
		new_node->next = NULL;
	else
		new_node->next = top;
	return (new_node);
}

t_node	*insert_at_bottom(t_node *top, t_node *new_node)
{
	t_node	*temp;

	if (top == NULL)
	{
		top = new_node;
		new_node->next = NULL;
	}
	else
	{
		temp = top;
		top = top->next;
		top = insert_at_bottom(top, new_node);
		temp->next = top;
		top = temp;
	}
	return (top);
}

int	get_stack_size(t_node *top)
{
	int		size;
	t_node	*temp;

	size = 0;
	if (top == NULL)
		return (size);
	temp = top;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
