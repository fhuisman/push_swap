/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:28:28 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/02/02 14:01:29 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	is_sorted(t_node *top_a)
{
	t_node	*temp;

	temp = top_a;
	if (top_a == NULL)
		return ;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return ;
		temp = temp->next;
	}
	exit(EXIT_SUCCESS);
}

void	push_swap(int argc, char const *argv[])
{
	t_node	*top_b;
	t_node	**a_ptr;
	t_node	**b_ptr;
	t_node	*top_a;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	top_a = NULL;
	top_b = NULL;
	a_ptr = &top_a;
	b_ptr = &top_b;
	top_a = validate_args(argc, argv, top_a);
	is_sorted(*a_ptr);
	sort(a_ptr, b_ptr, argc);
	free_stack(top_a);
	free_stack(top_b);
}

int	main(int argc, char const *argv[])
{
	push_swap(argc, argv);
	return (0);
}
