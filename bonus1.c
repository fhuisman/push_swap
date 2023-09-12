/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 13:52:35 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/02/02 15:57:34 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	is_ok(t_node **a_ptr, t_node **b_ptr)
{
	t_node	*temp;

	if (*b_ptr != NULL || *a_ptr == NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	temp = *a_ptr;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
		{
			write(1, "KO\n", 3);
			return ;
		}
		temp = temp->next;
	}
	write(1, "OK\n", 3);
}

void	check(t_node **a_ptr, t_node **b_ptr)
{
	char	move[2];
	int		bytesread;

	bytesread = read(0, move, 1);
	if (bytesread == -1)
		return (error_free_and_exit(*a_ptr, NULL));
	else if (bytesread == 0)
		return (is_ok(a_ptr, b_ptr));
	move[bytesread] = '\0';
	input_1(a_ptr, b_ptr, move);
}

void	checker(int argc, const char *argv[])
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
	check(a_ptr, b_ptr);
	free_stack(top_a);
	free_stack(top_b);
}

int	main(int argc, const char *argv[])
{
	checker(argc, argv);
	return (0);
}
