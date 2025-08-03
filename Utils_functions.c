/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:51 by romukena          #+#    #+#             */
/*   Updated: 2025/08/02 12:58:52 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_detected(int *pile)
{
	free(pile);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

int	push_swap_atoi(char *str, int *pile)
{
	unsigned int		i;
	int					sign;
	unsigned long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_detected(pile);
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if ((number > 2147483648 && sign == -1)
		|| (number > 2147483647 && sign == 1))
		error_detected(pile);
	return (number * sign);
}

int	push_swap_strlen(char **av)
{
	int	i;

	i = 0;
	while (*av)
	{
		av++;
		i++;
	}
	return (i);
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

void	check_doubles(int *pile, int size)
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
				error_detected(pile);
			j++;
		}
		i++;
		j = i + 1;
	}
}
