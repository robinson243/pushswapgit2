/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:51 by romukena          #+#    #+#             */
/*   Updated: 2025/08/06 02:37:04 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	check_limit(long n, int sign, int *error)
{
	n *= sign;
	if (n < INT_MIN || n > INT_MAX)
	{
		*error = 1;
		return (0);
	}
	return ((int)n);
}

int	push_swap_atoi(char *str, int *error)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!is_valid_digit(str[i]))
		return (*error = 1, 0);
	while (is_valid_digit(str[i]))
		n = n * 10 + (str[i++] - '0');
	if (str[i] != '\0')
		return (*error = 1, 0);
	return (check_limit(n, sign, error));
}

int	check_sorted(int *pile, int size, int order)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if ((order == 0 && pile[i - 1] > pile[i])
			|| (order != 0 && pile[i - 1] < pile[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_doubles(int *pile, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (pile[i] == pile[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
