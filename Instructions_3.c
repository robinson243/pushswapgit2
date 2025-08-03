/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:31:20 by romukena          #+#    #+#             */
/*   Updated: 2025/08/02 12:25:22 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_piles *pile, int bonus)
{
	int	tmp;
	int	i;

	if (pile->size_a <= 1)
		return ;
	i = pile->size_a - 1;
	tmp = pile->a[i];
	while (i > 0)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[i] = tmp;
	if (!bonus)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_piles *pile, int bonus)
{
	int	tmp;
	int	i;

	if (pile->size_b <= 1)
		return ;
	i = pile->size_b - 1;
	tmp = pile->b[i];
	while (i > 0)
	{
		pile->b[i] = pile->b[i - 1];
		i--;
	}
	pile->b[i] = tmp;
	if (!bonus)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_r(t_piles *pile, int bonus)
{
	if (pile->size_a <= 1 && pile->size_b <= 1)
		return ;
	reverse_rotate_a(pile, 1);
	reverse_rotate_b(pile, 1);
	if (!bonus)
		ft_putstr_fd("rrr\n", 1);
}
