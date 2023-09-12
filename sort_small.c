/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 15:32:35 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/02/02 14:01:19 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	sort_top_b_in_a(t_node **a_ptr, t_node **b_ptr, char **output)
{
	t_node	*temp;

	temp = *a_ptr;
	while (temp->num > (*b_ptr)->num)
	{
		if (temp->next == NULL)
			temp = *a_ptr;
		else
			temp = temp->next;
	}
	while (temp->num < (*b_ptr)->num)
	{
		if (temp->next == NULL)
			temp = *a_ptr;
		else
			temp = temp->next;
	}
	smart_rotate_a(a_ptr, b_ptr, temp->num, output);
	moves(a_ptr, b_ptr, "pa\n", output);
}

void	sort_top_a_in_b(t_node **a_ptr, t_node **b_ptr, char **output)
{
	t_node	*temp;

	temp = *b_ptr;
	while (temp->num < (*a_ptr)->num)
	{
		if (temp->next == NULL)
			temp = *b_ptr;
		else
			temp = temp->next;
	}
	while (temp->num > (*a_ptr)->num)
	{
		if (temp->next == NULL)
			temp = *b_ptr;
		else
			temp = temp->next;
	}
	smart_rotate_b(a_ptr, b_ptr, temp->num, output);
	moves(a_ptr, b_ptr, "pb\n", output);
}

void	sort_three(t_node **a_ptr, t_node **b_ptr, char **output)
{	
	if ((*a_ptr)->num > (*a_ptr)->next->num)
	{
		if ((*a_ptr)->next->num > (*a_ptr)->next->next->num)
		{
			moves(a_ptr, b_ptr, "sa\n", output);
			moves(a_ptr, b_ptr, "rra\n", output);
		}
		else if ((*a_ptr)->num > (*a_ptr)->next->next->num)
			moves(a_ptr, b_ptr, "ra\n", output);
		else
			moves(a_ptr, b_ptr, "sa\n", output);
	}
	else
	{
		if ((*a_ptr)->next->num < (*a_ptr)->next->next->num)
			return ;
		else if ((*a_ptr)->num < (*a_ptr)->next->next->num)
		{
			moves(a_ptr, b_ptr, "sa\n", output);
			moves(a_ptr, b_ptr, "ra\n", output);
		}
		else
			moves(a_ptr, b_ptr, "rra\n", output);
	}
}

void	sort_five(t_node **a_ptr, t_node **b_ptr, int argc, char **output)
{
	while (argc > 4)
	{
		moves(a_ptr, b_ptr, "pb\n", output);
		argc--;
	}
	sort_three(a_ptr, b_ptr, output);
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

void	sort(t_node **a_ptr, t_node **b_ptr, int argc)
{
	char	**output;
	char	*result;

	result = ft_strdup("");
	if (!result)
		error_free_and_exit(*a_ptr, *b_ptr);
	output = &result;
	if (argc == 3)
	{
		if ((*a_ptr)->num > (*a_ptr)->next->num)
			moves(a_ptr, b_ptr, "sa\n", output);
	}
	else if (argc <= 4)
		sort_three(a_ptr, b_ptr, output);
	else if (argc <= 6)
		sort_five(a_ptr, b_ptr, argc, output);
	else if (argc <= 101)
		sort_hundred(a_ptr, b_ptr, output);
	else
		sort_over_hundred(a_ptr, b_ptr, output);
	ft_printf("%s", *output);
	free(result);
}
