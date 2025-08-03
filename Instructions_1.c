/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:26:56 by romukena          #+#    #+#             */
/*   Updated: 2025/08/02 12:19:46 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_piles *pile, int bonus)
{
	int	i;

	if (pile->size_a == 0)
		return ;
	i = pile->size_b;
	while (i > 0)
	{
		pile->b[i] = pile->b[i - 1];
		i--;
	}
	pile->b[0] = pile->a[0];
	pile->size_b++;
	i = 0;
	while (i < pile->size_a - 1)
	{
		pile->a[i] = pile->a[i + 1];
		i++;
	}
	pile->size_a--;
	if (!bonus)
		ft_putstr_fd("pb\n", 1);
}

void	push_a(t_piles *pile, int bonus)
{
	int	i;

	if (pile->size_b == 0)
		return ;
	i = pile->size_a;
	while (i > 0)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[0] = pile->b[0];
	pile->size_a++;
	i = 0;
	while (i < pile->size_b - 1)
	{
		pile->b[i] = pile->b[i + 1];
		i++;
	}
	pile->size_b--;
	if (!bonus)
		ft_putstr_fd("pa\n", 1);
}
