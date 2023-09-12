/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_args.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 17:27:05 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/02/02 14:24:35 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	error_free_and_exit(t_node *top_a, t_node *top_b)
{
	t_node	*temp;

	while (top_a)
	{
		temp = top_a;
		top_a = top_a->next;
		free(temp);
	}
	while (top_b)
	{
		temp = top_b;
		top_b = top_b->next;
		free(temp);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	validate_atoi(char const *arg_string, t_node *top_a)
{
	int	sign;
	int	arg_int;
	int	i;

	sign = 1;
	arg_int = 0;
	i = 0;
	if (!arg_string[i])
		error_free_and_exit(top_a, NULL);
	while ((arg_string[i] == '-' || arg_string[i] == '+') && arg_string[i + 1])
	{
		if (arg_string[i++] == '-')
			sign *= -1;
	}
	while (arg_string[i])
	{
		if (arg_string[i] < '0' || arg_string[i] > '9')
			error_free_and_exit(top_a, NULL);
		if (check_int_max_min(arg_int, arg_string[i], sign) == 0)
			error_free_and_exit(top_a, NULL);
		arg_int *= 10;
		arg_int += arg_string[i] - '0';
		i++;
	}
	return (arg_int * sign);
}

void	check_for_double_integers(t_node *top_a)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = top_a;
	while (temp1->next != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->data == temp2->data)
				error_free_and_exit(top_a, NULL);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	simplify_data(int argc, t_node *top_a)
{
	int		num;
	t_node	*temp;
	t_node	*low_node;

	num = 0;
	while (num < argc - 1)
	{
		temp = top_a;
		while (temp->num != -1 && temp->next)
			temp = temp->next;
		low_node = temp;
		while (temp)
		{
			if (temp->data < low_node->data && temp->num == -1)
				low_node = temp;
			temp = temp->next;
		}
		low_node->num = num;
		num++;
	}
}

t_node	*validate_args(int argc, char const *argv[], t_node *top_a)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (i < argc - 1)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			error_free_and_exit(top_a, NULL);
		new_node->next = NULL;
		new_node->data = validate_atoi(argv[i + 1], top_a);
		new_node->num = -1;
		top_a = insert_at_bottom(top_a, new_node);
		i++;
	}
	check_for_double_integers(top_a);
	simplify_data(argc, top_a);
	return (top_a);
}
