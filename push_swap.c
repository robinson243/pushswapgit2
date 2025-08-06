/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:40 by romukena          #+#    #+#             */
/*   Updated: 2025/08/06 02:37:24 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_strlen(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	cleanup_pile(t_piles *pile)
{
	free(pile->a);
	free(pile->b);
	return (1);
}

int	push_swap(char **av)
{
	t_piles	p;
	int		i;
	int		err;

	err = 0;
	p.size_a = push_swap_strlen(av);
	p.a = malloc(p.size_a * sizeof(int));
	if (!p.a)
		return (1);
	p.b = malloc(p.size_a * sizeof(int));
	if (!p.b)
		return (free(p.a), 1);
	p.size_b = 0;
	i = -1;
	while (++i < p.size_a)
	{
		p.a[i] = push_swap_atoi(av[i], &err);
		if (err)
			return (free(p.a), free(p.b), 1);
	}
	if (check_doubles(p.a, p.size_a))
		return (free(p.a), free(p.b), 1);
	sort(&p, p.size_a);
	return (free(p.a), free(p.b), 0);
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
				return (ft_putstr_fd("Error\n", 2), 1);
		}
		else
		{
			status = push_swap(av);
			if (status)
				return (ft_putstr_fd("Error\n", 2), 1);
		}
	}
	return (0);
}
