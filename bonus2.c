/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 15:39:30 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/02/01 16:10:02 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <stdio.h>

void	input_3_r(t_node **a_ptr, t_node **b_ptr, char *move)
{
	int		bytesread;

	bytesread = read(0, move, 1);
	if (bytesread == -1 || bytesread == 0)
		return (error_free_and_exit(*a_ptr, NULL));
	if (move[0] == '\n')
	{
		*a_ptr = rotate(*a_ptr);
		*b_ptr = rotate(*b_ptr);
	}
	else
	{
		if (move[0] == 'a' || move[0] == 'r')
			*a_ptr = reverse_rotate(*a_ptr);
		if (move[0] == 'b' || move[0] == 'r')
			*b_ptr = reverse_rotate(*b_ptr);
		else if (move[0] != 'a')
			return (error_free_and_exit(*a_ptr, NULL));
		bytesread = read(0, move, 1);
		if (bytesread == -1 || bytesread == 0)
			return (error_free_and_exit(*a_ptr, NULL));
		if (move[0] != '\n')
			return (error_free_and_exit(*a_ptr, NULL));
	}
	check(a_ptr, b_ptr);
}

void	input_2_s(t_node **a_ptr, t_node **b_ptr, char *move)
{
	int		bytesread;

	bytesread = read(0, move, 1);
	if (bytesread == -1 || bytesread == 0)
		return (error_free_and_exit(*a_ptr, NULL));
	move[bytesread] = '\0';
	if (move[0] == 'a' || move[0] == 's')
		*a_ptr = swap(*a_ptr);
	if (move[0] == 'b' || move[0] == 's')
		*b_ptr = swap(*b_ptr);
	else if (move[0] != 'a')
		return (error_free_and_exit(*a_ptr, NULL));
	bytesread = read(0, move, 1);
	if (bytesread == -1 || bytesread == 0)
		return (error_free_and_exit(*a_ptr, NULL));
	if (move[0] != '\n')
		return (error_free_and_exit(*a_ptr, NULL));
	check(a_ptr, b_ptr);
}

void	input_2_p(t_node **a_ptr, t_node **b_ptr, char *move)
{
	int		bytesread;

	bytesread = read(0, move, 1);
	if (bytesread == -1 || bytesread == 0)
		return (error_free_and_exit(*a_ptr, NULL));
	move[bytesread] = '\0';
	if (move[0] == 'a')
		push(b_ptr, a_ptr);
	else if (move[0] == 'b')
		push(a_ptr, b_ptr);
	else
		return (error_free_and_exit(*a_ptr, NULL));
	bytesread = read(0, move, 1);
	if (bytesread == -1 || bytesread == 0)
		return (error_free_and_exit(*a_ptr, NULL));
	if (move[0] != '\n')
		return (error_free_and_exit(*a_ptr, NULL));
	check(a_ptr, b_ptr);
}

void	input_2_r(t_node **a_ptr, t_node **b_ptr, char *move)
{
	int		bytesread;

	bytesread = read(0, move, 1);
	if (bytesread == -1 || bytesread == 0)
		return (error_free_and_exit(*a_ptr, NULL));
	move[bytesread] = '\0';
	if (move[0] == 'r')
		input_3_r(a_ptr, b_ptr, move);
	else
	{
		if (move[0] == 'a')
			*a_ptr = rotate(*a_ptr);
		else if (move[0] == 'b')
			*b_ptr = rotate(*b_ptr);
		else
			return (error_free_and_exit(*a_ptr, NULL));
		bytesread = read(0, move, 1);
		if (bytesread == -1 || bytesread == 0)
			return (error_free_and_exit(*a_ptr, NULL));
		move[bytesread] = '\0';
		if (move[0] != '\n')
			return (error_free_and_exit(*a_ptr, NULL));
		check(a_ptr, b_ptr);
	}
}

void	input_1(t_node **a_ptr, t_node **b_ptr, char *move)
{
	if (move[0] == 's')
		input_2_s(a_ptr, b_ptr, move);
	else if (move[0] == 'p')
		input_2_p(a_ptr, b_ptr, move);
	else if (move[0] == 'r')
		input_2_r(a_ptr, b_ptr, move);
	else
		error_free_and_exit(*a_ptr, *b_ptr);
}
