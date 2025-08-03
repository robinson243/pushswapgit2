/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:31:25 by romukena          #+#    #+#             */
/*   Updated: 2025/08/02 12:28:53 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_piles *pile, int bonus)
{
	int	tmp;

	if (pile->size_a <= 1)
		return ;
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;
	if (!bonus)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_piles *pile, int bonus)
{
	int	tmp;

	if (pile->size_b <= 1)
		return ;
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
	if (!bonus)
		ft_putstr_fd("sb\n", 1);
}

void	swap_s(t_piles *pile, int bonus)
{
	if (pile->size_a <= 1 && pile->size_b <= 1)
		return ;
	swap_a(pile, 1);
	swap_b(pile, 1);
	if (!bonus)
		ft_putstr_fd("ss\n", 1);
}
