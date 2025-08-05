/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:40 by romukena          #+#    #+#             */
/*   Updated: 2025/08/06 01:46:59 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **av)
{
	t_piles		pile;
	int			size;
	int			i;
	int			error;

	i = -1;
	error = 0;
	size = push_swap_strlen(av);
	pile.a = malloc(size * sizeof(int));
	if (!pile.a)
		return (1);
	pile.size_a = size;
	pile.b = malloc(size * sizeof(int));
	if (!pile.b)
		return (free(pile.a), 1);
	pile.size_b = 0;
	while (++i < size)
	{
		pile.a[i] = push_swap_atoi(av[i], &error);
		if (error)
			return (free(pile.a), free(pile.b), 1);
	}
	if (check_doubles(pile.a, size))
		return (free(pile.a), free(pile.b), 1);
	sort(&pile, size);
	free(pile.a);
	free(pile.b);
	return (0);
}

int	main(int ac, char **av)
{
	char	**args;
	int		status;

	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			args = ft_split(*av, " ");
			if (!args)
				return (1);
			status = push_swap(args);
			free_tab(args);
			if (status)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
		}
		else
		{
			status = push_swap(av);
			if (status)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
		}
	}
	return (0);
}