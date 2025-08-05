/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:51 by romukena          #+#    #+#             */
/*   Updated: 2025/08/06 01:47:20 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_atoi(char *str, int *error)
{
	int				i;
	int				sign;
	long long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (*error = 1, 0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (*error = 1, 0);
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	number *= sign;
	if (number < INT_MIN || number > INT_MAX)
		*error = 1;
	return (number);
}

int	push_swap_strlen(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	check_sorted(int *pile, int size, int order)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if ((order == 0 && pile[i - 1] > pile[i]) || (order != 0 && pile[i
				- 1] < pile[i]))
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
