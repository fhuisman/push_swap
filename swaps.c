/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/29 15:16:06 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/01/26 17:54:57 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

t_node	*swap(t_node *top)
{
	t_node	*temp;

	if (top == NULL || top->next == NULL)
		return (top);
	temp = top->next;
	top->next = top->next->next;
	top = insert_at_top(top, temp);
	return (top);
}

void	push(t_node **from_ptr, t_node **to_ptr)
{	
	t_node	*temp;

	if (*from_ptr == NULL)
		return ;
	if (*to_ptr == NULL)
	{
		*to_ptr = *from_ptr;
		*from_ptr = (*from_ptr)->next;
		(*to_ptr)->next = NULL;
	}
	else
	{
		temp = *from_ptr;
		*from_ptr = (*from_ptr)->next;
		temp->next = *to_ptr;
		*to_ptr = temp;
	}
}

t_node	*rotate(t_node *top)
{
	t_node	*temp;

	if (top == NULL || top->next == NULL)
		return (top);
	temp = top;
	top = top->next;
	top = insert_at_bottom(top, temp);
	return (top);
}

t_node	*reverse_rotate(t_node *top)
{
	t_node	*temp;

	if (top == NULL || top->next == NULL)
		return (top);
	temp = get_bottom_node(top);
	temp->next = top;
	top = temp;
	while (temp->next != top)
		temp = temp->next;
	temp->next = NULL;
	return (top);
}
