/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:40 by romukena          #+#    #+#             */
/*   Updated: 2025/08/02 18:39:25 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **av)
{
	t_piles		pile;
	int			size;
	int			i;

	i = -1;
	size = push_swap_strlen(av);
	pile.a = malloc(size * sizeof(int));
	if (!pile.a)
		return ;
	pile.size_a = size;
	pile.b = malloc(size * sizeof(int));
	if (!pile.b)
	{
		free(pile.a);
		return ;
	}
	pile.size_b = 0;
	while (++i < size)
		pile.a[i] = push_swap_atoi(av[i], pile.a);
	check_doubles(pile.a, size);
	sort(&pile, size);
	free(pile.a);
	free(pile.b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, " ");
		push_swap(av);
		return (0);
	}
	return (0);
}
