/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_args1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhuisman <fhuisman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 14:55:29 by fhuisman      #+#    #+#                 */
/*   Updated: 2023/01/26 15:58:46 by fhuisman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int_max_min(int num, char next, int sign)
{
	if (num > 214748364)
		return (0);
	if (num == 214748364)
	{
		if (next == '9')
			return (0);
		if (sign == 1 && next == '8')
			return (0);
	}
	return (1);
}
